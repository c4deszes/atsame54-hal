project(atsame54-hal DESCRIPTION "ATSAME54 Hardware Abstraction Layer")
set(PROJECT_VERSION "0.1.0")

# Hardware Abstraction Layer interface
add_library(atsame54-hal-api INTERFACE)
target_include_directories(atsame54-hal-api INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(
    ATSAME54_HAL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/clock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/mcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/watchdog.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/eic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/complex/pdec.c
)

# Hardware Abstraction Layer library
add_library(
    atsame54-hal EXCLUDE_FROM_ALL
    ${ATSAME54_HAL_SOURCES}
)
target_link_libraries(atsame54-hal PUBLIC atsame54-core atsame54-hal-api)

# Hardware Abstraction Layer test library
add_library(
    atsame54-hal-test EXCLUDE_FROM_ALL
    ${ATSAME54_HAL_SOURCES}
)
target_link_libraries(atsame54-hal-test PUBLIC atsame54-core-mock atsame54-hal-api)

# Hardware Abstraction Library tests
add_subdirectory(test/unittest)
