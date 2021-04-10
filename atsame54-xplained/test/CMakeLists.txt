# Test library
if(XPLAINED_BOARD_INTEGRATION_TEST_ENABLED OR XPLAINED_BOARD_UNIT_TEST_ENABLED)
    add_library(
        XplainedBoardTest
        ${XPLAINED_BOARD_SOURCES_LIST}
    )
    target_link_libraries(XplainedBoardTest PUBLIC MockHal)
    target_include_directories(XplainedBoardTest PUBLIC ${XPLAINED_BOARD_INCLUDE_LIST})
endif()

if(XPLAINED_BOARD_INTEGRATION_TEST_ENABLED)
    add_subdirectory(inttest)
endif()
if(XPLAINED_BOARD_UNIT_TEST_ENABLED)
    add_subdirectory(unittest)
endif()
