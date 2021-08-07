/**
 * @file test_trng.cpp
 * @author Balazs Eszes
 * @brief 
 * 
 * @copyright Copyright (c) 2021
 */
#include "gtest/gtest.h"
#include "gtest_util/gtest_util.h"

extern "C" {
    #include "hal/complex/trng.h"
    #include "device/same54p20a.h"
}

/**
 * @brief True Random Number Generator test fixture
 */
class TrueRandomNumberGenerator : public testing::Test {
protected:
    /**
     * @brief Resets the True Random Number Generator peripheral
     */
    void SetUp() override {
        TRNG_REGS->TRNG_CTRLA = TRNG_CTRLA_RESETVALUE;
        TRNG_REGS->TRNG_DATA = TRNG_DATA_RESETVALUE;
        TRNG_REGS->TRNG_EVCTRL = TRNG_EVCTRL_RESETVALUE;
        TRNG_REGS->TRNG_INTENSET = TRNG_INTENSET_RESETVALUE;
        TRNG_REGS->TRNG_INTENCLR = TRNG_INTENCLR_RESETVALUE;
        TRNG_REGS->TRNG_INTFLAG = TRNG_INTFLAG_RESETVALUE;
    }
};

/**
 * Tests whether initialization of the TRNG peripheral happens correctly
 * 
 * Test steps:
 * - Call \fn TRNG_Initialize
 * - 
 */
TEST_F(TrueRandomNumberGenerator, InitializeShouldWork) {
    // Body
    TRNG_Initialize();

    EXPECT_BITSET(TRNG_REGS->TRNG_CTRLA, TRNG_CTRLA_ENABLE_Pos);
}

/**
 * Tests whether the synchronuous getter of TRNG works correctly after initialization
 * 
 * Test steps:
 * - Initialize TRNG, set the DATA value and set the interrupt flag
 * - Call \fn TRNG_GetSync
 * - Expect the DATA value to be returned
 */
TEST_F(TrueRandomNumberGenerator, GetSyncShouldReturnValid) {
    // Setup
    TRNG_Initialize();
    TRNG_REGS->TRNG_DATA = 0x69696969;
    TRNG_REGS->TRNG_INTFLAG |= TRNG_INTFLAG_DATARDY_Msk;

    // Body
    uint32_t data = TRNG_GetSync();

    // Assertions
    EXPECT_EQ(data, 0x69696969);
}

uint32_t GetAsyncShouldCallback_data = 0;

static void GetAsyncShouldCallback_handler(uint32_t data) {
    GetAsyncShouldCallback_data = data;
}

/**
 * Tests whether the asynchronuous getter of TRNG works correctly after initialization
 * 
 * Test steps:
 * - Initialize TRNG, set the DATA value and create callback function
 * - Call \fn TRNG_GetAsync
 * - Expect the TRNG Data Ready interrupt to be enabled
 * - Call \fn TRNG_Handler
 * - Expect callback to be called with the correct data and the interrupt to be cleared
 */
TEST_F(TrueRandomNumberGenerator, GetAsyncShouldCallback) {
    // Setup
    TRNG_Initialize();
    TRNG_REGS->TRNG_DATA = 0x69696969;

    // Body
    TRNG_GetAsync((trng_callback)GetAsyncShouldCallback_handler);
    EXPECT_BITSET(TRNG_REGS->TRNG_INTENSET, TRNG_INTENSET_DATARDY_Pos);

    TRNG_Handler();

    // Assertions
    EXPECT_EQ(GetAsyncShouldCallback_data, 0x69696969);
    EXPECT_BITSET(TRNG_REGS->TRNG_INTENCLR, TRNG_INTENCLR_DATARDY_Pos);
}

/**
 * Tests whether the disable function of TRNG works
 * 
 * Test steps:
 * - Initialize TRNG
 * - Call \fn TRNG_Disable
 * - Expect TRNG to be disabled and interrupts to be disabled
 */
TEST_F(TrueRandomNumberGenerator, DisableShouldWork) {
    // Setup
    TRNG_Initialize();

    // Body
    TRNG_Disable();

    // Assertions
    EXPECT_BITCLR(TRNG_REGS->TRNG_CTRLA, TRNG_CTRLA_ENABLE_Pos);
    EXPECT_BITSET(TRNG_REGS->TRNG_INTENCLR, TRNG_INTENCLR_DATARDY_Pos);
}
