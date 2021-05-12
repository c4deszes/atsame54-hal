project(
    atsame54-xplained
    VERSION "0.1.0"
)

# ATSAME54 Xplained Pro board interface
add_library(
    atsame54-xplained-api
    INTERFACE
)
target_include_directories(
    atsame54-xplained-api
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ATSAME54 Xplained Pro board implementation
add_library(
    atsame54-xplained
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
target_link_libraries(
    atsame54-xplained
    PUBLIC
    atsame54-hal
    atsame54-xplained-api
)

# ATSAME54 Xplained Pro board tests
option(XPLAINED_BOARD_UNIT_TEST_ENABLED "Enables Board unit test" OFF)
option(XPLAINED_BOARD_INTEGRATION_TEST_ENABLED "Enables Board integration tests" OFF)

if(XPLAINED_BOARD_INTEGRATION_TEST_ENABLED)
    add_subdirectory(test/inttest)
endif()
if(XPLAINED_BOARD_UNIT_TEST_ENABLED)
    add_subdirectory(test/unittest)
endif()
