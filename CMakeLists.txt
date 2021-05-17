cmake_minimum_required(VERSION 3.13)

project(
    ATSAME54_HAL
    VERSION "0.1.0"
)

# Core libraries
add_subdirectory(atsame54-core)
add_subdirectory(atsame54-hal)

# Board support for the development board
add_subdirectory(atsame54-xplained)

# Example application
add_subdirectory(atsame54-example)

# Test suite
add_subdirectory(lib/fff)
add_subdirectory(lib/googletest)
add_subdirectory(lib/unity)

# Documentation
add_subdirectory(docs)
