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
    print("./verify.py \
           -c <(continue in case of error) True/False> \
           [-i <input folder> \
           [-o <output folder> \
           [-f <reglist to filter>]")
    sys.exit(0)

ifolder="test_cases"
ofolder="test_results"
filter_reglist = []

if len(sys.argv) <= 1:
    print_usage_error()
try:
    opts,args = getopt.getopt(sys.argv[1:],"hc:i:o:f:",["help",
                                                       "continue=",
                                                       "input-folder=",
                                                       "output-folder="])
except getopt.GetoptError:
    print_usage_error()
for opt,arg in opts:
    if opt in ("-h","--help"):
        print("./generator.py")
        print("options:")
        print("    c,continue=:        True->skip errors, False->stop on error")
        print("    i,input-folder=:    folder where test cases are stored")
        print("    o,output-folder=:   folder where test results are stored")
        print("    f,filter-reglist=:  comma-separated list of registers not \
               to take into cosideration for the check")
        print("")
    elif opt in ("-c","--continue"):
        if arg == "True":
            cont = True
        elif arg == "False":
            cont = False
        else: 
            print("Error, continue must be True or False")
            sys.exit(1)
    elif opt in ("-i","--input-folder="):
            ifolder = arg 
    elif opt in ("-o","--output-folder="):
            ofolder = arg 
    elif opt in ("-f","--filter-reglist="):
            filter_reglist = arg.split(",")

# create output folder starting from the input
os_run.run_catch_error("mkdir -p %s"%(ofolder),False)
os_run.run_catch_error("cp %s/* %s/"%(ifolder,ofolder),False)

# save version
vfile = os.path.abspath(ofolder+"/version_verify.log")
os_run.run_catch_error("./versioning.sh %s"%(vfile),False)

# Retrieve number of generated tests
with open('%s/Ntests'%(ofolder),mode='r') as Ntests_file:
    Ntests = int(Ntests_file.readline())
Ntests_file.close

# DUT
# C + asm stubs => llvm IR
# TODO better
for i in range(0,Ntests):
    os_run.run_catch_error('echo "#define KLEE\n$(cat %s/main%d.c)" > \
                            %s/main%d.c'%(ofolder,i,ofolder,i),cont)
    ret = os_run.run_catch_error('./build.sh main%d inception %s'%(i,ofolder),cont)
    if(ret != 0):
        continue
    # Run klee and dump registers
    print ("Running klee ...")
    ret = os_run.run_catch_error("./run_klee.sh "+str(i)+" "+str(ofolder),cont)
    if(ret != 0):
        continue

    # check 
    with open('%s/reg_diff%d.log'%(ofolder,i),mode='r') as reg_diff_file:
        lines = reg_diff_file.read().splitlines()
    reg_diff_file.close
    reg_diff = set([(reg,val) \
                   for reg,val in zip(lines[::2],lines[1::2]) \
                   if reg not in filter_reglist])
    #print (reg_diff)

    with open('%s/reg_diff_klee%d.log'%(ofolder,i),mode='r') as reg_diff_klee_file:
        lines_klee = reg_diff_klee_file.read().splitlines()
    reg_diff_klee_file.close
    reg_diff_klee = set([(reg,val) \
                        for reg,val in zip(lines_klee[::2],lines_klee[1::2]) \
                        if reg not in filter_reglist])
    #print (reg_diff_klee)

    diff = reg_diff_klee.symmetric_difference(reg_diff)
    if(diff == set()):
        print ("TEST %d PASSED"%(i))
        print ("\t[Test]")
        print ("\t"+str(reg_diff_klee))
        print ("\t[Oracle]")
        print ("\t"+str(reg_diff))
        print ("\t[Differences]")
        print ("\t"+str(diff))
    else:
        print ("-----------------[TEST %d]---------------------"%(i))
        print ("[RESULT]\t The test failed ...",diff)
        print ("")
        print ("[Source Code]\t Available into %s/main%d.c :"%(ofolder,i))
        print ("")
        with open('%s/main%d.c'%(ofolder,i),mode='r') as source_file:
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
