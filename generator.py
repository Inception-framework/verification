# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

# Import the interactive module, responsible for the communication with the real
# device. Set the path to the libinception cpp library that handles jtag. Use it
# in non command line mode
import sys
import time
import os
sys.path.append('../RTDebugger-driver/src/')
import interactive

# generate the test code
# TODO

# compile the code for inception
# TODO

# compile the code for the real device
os.system('make')

# the real device, used as golden model
device = interactive.Interactive('../RTDebugger-driver/Debug/libinception.so',False)

# execute on the real device
# and dump the differencies in the values of the registers before and after
# execution
device.halt()
device.load_binary_in_sram('./main.bin',0x10000000)
device.write_reg(15,0x10000000)
device.write_reg(0,0)
regs_initial = device.dump_all_regs()
device.resume()
time.sleep(0.01)
device.halt()
regs_final = device.dump_all_regs()
for (initial_name,initial_val),(final_name,final_val) in zip(regs_initial.items(),regs_final.items()):
    if(final_val != initial_val):
        print(final_name,final_val)
