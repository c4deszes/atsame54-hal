# Integration tests
add_executable(
    atsame54-xplained-inttest EXCLUDE_FROM_ALL
    src/main.c
    src/test_user_io.c
)
target_include_directories(atsame54-xplained-inttest PRIVATE include)
target_link_libraries(atsame54-xplained-inttest PUBLIC atsame54-xplained-test atsame54-hal-fake unity)
add_test(NAME atsame54-xplained-inttest COMMAND atsame54-xplained-inttest)
