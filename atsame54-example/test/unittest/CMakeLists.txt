add_executable(
    atsame54-example-unittest EXCLUDE_FROM_ALL
    src/main.cpp
    src/test_application.cpp
)
target_link_libraries(atsame54-example-unittest PUBLIC atsame54-example-test gtest gtest-util)

gtest_discover_tests(
    atsame54-example-unittest
    TEST_PREFIX atsame54-example-unittest_
    XML_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/report
)
