# Create library
add_library(
	Hal
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mcu.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pdec.c
)
target_link_libraries(Hal PUBLIC Core)
target_include_directories(Hal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
