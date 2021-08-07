# Hardware Abstraction Layer unit tests
add_executable(
    atsame54-hal-unittest EXCLUDE_FROM_ALL
    src/main.cpp
    src/test_rstc.cpp
    src/test_tcc.cpp
    src/test_trng.cpp
    src/test_watchdog.cpp
)
target_link_libraries(atsame54-hal-unittest PUBLIC atsame54-hal-test gtest gtest-util)
gtest_discover_tests(
    atsame54-hal-unittest
    TEST_PREFIX atsame54-hal-unittest_
    XML_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/report
)
