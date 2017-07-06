#!/usr/bin/python3.5
# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

import os
import sys

os.system("./run_klee.sh")

with open('main/Ntests',mode='r') as Ntests_file:
    Ntests = int(Ntests_file.readline())
Ntests_file.close


for i in range(0,Ntests):
    with open('main/reg_diff%d.log'%(i),mode='r') as reg_diff_file:
        lines = reg_diff_file.read().splitlines()
    reg_diff_file.close
    reg_diff = set([(reg,val) for reg,val in zip(lines[::2],lines[1::2])])
    #print (reg_diff)
    
    with open('main/reg_diff_klee%d.log'%(i),mode='r') as reg_diff_klee_file:
        lines_klee = reg_diff_klee_file.read().splitlines()
    reg_diff_klee_file.close
    reg_diff_klee = set([(reg,val) for reg,val in zip(lines_klee[::2],lines_klee[1::2])])
    #print (reg_diff_klee)

    diff = reg_diff_klee - reg_diff
    if(diff == set()):
        print ("TEST %d PASSED"%(i))
    else:
        print ("TEST %d FAILED"%(i))
        print("reg_diff_klee",reg_diff_klee)
        print("reg_diff     ",reg_diff)
        print ("klee - device",diff)
    print("")


       



