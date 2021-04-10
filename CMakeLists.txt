cmake_minimum_required(VERSION 3.13)

project(
    ATSAME54_HAL
    VERSION "0.1.0"
)

option(ATSAME54_XPLAINED_BOARD_SUPPORT "Builds board support library" ON)
option(ATSAME54_EXAMPLE "Builds example application" ON)
option(ATSAME54_DOCS "Builds documentation" OFF)

# Core libraries
add_subdirectory(atsame54-core)
add_subdirectory(atsame54-hal)

# Board support for the development board
if(ATSAME54_XPLAINED_BOARD_SUPPORT)
    add_subdirectory(atsame54-xplained)
endif()

# Example application
if(ATSAME54_EXAMPLE)
    add_subdirectory(atsame54-example)
endif()

# Test suite
add_subdirectory(lib/fff)
add_subdirectory(lib/unity)

# Documentation
if(ATSAME54_DOCS)
    add_subdirectory(docs)
endif()
