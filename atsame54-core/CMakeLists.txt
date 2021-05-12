project(
    atsame54-core
    VERSION "1.0.0"
)

# ATSAME54 Core interface
add_library(
    atsame54-core-api
    INTERFACE
)
target_include_directories(atsame54-core-api INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(atsame54-core-api INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmsis/include)
target_compile_options(atsame54-core-api INTERFACE "-mcpu=cortex-m4" "-gdwarf-2" "-mthumb")

# ATSAME54 Core library
add_library(
    atsame54-core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/startup_same54p20a.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/system_same54p20a.c
)
target_link_options(atsame54-core PUBLIC "-mcpu=cortex-m4" "-mthumb")
target_link_libraries(atsame54-core PUBLIC atsame54-core-api)
