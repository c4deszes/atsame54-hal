#include "hal/complex/rstc.h"
#include "hal/complex/rstc_internal.h"

#include "device/same54p20a.h"

rstc_cause RSTC_GetBackupExitCause(uint8_t bkupexit) {
    switch (bkupexit) {
        case RSTC_BKUPEXIT_HIB_Msk:
            return RSTC_CAUSE_BACKUP_HIBERNATE;
        case RSTC_BKUPEXIT_BBPS_Msk:
            return RSTC_CAUSE_BACKUP_BATTERY_POWER_SWITCH;
        case RSTC_BKUPEXIT_RTC_Msk:
            return RSTC_CAUSE_BACKUP_RTC;
        default:
            return RSTC_CAUSE_INVALID;
    }
    return RSTC_CAUSE_INVALID;
}

rstc_cause RSTC_GetCause(void) {
    uint8_t cause = RSTC_REGS->RSTC_RCAUSE;
    uint8_t bkupexit = RSTC_REGS->RSTC_BKUPEXIT;

    switch (cause) {
        case RSTC_RCAUSE_BACKUP_Msk:
            return RSTC_GetBackupExitCause(bkupexit);
        case RSTC_RCAUSE_SYST_Msk:
            return RSTC_CAUSE_SYSTEM_RESET;
        case RSTC_RCAUSE_WDT_Msk:
            return RSTC_CAUSE_WATCHDOG;
        case RSTC_RCAUSE_EXT_Msk:
            return RSTC_CAUSE_EXTERNAL;
        case RSTC_RCAUSE_NVM_Msk:
            return RSTC_CAUSE_NVM;
        case RSTC_RCAUSE_BODVDD_Msk:
            return RSTC_CAUSE_BOD33;
        case RSTC_RCAUSE_BODCORE_Msk:
            return RSTC_CAUSE_BOD12;
        case RSTC_RCAUSE_POR_Msk:
            return RSTC_CAUSE_POR;
        default:
            return RSTC_CAUSE_INVALID;
    }
    return RSTC_CAUSE_INVALID;
}
