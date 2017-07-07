#!/usr/bin/python3.5
# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

# Import the interactive module, responsible for the communication with the real
# device. Set the path to the libinception cpp library that handles jtag. Use it
# in non command line mode
import sys
import time
import os
sys.path.append('../RTDebugger-driver/src/')
import interactive
from collections import OrderedDict
import random
import os_run
import getopt

# read command line args
def print_usage_error():
    print("Wrong parameters, usage:")
    print("./generator.py -s <seed> -c <(continue in case of error) True/False>")
    sys.exit(0)

if len(sys.argv) <= 1:
    print_usage_error()
try:
    opts,args = getopt.getopt(sys.argv[1:],"hs:c:",["help","seed=","continue="])
except getopt.GetoptError:
    print_usage_error()
for opt,arg in opts:
    if opt in ("-h","--help"):
        print("./generator.py")
        print("options:")
        print("    s,seed:     integer seed for pseudo random test generation")
        print("    c,continue: True->skip errors, False->stop on error")
        print("")
    elif opt in ("-s","--seed"):
        seed = int(arg)
    elif opt in ("-c","--continue"):
        if arg == "True":
            cont = True
        elif arg == "False":
            cont = False
        else: 
            print("Error, continue must be True or False")
            sys.exit(1)

random.seed(seed)

# the real device, used as golden model
device = interactive.Interactive('../RTDebugger-driver/Debug/libinception.so',False)

# possible operations
# TODO continue
operations = OrderedDict()
operations.update({"Add" : 
                     [
                       (("ADD","ADDS"),
                        ("Rd","Rn","<Operand2>"),
                        ("N","Z","C","V"),
                        ("Rd:=Rn+Operand2")
                       ),
                      # (("ADC","ADCS"),
                      #  ("Rd","Rn","<Operand2>"),
                      #  ("N","Z","C","V"),
                      #  ("Rd:=Rn+Operand2+Carry")
                      # ),
                        (("ADD",),
                        ("Rd","Rn","#<imm12>"),
                        (),
                        ("Rd:=Rn+imm12")
                       )
                     ]
                   })
#operations.update({"Subtract" : 
#                     [
#                       (("SUB","SUBS"),
#                        ("Rd","Rn","<Operand2>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-Operand2")
#                       ),
#                       (("SBC","SBCS"),
#                        ("Rd","Rn","<Operand2>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-Operand2-NOT(Carry)")
#                       ),
#                        (("SUB",),
#                        ("Rd","Rn","#<imm12>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-imm12")
#                       )
#                     ]
#                   })
#
# possible operand2
# TODO continue
operand2 = ( "#<imm8>", "Rn" )

## expanding Operand2
operations_expanded = OrderedDict()
for operation,suboperations in operations.items():
  #print (operation)
  suboperations_expanded = []
  for instructions,operands,updates,actions in suboperations:
      #print (instructions,operands,updates,actions)
      expanded = False
      for idx,operand in enumerate(operands):
          if operand == "<Operand2>":
              expanded = True
              for op in operand2:
                  #operands_expanded = operands + (op,)
                  tmp = list(operands)
                  tmp[idx]=op
                  operands_expanded = tuple(tmp)
                  suboperation_expanded = (instructions,operands_expanded,updates,actions)
                  suboperations_expanded.append(suboperation_expanded)
      if expanded == False:
          suboperations_expanded.append((instructions,operands,updates,actions))
  operations_expanded.update({operation : suboperations_expanded})

def generate_test_code(init_strings,inst_string,return_string,id):
    # generate the test code
    os_run.run_catch_error('mkdir -p main',cont)
    with open('main/main%d.c'%(id),mode='wt') as main_file:
        main_file.write("#include <stdlib.h>\n")
        main_file.write("__attribute__((naked))\n")
        main_file.write("void main(void){\n")
       
        # input operands
        for init_string in init_strings:
            main_file.write('  __asm volatile("'+init_string+'"); \n')
        
        # instruction under test
        main_file.write('  __asm volatile("'+inst_string+'");\n')
        
        # just to make fracture happy about the return value in r0
        main_file.write('  __asm volatile("'+return_string+'");\n')
        
        main_file.write("  #ifndef KLEE\n")
        main_file.write("  while(1);\n")
        main_file.write("  #else\n")
        main_file.write('  __asm volatile("bx lr");\n')
        main_file.write("  #endif\n")
        main_file.write("}\n")
    main_file.close

def execute_on_device_and_dump(id):
    # execute on the real device
    # and dump the differencies in the values of the registers before and after
    # execution
    device.halt()
    device.load_binary_in_sram('main/main%d.bin'%(id),0x10000000)
    device.write_reg(15,0x10000000)
    device.clear_all_regs()
    regs_initial = device.dump_all_regs()
    device.resume()
    time.sleep(0.01)
    device.halt()
    regs_final = device.dump_all_regs()
    with open('main/reg_diff%d.log'%(id),mode='wt') as reg_diff_file:
        #reg_diff_file.write("test\n")
        for (initial_name,initial_val),(final_name,final_val) in zip(regs_initial.items(),regs_final.items()):
            # print("%d %d\n"%(initial_val,final_val))
            if(final_val != initial_val):
                if(initial_name != "PC"):
                    reg_diff_file.write("%s\n%d\n"%(final_name,final_val))
            elif(initial_name == "CPSR"):
                reg_diff_file.write("%s\n%d\n"%(final_name,0))
        reg_diff_file.close


# test generation
# TODO continue                    
id = 0
for operation,suboperations in operations_expanded.items():
  #print (operation)
  for instructions,operands,updates,actions in suboperations:
      #print (instructions)
      for instruction in instructions:
          init_strings = []
          inst_string = instruction
          return_string = ""
          for operand in operands:
              #print(operand)
              if operand == "Rd":
                 Rd = random.randint(0,12)
                 inst_string += " R%d"%(Rd)
                 return_string += "mov r0,r%d"%(Rd)
              elif operand == "Rn":
                 Rn = random.randint(0,12)
                 Rn_val = random.randint(0,2**8-1)
                 init_strings.append("mov R%d,#0x%02x"%(Rn,Rn_val))
                 inst_string += ", R%d"%(Rn)
              elif operand == "#<imm8>":
                 inst_string += ", #0x%02x"%(random.randint(0,2**8-1))
              elif operand == "#<imm12>":
                 inst_string += ", #0x%03x"%(random.randint(0,2**12-1))
          
          # print test case to screen                  
          print ("")        
          for init_str in init_strings:
              print(init_str)     
          print (inst_string)
          
          # generate c code
          generate_test_code(init_strings,inst_string,return_string,id)
          
          # compile the code for the real device
          os_run.run_catch_error('make ID=%d'%(id),cont)

          # execute on the real hw
          execute_on_device_and_dump(id)

          # compile the code for inception
          # TODO better
          os_run.run_catch_error('echo "#define KLEE\n$(cat main/main%d.c)" > main/main%d.c'%(id,id),cont)
          os_run.run_catch_error('./build.sh main%d inception'%(id),cont)
          
          # print test case to screen                  
          print ("")        
          for init_str in init_strings:
              print(init_str)     
          print (inst_string)
 
          os_run.run_catch_error('cat main/reg_diff%d.log'%(id),cont)
          
          id += 1
          #input("Press any key to continue")

with open('main/Ntests',mode='wt') as Ntests_file:
    Ntests_file.write("%d\n"%(id))
Ntests_file.close

sys.exit(0)


