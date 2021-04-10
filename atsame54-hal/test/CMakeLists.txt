# Mock of Hardware Abstraction Layer
add_library(
    MockHal
    ${CMAKE_CURRENT_SOURCE_DIR}/mock/gpio.c
)
target_include_directories(MockHal PUBLIC ${HAL_INCLUDE_LIST})
target_include_directories(MockHal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MockHal PUBLIC fff)
