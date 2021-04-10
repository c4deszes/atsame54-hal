# HAL source list and headers
set(
    HAL_SOURCES_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/clock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/mcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system/watchdog.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/eic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io/gpio.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/complex/pdec.c
)
set(
    HAL_INCLUDE_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Hardware Abstraction Layer library
add_library(
    Hal
    ${HAL_SOURCES_LIST}
)
target_link_libraries(Hal PUBLIC Core)
target_include_directories(Hal PUBLIC ${HAL_INCLUDE_LIST})

add_subdirectory(test)
