#
# Core library
#
add_library(
	Core
	${CMAKE_CURRENT_SOURCE_DIR}/src/startup_same54p20a.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/system_same54p20a.c
)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmsis/include)

target_compile_options(Core PUBLIC "-mcpu=cortex-m4" "-gdwarf-2" "-mthumb")
target_link_options(Core PUBLIC "-mcpu=cortex-m4" "-mthumb")
