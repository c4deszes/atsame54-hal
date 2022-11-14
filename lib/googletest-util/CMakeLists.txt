add_library(
    gtest-util EXCLUDE_FROM_ALL
    src/gtest_util.cpp
)
target_include_directories(gtest-util PUBLIC api)
target_link_libraries(gtest-util PUBLIC gtest)
