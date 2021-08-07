project(atsame54-xplained DESCRIPTION "ATSAME54 Xplained Board support library")
set(PROJECT_VERSION "0.1.0")

# ATSAME54 Xplained Pro board interface
add_library(atsame54-xplained-api INTERFACE)
target_include_directories(atsame54-xplained-api INTERFACE api)

add_library(atsame54-xplained-private-api INTERFACE)
target_include_directories(atsame54-xplained-private-api INTERFACE include)

set(
    SOURCES
    src/board/clock.c
    src/board/init.c
    src/communication/can.c
    src/communication/virtual_com.c
    src/io/analog.c
    src/io/ext1.c
    src/io/ext2.c
    src/io/ext3.c
    src/io/pdec.c
    src/io/user_io.c
)

# ATSAME54 Xplained Pro board implementation
add_library(
    atsame54-xplained EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_link_libraries(atsame54-xplained PUBLIC atsame54-xplained-api atsame54-hal)
target_link_libraries(atsame54-xplained PRIVATE atsame54-xplained-private-api)

# ATSAME54 Xplained Pro board test library
add_library(
    atsame54-xplained-test EXCLUDE_FROM_ALL
    ${SOURCES}
)
target_link_libraries(atsame54-xplained-test PUBLIC atsame54-xplained-api atsame54-xplained-private-api atsame54-hal-api)

add_subdirectory(test/inttest)
add_subdirectory(test/unittest)
