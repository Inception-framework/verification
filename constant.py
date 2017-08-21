#!/usr/bin/python3.5
# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

import os
import random
import itertools

from collections import OrderedDict

def generate(seed):
    random.seed(seed)
    byte = random.randint(0,2**8-1)
    combs = list(itertools.product(
                     [byte,
                      byte << 16 | byte,
                      byte << 24 | byte << 8,
                      byte << 24 | byte << 16 | byte << 8 | byte,
                      (byte << 23) | 0x40000000,
                      (byte << 22) | 0x20000000,
                      (byte << 21) | 0x10000000,
                      (byte <<  3) | 0x00000040,
                      (byte <<  2) | 0x00000020,
                      (byte <<  1) | 0x00000010]
                ))
    #print(combs)
    #for c in combs:
    #    print(hex(c[0]))
    return random.choice(combs)[0]

#print ("return ="+hex(generate_const(0)))
