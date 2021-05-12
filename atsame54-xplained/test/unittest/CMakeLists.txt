# Unit tests
add_executable(
    atsam54-xplained-unittest
    $<TARGET_OBJECTS:atsam54-xplained-obj>
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_link_libraries(
    atsam54-xplained-unittest
    PUBLIC
    atsame54-hal-mock
    unity
)
set_target_properties(atsam54-xplained-unittest PROPERTIES SUFFIX ".elf")
