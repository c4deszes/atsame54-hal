enable_testing()
include(GoogleTest)

# Hardware Abstraction Layer unit tests
add_executable(
    atsame54-hal-unittest EXCLUDE_FROM_ALL
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test_watchdog.cpp
)
target_link_libraries(atsame54-hal-unittest PUBLIC atsame54-hal-test gtest)
gtest_discover_tests(
    atsame54-hal-unittest
    TEST_PREFIX HAL_UNITTEST_
    XML_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/report
)
