# Integration tests
add_executable(
    XplainedBoardIntegrationTest
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(
    XplainedBoardIntegrationTest
    PUBLIC
    XplainedBoardTest
    unity
)
set_target_properties(XplainedBoardIntegrationTest PROPERTIES SUFFIX ".elf")
