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

conditions = ["eq","ne","cs","hs",
              "cc","lo","mi","pl",
              "vs","vc","hi","ls",
              "ge","lt","gt","le"]

conditions_loop_p = ["eq","ne","cs","hs",
                     "cc","lo","mi","pl",
                     "vs",     "hi","ls",
                     "ge","lt","gt","le"]

conditions_loop_n = ["eq","ne",     
                     "cc","lo","mi","pl",
                     "vs",     "hi","ls",
                     "ge","lt","gt","le"]


def generate_cf_tests(seed):
    random.seed(seed)
    reglist_allowed = list(device.regs.keys())
    reglist_allowed.remove("CPSR")
    reglist_allowed.remove("PC")
    reglist_allowed.remove("SP")
    reglist_allowed.remove("LR")
    Rindex = random.choice(reglist_allowed)
    cond_loop_p = random.choice(conditions_loop_p)
    cond_loop_n = random.choice(conditions_loop_n)

    programs = []
    changed_regs = []
    
    ## loops
    combs = list(itertools.product(
                     ["mov %s, #0"%(Rindex)],
                     ["loop:"],
                     ["add %s,%s,#1"%(Rindex,Rindex)],
                     ["cmp %s,#0x100"%(Rindex)],
                     ["b%s loop"%(cond_loop_p)]
                ))
    programs += combs
    for i in range(0,len(combs)):
        changed_regs.append([list(device.regs.keys()).index(Rindex),
                             list(device.regs.keys()).index("CPSR") 
                           ])
    combs = list(itertools.product(
                     ["mov %s, #100"%(Rindex)],
                     ["loop:"],
                     ["add %s,%s,#-1"%(Rindex,Rindex)],
                     ["cmp %s,#0"%(Rindex)],
                     ["b%s loop"%(cond_loop_n)]
                ))
    programs += combs
    for i in range(0,len(combs)):
        changed_regs.append([list(device.regs.keys()).index(Rindex),
                             list(device.regs.keys()).index("CPSR") 
                           ])


    return changed_regs,programs
    
#def init(seed):
#    random.seed(seed)
#
#def generate_bb(instructions,id):
#    l = random.randint(0,5):
#    for i in range(0,l):
#        instructions.append(["mo"])
#        
#        
#def generate_branch_instruction():
#    combs = list(itertools.product(["b"],
#                                   ["","B","H"],
#                                   t,
#                                   [" %s, [%s"%(Rd,Rn)],
#                                   [""," ,#%s"%(offset)],
#                                   ["]"],
#                                   ["",wb]))
# 
#def generate_ldrstr(seed):
#    t = [""]
#    
#    random.seed(seed)
#    reglist_allowed = list(device.regs.keys())
#    reglist_allowed.remove("CPSR")
#    reglist_allowed.remove("PC")
#    reglist_allowed.remove("SP")
#    Rd = random.choice(reglist_allowed)
#    reglist_allowed = list(device.regs.keys())
#    reglist_allowed.remove("CPSR")
#    reglist_allowed.remove("PC")
#    Rn = random.choice(reglist_allowed)
#    while(Rd == Rn):
#        Rn = random.choice(reglist_allowed)
#    reglist_allowed = list(device.regs.keys())
#    reglist_allowed.remove("CPSR")
#    reglist_allowed.remove("PC")
#    reglist_allowed.remove("SP")
#    Rm = random.choice(reglist_allowed)
#    #offset = random.randint(-4095,4095)
#    offset = random.choice(range(-100,100,4)) #always ok
#    opsh = "LSL #2" #always ok
#    label = random.randint(-4092,4092)
#    reglist_allowed = list(device.regs.keys())
#    reglist_allowed.remove("PC")
#    reglist_allowed.remove("SP")
#    reglist_allowed.remove("CPSR")
#    if Rn != "PC" and Rn != "SP" and Rn != "CPSR":
#        reglist_allowed.remove(Rn)
#    reglist = []
#    for i in range(0,random.randint(2,16)):
#        reglist.append(random.choice(reglist_allowed))
#    reglist="{"+', '.join(reglist)+"}"
#    Rd1 = random.choice(reglist_allowed)
#    Rd2 = random.choice(reglist_allowed)
# 
#    init_regs = ', '.join([Rd,Rd1,Rd2,Rm])+", "+reglist[1:len(reglist)-1]
#    init_regs = init_regs.split(', ')
#    if "PC" in init_regs:
#        init_regs.remove("PC")
#    if "SP" in init_regs:
#        init_regs.remove("SP")
#    if "CPSR" in init_regs:
#        init_regs.remove("CPSR")
#    init_regs = [list(device.regs.keys()).index(reg_name) for reg_name in init_regs]
#    init_regs = list(set(init_regs))
#    base_reg  = list(device.regs.keys()).index(Rn)
#    ldrstr_instructions = []
#    
#    #if(Rn == "PC"):
#    #  wb = ""
#    #else:
#    wb = "!"
# 
#    # considering that we do not have {T}...
#    
#    ## immidiate offset
#    #  ld
#    #combs = list(itertools.product(["LDR"],
#    #                               ["","B","SB","H","SH"],
#    #                               t,
#    #                               [" Rd, [Rn"],
#    #                               [""," ,#<offset>"],
#    #                               ["]"],
#    #                               ["","!"]))
#    #for comb in combs:
#    #    comb = ''.join(comb)
#    #    ldrstr_instructions.append(comb)
#    
#    ## st
#    #  immediate offset
#    combs = list(itertools.product(["R"],
#                                   ["","B","H"],
#                                   t,
#                                   [" %s, [%s"%(Rd,Rn)],
#                                   [""," ,#%s"%(offset)],
#                                   ["]"],
#                                   ["",wb]))
#    #  postindexed immediate
#    combs += list(itertools.product(["R"],
#                                   ["","B","H"],
#                                   t,
#                                   [" %s, [%s]"%(Rd,Rn)],
#                                   [" ,#%s"%(offset)]))
#    #  register offset
#    combs += list(itertools.product(["R"],
#                                   ["","B","H"],
#                                   [" %s, [%s"%(Rd,Rn)],
#                                   #[", +",", -"],
#                                   [", +"],
#                                   ["%s"%(Rm)],
#                                   ["",", %s"%(opsh)],
#                                   ["]"]))
#                                   #["","!"]))
#    #  postindexed register
#    #combs += list(itertools.product(["STR"],
#    #                               ["","B","H"],
#    #                               t,
#    #                               [" %s, [%s]"%(Rd,Rn)],
#    #                               [", +",", -"],
#    #                               ["%s"%(Rm)],
#    #                               ["",", %s"%(opsh)]))
#    # PC-relative
#    #combs += list(itertools.product(["STR"],
#    #                               ["","B","H"],
#    #                               [" %s, %s"%(Rd,label)]))
#     
#    #  immediate offset
#    combs += list(itertools.product(["R"],
#                                   ["D"],
#                                   [" %s, %s, [%s"%(Rd1,Rd2,Rn)],
#                                   [""," ,#%s"%(offset)],
#                                   ["]"],
#                                   ["",wb]))
#    #  postindexed immediate
#    combs += list(itertools.product(["R"],
#                                   ["D"],
#                                   [" %s, %s, [%s]"%(Rd1,Rd2,Rn)],
#                                   [" ,#%s"%(offset)]))
#    #  register offset
#    #combs += list(itertools.product(["STR"],
#    #                               ["D"],
#    #                               [" %s, %s, [%s"%(Rd1,Rd2,Rn)],
#    #                               [", +",", -"],
#    #                               ["%s"%(Rm)],
#    #                               ["",", %s"%(opsh)],
#    #                               ["]"],
#    #                               ["","!"]))
#    #  postindexed register
#    #combs += list(itertools.product(["STR"],
#    #                               ["D"],
#    #                               [" %s, %s, [%s]"%(Rd1,Rd2,Rn)],
#    #                               [", +",", -"],
#    #                               ["%s"%(Rm)],
#    #                               ["",", %s"%(opsh)]))
#    # PC-relative
#    #combs += list(itertools.product(["STR"],
#    #                               ["D"],
#    #                               [" %s, %s, %s"%(Rd1,Rd2,label)]))
#    
#    # push reglist
#    combs += list(itertools.product(["M"],
#                                   #["IA","IB","DA","DB"],
#                                   ["IA","DB"],
#                                   [" %s"%(Rn)],
#                                   ["",wb],
#                                   [", %s"%(reglist)]))
#    
#    
#    # lists to strings
#    for comb in combs:
#        comb = ''.join(comb)
#        ldrstr_instructions.append(comb)
#    
#    
#   # ## generate code
#   # #print("Generating ldr str test cases")
#   # for ldrstr_instr in enumerate(ldrstr_instructions):
#   #     print("#include <stdlib>")
#   #     print("__attribute__((naked))")
#   #     print("void foo(){")
#   #     print('  __asm volatile("%s")'%(ldrstr_instr))
#   #     print('  __asm_volatile("bx lr")')
#   #     print("}")
#   #     print("void main(void){")
#   #     print("  foo()")
#   #     print("}")
#   #     break
#   # print("")
#    
#    
#    return init_regs,base_reg,ldrstr_instructions
#    
### save number of tests
##with open('%s/Ntests'%(folder),mode='wt') as Ntests_file:
##    Ntests_file.write("%d\n"%(id))
##Ntests_file.close


