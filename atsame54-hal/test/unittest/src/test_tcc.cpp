/**
 * @file test_tcc.cpp
 * @author Balazs Eszes
 * @brief 
 * 
 * @copyright Copyright (c) 2021
 */
#include "gtest/gtest.h"
#include <stddef.h>

extern "C" {
    #include "hal/complex/tcc.h"
    #include "hal/complex/tcc_internal.h"
    #include "device/same54p20a.h"
}

/**
 * @brief Timer Counter Control test fixture
 */
class TimerCounterControl : public testing::Test {
protected:
    /**
     * @brief Resets the TCC module
     */
    void SetUp() override {
        memset(tcc_instances, 0, sizeof(tcc_instances));
        tcc_instance_cntr = 0;
    }
};

/**
 * Tests whether creation of TCC peripheral is possible.
 * 
 * Test steps:
 * - Create TCC peripherals by calling \fn TCC_Create
 * - Expect that the returned handle is non zero
 */
TEST_F(TimerCounterControl, CreateSingle) {
    // Body
    tcc_handle handle = TCC_Create(TCC0_REGS);

    // Assertions
    EXPECT_NE(handle, (tcc_handle)NULL);
    EXPECT_EQ(tcc_instance_cntr, 1);
}

/**
 * Tests whether creation of multiple TCC peripherals is possible.
 * 
 * Test steps:
 * - Create 2 TCC peripherals by calling \fn TCC_Create
 * - Expect that both calls return non zero values
 * - Expect that the returned handles are different
 */
TEST_F(TimerCounterControl, CreateMultiple) {
    // Body
    tcc_handle handle1 = TCC_Create(TCC0_REGS);
    tcc_handle handle2 = TCC_Create(TCC1_REGS);

    // Assertions
    EXPECT_NE(handle1, (tcc_handle)NULL);
    EXPECT_NE(handle2, (tcc_handle)NULL);
    EXPECT_NE(handle1, handle2);
    EXPECT_EQ(tcc_instance_cntr, 2);
}

/**
 * Tests whether creation of a TCC peripheral fails when creating too many
 * instances.
 * 
 * Test steps:
 * - Create \def TCC_INSTANCE_COUNT number of peripherals
 * - Call \fn TCC_Create one more time and store the handle
 * - Expect that the handle is \def NULL
 */
TEST_F(TimerCounterControl, CreateTooMany) {
    // Setup
    for (int i = 0; i < TCC_INSTANCE_COUNT; i++) {
        TCC_Create(TCC0_REGS);
    }

    // Body
    tcc_handle handle = TCC_Create(TCC0_REGS);

    // Assertions
    EXPECT_EQ(handle, (tcc_handle)NULL);
}
