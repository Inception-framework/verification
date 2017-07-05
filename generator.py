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

# the real device, used as golden model
device = interactive.Interactive('../RTDebugger-driver/Debug/libinception.so',False)


# generate the test code
with open('main.c',mode='wt') as main_file:
    main_file.write("#include <stdlib.h>\n")
    main_file.write("__attribute__((naked))\n")
    main_file.write("void main(void){\n")
   
    # input operands
    reg="r0"
    val="#5"
    main_file.write('  __asm volatile("mov %s,%s"); \n'%(reg,val))
    
    # instruction under test
    instr="mov"
    operands="r3,r0"
    main_file.write('  __asm volatile("%s %s");\n'%(instr,operands))
    
    main_file.write("  while(1);\n")
    main_file.write("}\n")
main_file.close

# compile the code for inception
# TODO

# compile the code for the real device
os.system('make')

# execute on the real device
# and dump the differencies in the values of the registers before and after
# execution
device.halt()
device.load_binary_in_sram('./main.bin',0x10000000)
device.write_reg(15,0x10000000)
device.clear_all_regs()
regs_initial = device.dump_all_regs()
device.resume()
time.sleep(0.01)
device.halt()
regs_final = device.dump_all_regs()
with open('reg_diff.log',mode='wt') as reg_diff_file:
    reg_diff_file.write("test\n")
    for (initial_name,initial_val),(final_name,final_val) in zip(regs_initial.items(),regs_final.items()):
        # print("%d %d\n"%(initial_val,final_val))
        if(final_val != initial_val):
            reg_diff_file.write("%s %d\n"%(final_name,final_val))
    reg_diff_file.close
