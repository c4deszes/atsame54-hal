project(atsame54-core DESCRIPTION "ATSAME54 Core library")
set(PROJECT_VERSION "1.0.0")

# Core interface
add_library(atsame54-core-api INTERFACE)
target_include_directories(
    atsame54-core-api
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmsis/include
)

# Core library
add_library(
    atsame54-core STATIC EXCLUDE_FROM_ALL
    ${CMAKE_CURRENT_SOURCE_DIR}/src/startup_same54p20a.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system_same54p20a.c
)
target_compile_options(atsame54-core PUBLIC "-mcpu=cortex-m4" "-gdwarf-2" "-mthumb")
target_link_options(atsame54-core PUBLIC "-mcpu=cortex-m4" "-mthumb")
target_link_libraries(atsame54-core PUBLIC atsame54-core-api)

# Core mock library
add_library(
    atsame54-core-mock STATIC EXCLUDE_FROM_ALL
    ${CMAKE_CURRENT_SOURCE_DIR}/mock/same54p20a.c
)
target_compile_options(
    atsame54-core-mock
    PUBLIC
    -include${CMAKE_CURRENT_SOURCE_DIR}/mock/same54p20a.h
)
target_link_libraries(atsame54-core-mock PUBLIC atsame54-core-api)
