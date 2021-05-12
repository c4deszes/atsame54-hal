# Integration tests
add_executable(
    atsam54-xplained-inttest
    $<TARGET_OBJECTS:atsam54-xplained-obj>
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(
    atsam54-xplained-inttest
    PUBLIC
    atsam54-xplained-obj
    atsame54-hal-mock
    unity
)
set_target_properties(atsam54-xplained-inttest PROPERTIES SUFFIX ".elf")
