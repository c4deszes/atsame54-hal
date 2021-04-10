# Unit tests
add_executable(
    XplainedBoardUnitTest
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(
    XplainedBoardUnitTest
    PUBLIC
    XplainedBoardTest
    unity
)
set_target_properties(XplainedBoardUnitTest PROPERTIES SUFFIX ".elf")
