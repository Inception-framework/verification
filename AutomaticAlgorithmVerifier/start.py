#!/usr/bin/python3.5
"""Module docstring.

Start script to verify Compiler against a given algorithm
"""
import sys

from optparse import OptionParser

from ConcreteMachine import ConcreteMachine
from VirtualMachine import VirtualMachine
from Binary import Binary

usage = "usage: %prog [options] binary_file bitcode_file output_dir"
parser = OptionParser(usage=usage)
parser.add_option("-b", "--input-elf-file", dest="input_bin_file",
                  help="Input algorithm", type="string")
parser.add_option("-k", "--input-bc-file", dest="input_bc_file",
                  help="Input algorithm", type="string")
parser.add_option("-o", "--output-dir", dest="output_dir",
                  help="Output directory", type="string")
(options, args) = parser.parse_args()

import coloredlogs, logging

logger = logging.getLogger(__name__)

coloredlogs.install(level='DEBUG', logger=logger)

if not options.output_dir:
    parser.error('output_dir not given')

if not options.input_bin_file:
    parser.error('input_bin_file not given')

if not options.input_bc_file:
    parser.error('input_bc_file not given')

def main():

    input_bc_file = options.input_bc_file;
    input_bin_file = options.input_bin_file;

    logger.info("Initializing Concrete and Virtual Machine ...")
    device = ConcreteMachine()
    analyzer = VirtualMachine()

    # load the binary file in memory
    logger.info("Loading bitcode onto the concrete machine...")
    device.load(input_bin_file)

    # load the binary file in memory
    logger.info("Loading bitcode onto the virtual machine...")
    analyzer.load(input_bc_file)


    device.start()
    analyzer.start()

    while( device.isRunning() ):
        continue

    while( analyzer.isRunning() ):
        continue

    dump_device =  device.dump()
    dump_analyzer = analyzer.dump()

    assert(compareDump(dump_device, dump_analyzer) == True)

    logger.info("Shutting down ...")

    device.stop()
    analyzer.stop()

if __name__ == "__main__":
    main()
