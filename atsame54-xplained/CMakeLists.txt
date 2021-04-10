# Board source list and headers
set(
    XPLAINED_BOARD_SOURCES_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/board/clock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/board/init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/communication/can.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/communication/virtual_com.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/analog.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/ext1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/ext2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/ext3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/pdec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/user_io.c
)
set(
    XPLAINED_BOARD_INCLUDE_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Board library
add_library(
    XplainedBoard
    ${XPLAINED_BOARD_SOURCES_LIST}
)
target_link_libraries(XplainedBoard PUBLIC Hal)
target_include_directories(XplainedBoard PUBLIC ${XPLAINED_BOARD_INCLUDE_LIST})

# Board tests
option(XPLAINED_BOARD_UNIT_TEST_ENABLED "Enables Board unit test" ON)
option(XPLAINED_BOARD_INTEGRATION_TEST_ENABLED "Enables Board integration tests" ON)
add_subdirectory(test)
