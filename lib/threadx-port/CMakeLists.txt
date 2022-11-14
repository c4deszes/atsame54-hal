add_library(
    threadx-adapter EXCLUDE_FROM_ALL
    src/tx_initialize_low_level.S
)
target_link_libraries(threadx-adapter PRIVATE atsame54-core)
target_link_libraries(threadx PRIVATE threadx-adapter)
target_link_libraries(threadx PRIVATE atsame54-core)
