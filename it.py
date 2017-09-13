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

conditions = [["eq","ne"],
              ["ne","eq"],
              ["cs","cc"],
              ["cc","cs"],
              ["mi","pl"],
              ["pl","mi"],
              ["vs","vc"],
              ["vc","vs"],
              ["hi","ls"],
              ["ls","hi"],
              ["ge","lt"],
              ["lt","ge"],
              ["gt","le"],
              ["le","gt"]]

init = ["R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10"]

instructions = [["movs","r2,#2"],
                ["mov","r3,#3"],
                ["movs","r4,#4"],
                ["mov","r5,#5"],
                ["adds","r6,r0,r1"],
                ["add","r7,r0,r1"],
                ["adds","r8,r0,r1,lsl #1"],
                ["subs","r9,r0,r1,lsr #1"]]

last = [["b","target"]]

target = ["mov r10,#10"]

its = list(itertools.product(["itblock: it"],
                            ["","t","e"],
                            ["","t","e"],
                            ["","t","e"]))

def generate_it_tests(seed):
    random.seed(seed)
    tests = []
    for it in its:
        it_block = []
        it_block.append("cmp r0,r1")
        # randomly put it as first instruction of a block
        if(random.choice([0,1]) == 1):
            it_block.append("b itblock")
        cond,cond_n = random.choice(conditions)
        
        it_inst = ''.join(it)
        it_inst += " "
        it_inst += cond
        #print(it_inst)
        it_block.append(it_inst)

        for i,c in enumerate(it):
            if i == len(it)-1:
                inst = random.choice(instructions+last)
            else:
                inst = random.choice(instructions)
            if c == "t" or i==0:
              true_inst = ''.join([inst[0],cond," ",inst[1]])
              it_block.append(true_inst)
              #print(true_inst)
            elif c == "e":
              false_inst = ''.join([inst[0],cond_n," ",inst[1]])
              it_block.append(false_inst)
              #print(false_inst)

        it_block.append("b continue");
        it_block.append("target:  mov r10,#10");
        it_block.append("continue:  mov r10,r10");

        tests.append(it_block)
    
    init_regs = []
    for reg in init:
      init_regs.append(list(device.regs.keys()).index(reg))
    return init_regs,tests

if __name__ == "__main__":
    init_regs,tests = generate_it_tests(0)
    for init_reg in init_regs:
      print(init_reg)
    print("")
    for test in tests:
      for inst in test:
         print(inst)
      print("") 


