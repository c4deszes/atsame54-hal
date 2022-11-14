/**
 * @file test_watchdog.cpp
 * @author Balazs Eszes
 * @brief 
 * 
 * @copyright Copyright (c) 2021
 */
#include "gtest/gtest.h"

extern "C" {
    #include "hal/system/wdt.h"
    #include "device/same54p20a.h"
}

/**
 * @brief Watchdog test fixture
 */
class Watchdog : public testing::Test {
protected:
    /**
     * @brief Resets the watchdog peripheral
     */
    void SetUp() override {
        WDT_REGS->WDT_CONFIG = WDT_CONFIG_RESETVALUE;
        WDT_REGS->WDT_CTRLA = WDT_CTRLA_RESETVALUE;
        WDT_REGS->WDT_EWCTRL = WDT_EWCTRL_RESETVALUE;
    }
};

/**
 * Tests whether initialization of Watchdog happens correctly, under the following conditions:
 * - Watchdog mode is normal
 * - Always On is disabled
 * - Period is CYC8
 * - Early warning disabled
 * 
 * Test steps:
 * - Setup conditions
 * - Call WDT_InitializeNormal()
 * - Expect Watchdog registers to be set
 */
TEST_F(Watchdog, InitializeNormalWithoutEarlyWarning) {
    // Setup
    const wdt_normal_configuration config = {
        .always_on = false,
        .period = CYC8,
        .ew_period = CYC8,
        .ew_callback = NULL
    };

    // Body
    WDT_InitializeNormal(&config);

    // Assertions
    EXPECT_EQ(WDT_REGS->WDT_CONFIG, CYC8);
    EXPECT_EQ(WDT_REGS->WDT_EWCTRL, CYC8);
    EXPECT_NE((WDT_REGS->WDT_CTRLA | WDT_CTRLA_ENABLE_Msk), 0);
}

/**
 * @brief Local Watchdog interrupt handler
 */
static void Watchdog_InterruptHandler(void) {
}

/**
 * Tests whether initialization of Watchdog happens correctly, under the following conditions:
 * - Watchdog mode is normal
 * - Always On is disabled
 * - Period is CYC8
 * - Early warning enabled
 * 
 * Test steps:
 * - Setup conditions
 * - Call WDT_InitializeNormal()
 * - Call WDT_Handler()
 * - Expect Watchdog registers to be set
 * - Expect Watchdog handler to be called on early warning interrupt
 */
TEST_F(Watchdog, InitializeNormalWithEarlyWarning) {
    // Setup
    const wdt_normal_configuration config = {
        .always_on = false,
        .period = CYC8,
        .ew_period = CYC8,
        .ew_callback = Watchdog_InterruptHandler
    };

    // Body
    WDT_InitializeNormal(&config);

    WDT_Handler();

    // Assertions
    EXPECT_EQ(WDT_REGS->WDT_CONFIG, CYC8);
    EXPECT_EQ(WDT_REGS->WDT_EWCTRL, CYC8);
    EXPECT_NE((WDT_REGS->WDT_CTRLA | WDT_CTRLA_ENABLE_Msk), 0);
}
