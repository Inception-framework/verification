#!/usr/bin/python3.5
import socket
import sys
import subprocess
import time
import coloredlogs, logging

logger = logging.getLogger(__name__)

coloredlogs.install(level='DEBUG', logger=logger)

from Machine import Machine

class VirtualMachine(Machine):
    def __init__(self):
        Machine.__init__(self)
        self._pipe = None
        self._command = None

    def command(self, message, waitForAnswer=False):
        self._command.send(message.encode('utf-8'))

        if(waitForAnswer):
            return self._command.recv(2048)

    def start(self):
        Machine.start(self)
        self.command("6main")

    def stop(self):
        Machine.stop(self)
        self.command("5")
        time.sleep(2)
        self._command.close()

    def step(self):
        Machine.step(self)
        self.command("4")

    def dump(self):
        Machine.dump(self)
        return self.command("7", True)

    def load(self, bitcode):
        Machine.load(self)

        # edit the configuration file to set binary location

        # opend a subprocess to start the virtual machine
        self._pipe = subprocess.Popen("klee "+bitcode, shell=True, stdout=subprocess.PIPE)

        # wait a few ...
        time.sleep(2)

        # start client socket to connecto to machine debugger server socket
        self._command = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._command.connect(("localhost", 2017))