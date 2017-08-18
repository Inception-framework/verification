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
    reglist_allowed.remove(Rindex)
    Rindex2 = random.choice(reglist_allowed)
    reglist_allowed.remove(Rindex2)
    Rbb1 = random.choice(reglist_allowed)
    reglist_allowed.remove(Rbb1)
    Rbb2 = random.choice(reglist_allowed)
    reglist_allowed.remove(Rbb2)
    Rbb3 = random.choice(reglist_allowed)
    cond_loop_p = random.choice(conditions_loop_p)
    cond_loop_n = random.choice(conditions_loop_n)

    programs = []
    changed_regs = []
    
   # ## loops
   # combs = list(itertools.product(
   #                  ["mov %s, #0"%(Rindex)],
   #                  ["loop:"],
   #                  ["add %s,%s,#1"%(Rindex,Rindex)],
   #                  ["cmp %s,#0x100"%(Rindex)],
   #                  ["b%s loop"%(cond_loop_p)]
   #             ))
   # programs += combs
   # for i in range(0,len(combs)):
   #     changed_regs.append([list(device.regs.keys()).index(Rindex),
   #                          list(device.regs.keys()).index("CPSR") 
   #                        ])
   # combs = list(itertools.product(
   #                  ["mov %s, #100"%(Rindex)],
   #                  ["loop:"],
   #                  ["add %s,%s,#-1"%(Rindex,Rindex)],
   #                  ["cmp %s,#0"%(Rindex)],
   #                  ["b%s loop"%(cond_loop_n)]
   #             ))
   # programs += combs
   # for i in range(0,len(combs)):
   #     changed_regs.append([list(device.regs.keys()).index(Rindex),
   #                          list(device.regs.keys()).index("CPSR") 
   #                        ])

   # ## nested loops
   # combs = list(itertools.product(
   #                  ["mov %s, #0"%(Rindex2)],
   #                  ["outer_loop:"],
   #                  #
   #                  ["mov %s, #100"%(Rindex)],
   #                  ["loop:"],
   #                  ["add %s,%s,#-1"%(Rindex,Rindex)],
   #                  ["cmp %s,#0"%(Rindex)],
   #                  ["b%s loop"%(cond_loop_n)],
   #                  #
   #                  ["add %s,%s,#1"%(Rindex2,Rindex2)],
   #                  ["cmp %s,#0x100"%(Rindex2)],
   #                  ["b%s outer_loop"%(cond_loop_p)]
   #             ))
   # programs += combs
   # for i in range(0,len(combs)):
   #     changed_regs.append([list(device.regs.keys()).index(Rindex),
   #                          list(device.regs.keys()).index("CPSR") 
   #                        ])

   # ## cfg
   # n = random.randint(0,4)
   # programs.append(["mov r1,#%d"%(n),
   #                  "cmp r1,#0",
   #                  "bne compute",
   #                  "mov r0,#0",
   #                  "b return",
   #                  "compute:",
   #                  "mov r2,#%d"%(n),
   #                  "mov r3,#%d"%(n+1),
   #                  "add r0,r2,r3",
   #                  "return:"])
   # changed_regs.append([list(device.regs.keys()).index("R0"),
   #                      list(device.regs.keys()).index("R1"), 
   #                      list(device.regs.keys()).index("R2"),
   #                      list(device.regs.keys()).index("R3"), 
   #                      list(device.regs.keys()).index("CPSR") 
   #                    ])

   # cmp1 = Rindex
   # cmp2 = Rindex2
   # cmp1_val = random.randint(-5,5)
   # cmp2_val = random.randint(-5,5)
   # cond = random.choice(conditions)
   # combs = list(itertools.product(
   #                  ["start:"],
   #                  ["mov %s,#%d"%(cmp1,cmp1_val)],
   #                  ["mov %s,#%d"%(cmp2,cmp2_val)],
   #                  ["cmp %s,%s"%(cmp1,cmp2)],
   #                  ["b%s %s"%(cond,random.choice(["bb1","bb2","bb3"]))],
   #                  ["bb1:"],
   #                  ["mov %s,#1"%(Rbb1)],
   #                  ["b end"],
   #                  ["bb2:"],
   #                  ["mov %s,#2"%(Rbb2)],
   #                  ["bb3:"],
   #                  ["mov %s,#3"%(Rbb3)],
   #                  ["cmp %s,%s"%(cmp1,cmp2)],
   #                  ["b%s %s"%(cond,random.choice(["bb1","end"]))],
   #                  ["end:"],
   #             ))
   # programs += combs
   # for i in range(0,len(combs)):
   #     changed_regs.append([list(device.regs.keys()).index(cmp1),
   #                          list(device.regs.keys()).index(cmp2), 
   #                          list(device.regs.keys()).index(Rbb1),
   #                          list(device.regs.keys()).index(Rbb2), 
   #                          list(device.regs.keys()).index(Rbb3), 
   #                          list(device.regs.keys()).index("CPSR") 
   #                        ])

    ## algos
    reglist_allowed = list(device.regs.keys())
    reglist_allowed.remove("CPSR")
    reglist_allowed.remove("PC")
    reglist_allowed.remove("SP")
    reglist_allowed.remove("LR")
    Rindex = random.choice(reglist_allowed)
    reglist_allowed.remove(Rindex)
    r0 = random.choice(reglist_allowed)
    reglist_allowed.remove(r0)
    r2 = random.choice(reglist_allowed)
    reglist_allowed.remove(r2)
    r3 = random.choice(reglist_allowed)
    reglist_allowed.remove(r3)
    r7 = random.choice(reglist_allowed)
    reglist_allowed.remove(r7)
    combs = list(itertools.product(
                     ["mov	%s,#%d"%(r0,random.randint(1,10))],
                     ["push	{%s}"%(r7)],
                     ["sub	sp, #28"],
                     ["add	%s, sp, #0"%(r7)],
                     ["str	%s, [%s, #4]"%(r0,r7)],
                     ["movs	%s, #0"%(r3)],
                     ["str	%s, [%s, #20]"%(r3,r7)],
                     ["movs	%s, #1"%(r3)],
                     ["str	%s, [%s, #16]"%(r3,r7)],
                     ["movs	%s, #0"%(r3)],
                     ["str	%s, [%s, #8]"%(r3,r7)],
                     ["b.n	fibonaccix38"],
                     ["fibonaccix16:"], 
                     ["ldr	%s, [%s, #8]"%(r3,r7)],
                     ["cmp	%s, #1"%(r3)],
                     ["bgt.n	fibonaccix22"],
                     ["ldr	%s, [%s, #8]"%(r3,r7)],
                     ["str	%s, [%s, #12]"%(r3,r7)],
                     ["b.n	fibonaccix32"],
                     ["fibonaccix22:"], 
                     ["ldr	%s, [%s, #20]"%(r2,r7)],
                     ["ldr	%s, [%s, #16]"%(r3,r7)],
                     ["add	%s, %s"%(r3,r2)],
                     ["str	%s, [%s, #12]"%(r3,r7)],
                     ["ldr	%s, [%s, #16]"%(r3,r7)],
                     ["str	%s, [%s, #20]"%(r3,r7)],
                     ["ldr	%s, [%s, #12]"%(r3,r7)],
                     ["str	%s, [%s, #16]"%(r3,r7)],
                     ["fibonaccix32:"], 
                     ["ldr	%s, [%s, #8]"%(r3,r7)],
                     ["adds	%s, #1"%(r3)],
                     ["str	%s, [%s, #8]"%(r3,r7)],
                     ["fibonaccix38:"],
                     ["ldr	%s, [%s, #8]"%(r2,r7)],
                     ["ldr	%s, [%s, #4]"%(r3,r7)],
                     ["cmp	%s, %s"%(r2,r3)],
                     ["blt.n	fibonaccix16"],
                     ["ldr	%s, [%s, #12]"%(r3,r7)],
                     ["mov	%s, %s"%(r0,r3)],
                     ["adds	%s, #28"%(r7)],
                     ["mov	sp, %s"%(r7)],
                     ["ldr.w	%s, [sp], #4"%(r7)],
                ))
    programs += combs
    for i in range(0,len(combs)):
        changed_regs.append([list(device.regs.keys()).index(r0),
                             list(device.regs.keys()).index(r2), 
                             list(device.regs.keys()).index(r3),
                             list(device.regs.keys()).index(r7), 
                             list(device.regs.keys()).index("SP"), 
                             list(device.regs.keys()).index("CPSR") 
                           ])



  

    return changed_regs,programs
    

