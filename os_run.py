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

def run_catch_error(command_str, continue_stop_n):
    ret = os.system(command_str)
    if(ret != 0):
        print("")
        print("-> fail while running from python: %s"%(command_str))
        if(continue_stop_n == False):
            print("aborting...")
            sys.exit(1)
        else:
            print("continuing anyway...")
            return 1
        print("")
    return 0
        
         
           
