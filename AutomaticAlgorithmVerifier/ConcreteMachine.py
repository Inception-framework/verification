import sys
from Machine import Machine


sys.path.append('../../RTDebugger-driver/src/')
import interactive

class ConcreteMachine(Machine):

    def __init__(self):
        Machine.__init__(self)

        self._command = interactive.Interactive('../../RTDebugger-driver/Debug/libinception.so',False)

    def isRunning(self):
        Machine.isRunning(self)
        return False

    def start(self):
        Machine.start(self)

    def stop(self):
        Machine.stop(self)
        self._command.halt()

    def step(self):
        Machine.step(self)
        self._command.step(1)

    def dump(self):
        Machine.dump(self)
        return self._command.dump_all_regs()

    def load(self, binary):
        Machine.load(self)

        self._command.halt()
        self._command.load_binary_in_sram(binary, 0x20000000)
        self._command.clear_all_regs()
        self._command.write_reg(15, 0x20000000)
