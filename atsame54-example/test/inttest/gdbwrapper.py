from typing import List
from pygdbmi.gdbcontroller import GdbController

import logging

class BreakpointHandler():
    def __init__(self, number: int) -> None:
        self.number = number

class GdbWrapper():

    def __init__(self, command: List[str]) -> None:
        self._command = command
        self._controller = None

    def close(self):
        self._controller.exit()

    def __enter__(self):
        self._controller = GdbController(command=self._command)
        self._controller.get_gdb_response()
        return self

    def __exit__(self ,type, value, traceback):
        self.close()

    def target_remote(self, host: str):
        cs = self._controller.write(f"-target-select extended-remote {host}", timeout_sec=30)[0]

        #if cs['message'] != 'connected':
        #    raise Exception('Failed to connect', cs)

    def load_symbols(self, path):
        self._controller.write(f"-file-exec-and-symbols {path}", timeout_sec=0.5)

    def monitor_reset(self):
        self._controller.write('-interpreter-exec console "monitor reset halt"', timeout_sec=0.3)
        pass

    def data_evaluate(self, expression: str):
        pass

    def data_read_memory(self, expression: str):
        pass

    def breakpoint_insert(self, expression: str) -> BreakpointHandler:
        # -break-insert [ -t ] [ -h ] [ -f ] [ -d ] [ -a ] [ --qualified ]
        #    [ -c condition ] [ --force-condition ] [ -i ignore-count ]
        #    [ -p thread-id ] [ location ]
        bp = self._controller.write(f"-break-insert {expression}", timeout_sec=0.5)[0]

        #if bp['message'] != 'done':
        #    raise Exception('Failed to insert breakpoint', bp)
        return None
        #return BreakpointHandler(int(bp['payload']['bkpt']['number']))

    def breakpoint_set_condition(self, breakpoint: BreakpointHandler, expression: str):
        # -break-condition [ --force ] number [ expr ]
        pass

    def breakpoint_enable(self, breakpoint: BreakpointHandler):
        # -break-enable ( breakpoint )+
        pass

    def breakpoint_disable(self, breakpoint: BreakpointHandler):
        # -break-disable ( breakpoint )+
        pass

    def breakpoint_delete(self, breakpoint: BreakpointHandler):
        # -break-delete ( breakpoint )+
        pass

    def exec_continue(self):
        pass

    def exec_continue_wait(self, timeout: float) -> BreakpointHandler:
        cr = self._controller.write("-exec-continue")
        
        resp = self._controller.get_gdb_response(timeout_sec=timeout)

        if resp['message'] != 'stopped':
            pass
        pass

    def exec_step(self, timeout):
        # -exec-step
        pass

    def exec_interrupt(self):
        pass

    def exec_finish(self, resume: bool=False):
        pass

    def exec_return(self):
        pass

class GdbServerWrapper():

    def __init__(self) -> None:
        pass