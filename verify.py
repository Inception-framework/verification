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
    print("./generator.py \
           -s <seed> \
           -c <(continue in case of error) True/False> \
           [-n (no device)] \
           [-N <number of tests>")
    sys.exit(0)

no_device = False
folder="test"

if len(sys.argv) <= 1:
    print_usage_error()
try:
    opts,args = getopt.getopt(sys.argv[1:],"hs:c:nf:",["help",
                                                       "seed=",
                                                       "continue=",
                                                       "no-device",
                                                       "folder="])
except getopt.GetoptError:
    print_usage_error()
for opt,arg in opts:
    if opt in ("-h","--help"):
        print("./generator.py")
        print("options:")
        print("    s,seed=:            integer seed for pseudo random test generation")
        print("    c,continue=:        True->skip errors, False->stop on error")
        print("    n,no-device:        skip execution on device")
        print("    o,folder=:          folder where tests are stored")
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
    elif opt in ("-n","--no-device"):
            no_device = True
    elif opt in ("-f","--folder="):
            folder = arg 



# Retrieve number of generated tests
with open('%s/Ntests'%(folder),mode='r') as Ntests_file:
    Ntests = int(Ntests_file.readline())
Ntests_file.close

# Run klee and dump registers
print ("Running klee ...")
os_run.run_catch_error("./run_klee.sh "+str(Ntests)+" "+str(folder),cont)

for i in range(0,Ntests):

    with open('%s/reg_diff%d.log'%(folder,i),mode='r') as reg_diff_file:
        lines = reg_diff_file.read().splitlines()
    reg_diff_file.close
    reg_diff = set([(reg,val) for reg,val in zip(lines[::2],lines[1::2])])
    #print (reg_diff)

    with open('%s/reg_diff_klee%d.log'%(folder,i),mode='r') as reg_diff_klee_file:
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
        print ("[Source Code]\t Available into %s/main%d.c :"%(folder,i))
        print ("")
        with open('%s/main%d.c'%(folder,i),mode='r') as source_file:
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
