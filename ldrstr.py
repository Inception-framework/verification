#!/usr/bin/python3.5
# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

import os
import os_run
import random
import itertools
import sys

sys.path.append('../RTDebugger-driver/src/')
import interactive
from collections import OrderedDict
device = interactive.Interactive('../RTDebugger-driver/Debug/libinception.so',False)
#
#folder = "./ldrstr_test_cases"
## create output folder
#os_run.run_catch_error('mkdir -p %s'%folder,False)
#
## save version
#vfile = os.path.abspath(folder+"/version_generator.log")
#os_run.run_catch_error("./versioning.sh %s"%(vfile),False)
#
#
#ld = ["LDR"]
#st = ["STR"]
#ld_size = ["","B","SB","H","SH"]
## since we don't have T we can put D with the others
#st_size = ["","B","H","D"]
##t = ["","T"]
def generate_ldrstr(seed):
    t = [""]
    
    random.seed(seed)
    Rd = random.choice(list(device.regs.keys()))
    Rn = random.choice(list(device.regs.keys()))
    Rm = random.choice(list(device.regs.keys()))
    #offset = random.randint(-4095,4095)
    offset = random.choice(range(-100,100,4)) #always ok
    opsh = "LSL #2" #always ok
    label = random.randint(-4092,4092)
    reglist_allowed = list(device.regs.keys())
    reglist_allowed.remove("PC")
    reglist_allowed.remove("SP")
    reglist_allowed.remove("CPSR")
    reglist = []
    for i in range(0,random.randint(2,16)):
        reglist.append(random.choice(reglist_allowed))
    reglist="{"+', '.join(reglist)+"}"
    Rd1 = random.choice(reglist_allowed)
    Rd2 = random.choice(reglist_allowed)
    
    ldrstr_instructions = []
    
    # considering that we do not have {T}...
    
    ## immidiate offset
    #  ld
    #combs = list(itertools.product(["LDR"],
    #                               ["","B","SB","H","SH"],
    #                               t,
    #                               [" Rd, [Rn"],
    #                               [""," ,#<offset>"],
    #                               ["]"],
    #                               ["","!"]))
    #for comb in combs:
    #    comb = ''.join(comb)
    #    ldrstr_instructions.append(comb)
    
    ## st
    #  immediate offset
    combs = list(itertools.product(["STR"],
                                   ["","B","H"],
                                   t,
                                   [" %s, [%s"%(Rd,Rn)],
                                   [""," ,#%s"%(offset)],
                                   ["]"],
                                   ["","!"]))
    #  postindexed immediate
    combs += list(itertools.product(["STR"],
                                   ["","B","H"],
                                   t,
                                   [" %s, [%s]"%(Rd,Rn)],
                                   [" ,#%s"%(offset)]))
    #  register offset
    combs += list(itertools.product(["STR"],
                                   ["","B","H"],
                                   [" %s, [%s"%(Rd,Rn)],
                                   #[", +",", -"],
                                   [", +"],
                                   ["%s"%(Rm)],
                                   ["",", %s"%(opsh)],
                                   ["]"]))
                                   #["","!"]))
    #  postindexed register
    #combs += list(itertools.product(["STR"],
    #                               ["","B","H"],
    #                               t,
    #                               [" %s, [%s]"%(Rd,Rn)],
    #                               [", +",", -"],
    #                               ["%s"%(Rm)],
    #                               ["",", %s"%(opsh)]))
    # PC-relative
    #combs += list(itertools.product(["STR"],
    #                               ["","B","H"],
    #                               [" %s, %s"%(Rd,label)]))
     
    #  immediate offset
    combs += list(itertools.product(["STR"],
                                   ["D"],
                                   [" %s, %s, [%s"%(Rd1,Rd2,Rn)],
                                   [""," ,#%s"%(offset)],
                                   ["]"],
                                   ["","!"]))
    #  postindexed immediate
    combs += list(itertools.product(["STR"],
                                   ["D"],
                                   [" %s, %s, [%s]"%(Rd1,Rd2,Rn)],
                                   [" ,#%s"%(offset)]))
    #  register offset
    #combs += list(itertools.product(["STR"],
    #                               ["D"],
    #                               [" %s, %s, [%s"%(Rd1,Rd2,Rn)],
    #                               [", +",", -"],
    #                               ["%s"%(Rm)],
    #                               ["",", %s"%(opsh)],
    #                               ["]"],
    #                               ["","!"]))
    #  postindexed register
    #combs += list(itertools.product(["STR"],
    #                               ["D"],
    #                               [" %s, %s, [%s]"%(Rd1,Rd2,Rn)],
    #                               [", +",", -"],
    #                               ["%s"%(Rm)],
    #                               ["",", %s"%(opsh)]))
    # PC-relative
    #combs += list(itertools.product(["STR"],
    #                               ["D"],
    #                               [" %s, %s, %s"%(Rd1,Rd2,label)]))
    
    # push reglist
    combs += list(itertools.product(["STM"],
                                   #["IA","IB","DA","DB"],
                                   ["IA","DB"],
                                   [" %s"%(Rn)],
                                   ["","!"],
                                   [", %s"%(reglist)]))
    
    
    # lists to strings
    for comb in combs:
        comb = ''.join(comb)
        ldrstr_instructions.append(comb)
    
    
   # ## generate code
   # #print("Generating ldr str test cases")
   # for ldrstr_instr in enumerate(ldrstr_instructions):
   #     print("#include <stdlib>")
   #     print("__attribute__((naked))")
   #     print("void foo(){")
   #     print('  __asm volatile("%s")'%(ldrstr_instr))
   #     print('  __asm_volatile("bx lr")')
   #     print("}")
   #     print("void main(void){")
   #     print("  foo()")
   #     print("}")
   #     break
   # print("")
    
  
    return ldrstr_instructions
    
## save number of tests
#with open('%s/Ntests'%(folder),mode='wt') as Ntests_file:
#    Ntests_file.write("%d\n"%(id))
#Ntests_file.close


