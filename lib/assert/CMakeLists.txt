# ARM Target Assert adapter
add_library(assert-lib-arm INTERFACE)
target_compile_options(assert-lib-arm INTERFACE -include${CMAKE_CURRENT_SOURCE_DIR}/api/inline/arm_cm_assert.h)

# Google Test Assert adapter
add_library(assert-lib-gtest INTERFACE)
target_compile_options(assert-lib-gtest INTERFACE -include${CMAKE_CURRENT_SOURCE_DIR}/api/inline/gtest_assert.h)

# Unity Test Assert adapter
add_library(assert-lib-unity INTERFACE)
target_compile_options(assert-lib-unity INTERFACE -include${CMAKE_CURRENT_SOURCE_DIR}/api/inline/unity_assert.h)

# Stdlib adapter
add_library(assert-lib-std INTERFACE)
target_compile_options(assert-lib-std INTERFACE -include${CMAKE_CURRENT_SOURCE_DIR}/api/inline/std_assert.h)

# Assert library
add_library(
    assert-lib-generic EXCLUDE_FROM_ALL
    src/custom_assert.c
)
target_include_directories(assert-lib-generic PUBLIC api)
