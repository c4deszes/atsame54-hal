cmake_minimum_required(VERSION 3.13)

project(
    atsame54-parent
    DESCRIPTION "ATSAME54 Package"
    HOMEPAGE_URL "https://github.com/c4deszes/atsame54-hal")
set(PROJECT_VERSION "0.1.0")
file(STRINGS "AUTHORS" CMAKE_PROJECT_AUTHORS)

enable_testing()
set(CTEST_OUTPUT_ON_FAILURE ON)

include(GoogleTest)
include(tools/hexregistry/package.cmake)

# Core libraries
add_subdirectory(atsame54-core)
add_subdirectory(atsame54-hal)

# Board support for the development board
add_subdirectory(atsame54-xplained)

# Bootloader
# add_subdirectory(atsame54-bootloader)

# Example application
add_subdirectory(atsame54-example)

# Test suite
add_subdirectory(lib/fff)
add_subdirectory(lib/googletest)
add_subdirectory(lib/unity)
add_subdirectory(lib/assert)
add_subdirectory(lib/googletest-util)

# Documentation
add_subdirectory(docs)
