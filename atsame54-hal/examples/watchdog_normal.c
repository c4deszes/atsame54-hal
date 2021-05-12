/**
 * @file watchdog.c
 * @author your name (you@domain.com)
 * @brief 
 */
#include "hal/system/watchdog.h"

const wdt_normal_configuration wdt_config = {
    .always_on = false,
    .period = CYC512,
    .ew_period = CYC512,
    .ew_callback = NULL
}

int main() {
    WDT_Initialize(&wdt_config);

    while(1) {
        WDT_Acknowledge();
    }
}
