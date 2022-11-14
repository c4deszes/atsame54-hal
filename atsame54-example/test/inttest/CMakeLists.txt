

pytest_discover_tests(
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    TEST_PREFIX atsame54-example-inttest_
    XML_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/report
)
