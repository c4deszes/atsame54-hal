add_library(
    atsame54-hal-fake EXCLUDE_FROM_ALL
    src/fake_gpio.c
    src/fake_trng.c
)
target_include_directories(atsame54-hal-fake PUBLIC include)
target_link_libraries(atsame54-hal-fake PUBLIC atsame54-hal-api atsame54-hal-private-api assert-lib-std)
