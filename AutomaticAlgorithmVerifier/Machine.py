#!/usr/bin/python3.5

from enum import Enum

class MachineState(Enum):
     NONE = 1
     IDLE = 2
     BUSY = 3

class Machine():

    def __init__(self):
        self.state = MachineState.NONE

    def isRunning(self):
        return self.state != MachineState.NONE

    def start(self):
        assert self.state == MachineState.IDLE
        self.state = MachineState.BUSY

    def stop(self):
        assert self.state != MachineState.NONE
        self.state = MachineState.NONE

    def step(self):
        assert self.state != MachineState.NONE

    def dump(self):
        assert self.state != MachineState.NONE
        self.state = MachineState.BUSY

    def load(self):
        assert self.state == MachineState.NONE
        self.state = MachineState.IDLE
