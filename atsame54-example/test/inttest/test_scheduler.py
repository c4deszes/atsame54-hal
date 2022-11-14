import pytest

class TestScheduler:

    def test_setup_should_be_called_once(self, debugger):
        debugger.target_remote(':3333')
        debugger.load_symbols('../../../build/user-debug/atsame54-example/atsame54-example.elf')
        debugger.monitor_reset()
        bp = debugger.breakpoint_insert("setup")

        debugger.exec_continue_wait(5)

        with pytest.raises(Exception):
            debugger.exec_continue_wait(10)
        pass

    @pytest.mark.skip("xd")
    def test_loop_should_be_called_periodically(self, debugger):
        debugger.monitor_reset()
        bp = debugger.breakpoint_insert("loop")

        for _ in range(10):
            debugger.exec_continue_wait(1)
