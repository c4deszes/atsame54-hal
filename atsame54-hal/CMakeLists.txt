project(atsame54-hal DESCRIPTION "ATSAME54 Hardware Abstraction Layer")
set(PROJECT_VERSION "0.1.0")

# Hardware Abstraction Layer interface
add_library(atsame54-hal-api INTERFACE)
target_include_directories(atsame54-hal-api INTERFACE api)

add_library(atsame54-hal-private-api INTERFACE)
target_include_directories(atsame54-hal-private-api INTERFACE include)

set(
    SOURCES
    src/system/clock.c
    src/system/mcu.c
    src/system/watchdog.c
    src/io/eic.c
    src/io/gpio.c
    src/complex/pdec.c
    src/complex/rstc.c
    src/complex/rtc.c
    src/complex/tcc.c
    src/complex/trng.c
)

# Hardware Abstraction Layer library
add_library(
    atsame54-hal EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_link_libraries(atsame54-hal PUBLIC atsame54-core atsame54-hal-api)
target_link_libraries(atsame54-hal PRIVATE atsame54-hal-private-api)

# Hardware Abstraction Layer test library
add_library(
    atsame54-hal-test EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_compile_options(atsame54-hal-test PRIVATE --coverage)
target_link_libraries(atsame54-hal-test PUBLIC atsame54-core-mock atsame54-hal-api)
target_link_libraries(atsame54-hal-test PUBLIC atsame54-hal-private-api)
target_link_libraries(atsame54-hal-test PRIVATE -lgcov --coverage)

add_subdirectory(fake)

# Hardware Abstraction Library tests
add_subdirectory(test/unittest)
