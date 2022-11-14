/**
 * @file test_rstc.cpp
 * @author Balazs Eszes
 * @brief 
 * 
 * @copyright Copyright (c) 2021
 */
#include <tuple>
#include "gtest/gtest.h"
#include "gtest_util/gtest_util.h"

extern "C" {
    #include "hal/complex/rstc.h"
    #include "hal/complex/rstc_internal.h"
    #include "device/same54p20a.h"
}

/**
 * @brief ResetController test fixture
 */
class ResetController : public testing::TestWithParam<std::tuple<uint8_t, uint8_t, rstc_cause>> {
protected:
    /**
     * @brief Resets the ResetController peripheral
     */
    void SetUp() override {
        RSTC_REGS->RSTC_RCAUSE = 0;
        RSTC_REGS->RSTC_BKUPEXIT = RSTC_BKUPEXIT_RESETVALUE;
    }
};

/**
 * Tests whether the reset cause is determined correctly
 * 
 * Test steps:
 * - Set RCAUSE and BKUPEXIT registers
 * - Expect RSTC_Cause to return the correct cause
 */
TEST_P(ResetController, GetCauseShouldReturnCorrect) {
    RSTC_REGS->RSTC_RCAUSE = std::get<0>(GetParam());
    RSTC_REGS->RSTC_BKUPEXIT = std::get<1>(GetParam());
    rstc_cause expected = std::get<2>(GetParam());

    EXPECT_EQ(expected, RSTC_GetCause());
}

INSTANTIATE_TEST_CASE_P(
    ,
    ResetController,
    ::testing::Values(
        std::make_tuple(RSTC_RCAUSE_BACKUP_Msk, RSTC_BKUPEXIT_HIB_Msk, RSTC_CAUSE_BACKUP_HIBERNATE),
        std::make_tuple(RSTC_RCAUSE_BACKUP_Msk, RSTC_BKUPEXIT_BBPS_Msk, RSTC_CAUSE_BACKUP_BATTERY_POWER_SWITCH),
        std::make_tuple(RSTC_RCAUSE_BACKUP_Msk, RSTC_BKUPEXIT_RTC_Msk, RSTC_CAUSE_BACKUP_RTC),
        std::make_tuple(RSTC_RCAUSE_BACKUP_Msk, 0, RSTC_CAUSE_INVALID),
        std::make_tuple(RSTC_RCAUSE_BACKUP_Msk, 0xFF, RSTC_CAUSE_INVALID),
        std::make_tuple(RSTC_RCAUSE_SYST_Msk, 0, RSTC_CAUSE_SYSTEM_RESET),
        std::make_tuple(RSTC_RCAUSE_WDT_Msk, 0, RSTC_CAUSE_WATCHDOG),
        std::make_tuple(RSTC_RCAUSE_EXT_Msk, 0, RSTC_CAUSE_EXTERNAL),
        std::make_tuple(RSTC_RCAUSE_NVM_Msk, 0, RSTC_CAUSE_NVM),
        std::make_tuple(RSTC_RCAUSE_BODVDD_Msk, 0, RSTC_CAUSE_BOD33),
        std::make_tuple(RSTC_RCAUSE_BODCORE_Msk, 0, RSTC_CAUSE_BOD12),
        std::make_tuple(RSTC_RCAUSE_POR_Msk, 0, RSTC_CAUSE_POR),
        std::make_tuple(0, 0, RSTC_CAUSE_INVALID),
        std::make_tuple(0xFF, 0, RSTC_CAUSE_INVALID)
    )
);
