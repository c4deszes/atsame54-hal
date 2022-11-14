/**
 * @file watchdog.c
 * @author Balazs Eszes
 * @brief Watchdog implementation
 */
#include "hal/system/wdt.h"

#include <stddef.h>
#include "device/same54p20a.h"

wdt_ew_callback wdt_ew_handle = NULL;

void WDT_InitializeNormal(const wdt_normal_configuration* wdt_conf) {
    /* Configure watchdog period */
    WDT_REGS->WDT_CONFIG = wdt_conf->period & WDT_CONFIG_PER_Msk;
    WDT_REGS->WDT_EWCTRL = (wdt_conf->ew_period & WDT_EWCTRL_EWOFFSET_Msk);

    if (wdt_conf->ew_callback != NULL) {
        WDT_EnableInterrupt(wdt_conf->ew_callback);
    }

    /* Enable Watchdog */
    WDT_REGS->WDT_CTRLA |= WDT_CTRLA_ENABLE_Msk;

    while ((WDT_REGS->WDT_SYNCBUSY & WDT_SYNCBUSY_ENABLE_Msk) == WDT_SYNCBUSY_ENABLE_Msk) {
        /* Wait for synchronization */
    }
}

void WDT_InitializeWindow(const wdt_window_configuration* wdt_conf) {
    /* Configure Open and Closed window periods */
    WDT_REGS->WDT_CONFIG =    (wdt_conf->closed & WDT_CONFIG_WINDOW_Msk)
                            | (wdt_conf->open & WDT_CONFIG_PER_Msk);
    WDT_REGS->WDT_EWCTRL = (wdt_conf->ew_period & WDT_EWCTRL_EWOFFSET_Msk);

    if (wdt_conf->ew_callback != NULL) {
        WDT_EnableInterrupt(wdt_conf->ew_callback);
    }

    /* Enable Watchdog */
    WDT_REGS->WDT_CTRLA |= WDT_CTRLA_ENABLE_Msk;

    while ((WDT_REGS->WDT_SYNCBUSY & WDT_SYNCBUSY_ENABLE_Msk) == WDT_SYNCBUSY_ENABLE_Msk) {
        /* Wait for synchronization */
    }
}

void WDT_EnableInterrupt(wdt_ew_callback handle) {
    wdt_ew_handle = handle;

    /* Enable interrupt in peripheral and NVIC controllers */
    WDT_REGS->WDT_INTENSET = WDT_INTENSET_EW_Msk;
    NVIC_EnableIRQ(WDT_IRQn);
}

void WDT_DisableInterrupt(void) {
    /* Disable interrupt in peripheral and NVIC controllers */
    WDT_REGS->WDT_INTENCLR = WDT_INTENCLR_EW_Msk;
    NVIC_DisableIRQ(WDT_IRQn);

    wdt_ew_handle = NULL;
}

void WDT_Disable(void) {
    /* Disable Always On */
    WDT_REGS->WDT_CTRLA &= ~((uint8_t)WDT_CTRLA_ALWAYSON_Msk);

    /* Disable Watchdog */
    WDT_REGS->WDT_CTRLA &= ~((uint8_t)WDT_CTRLA_ENABLE_Msk);

    while ((WDT_REGS->WDT_SYNCBUSY & WDT_SYNCBUSY_ENABLE_Msk) == WDT_SYNCBUSY_ENABLE_Msk) {
        /* Wait for synchronization */
    }
}

void WDT_Acknowledge(void) {
    /* Writing 0xA5 into clear register resets the Watchdog counter */
    WDT_REGS->WDT_CLEAR = WDT_CLEAR_CLEAR_KEY_Val;
}

void WDT_SelfReset(void) {
    /* Issues immediate system reset by writing 0xA6 into clear register */
    WDT_REGS->WDT_CLEAR = WDT_CLEAR_CLEAR_KEY_Val + 1;
}

void WDT_Handler(void) {
    /* Clear Watchdog interrupt flag */
    WDT_REGS->WDT_INTFLAG = WDT_INTFLAG_EW_Msk;

    /* Call Watchdog Early Warning handler */
    if (wdt_ew_handle != NULL) {
        wdt_ew_handle();
    }
}
