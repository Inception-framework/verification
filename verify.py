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
import getopt
import os_run

# read command line args
def print_usage_error():
    print("Wrong parameters, usage:")
    print("./generator.py -s <seed> -c <(continue in case of error) True/False>")
    sys.exit(0)

if len(sys.argv) <= 1:
    print_usage_error()
try:
    opts,args = getopt.getopt(sys.argv[1:],"h:s:c",["help","seed=","continue="])
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



# Retrieve number of generated tests
with open('main/Ntests',mode='r') as Ntests_file:
    Ntests = int(Ntests_file.readline())
Ntests_file.close

# Run klee and dump registers
print ("Running klee ...")
os_run.run_catch_error("./run_klee.sh "+str(Ntests),cont)

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
        print ("-----------------[TEST %d]---------------------"%(i))
        print ("[RESULT]\t The test failed ...")
        print ("")
        print ("[Source Code]\t Available into main/main%d.c :"%(i))
        print ("")
        with open('main/main%d.c'%(i),mode='r') as source_file:
            print (source_file.read())
        print ("")
        print ("\t[Test]")
        print ("\t"+str(reg_diff_klee))
        print ("\t[Oracle]")
        print ("\t"+str(reg_diff))
        print ("\t[Differences]")
        print ("\t"+str(diff))
        print ("-----------------------------------------------")
        print("")
        if(cont == False):
            print("aborting...")
            sys.exit(1)
