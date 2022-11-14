from .gdbwrapper import GdbWrapper
import pytest

@pytest.fixture()
def debugger(request):
    with GdbWrapper(['arm-none-eabi-gdb', '--interpreter=mi2']) as gdb:
        yield gdb
