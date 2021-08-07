#ifndef RSTC_H_
#define RSTC_H_

typedef enum {
    RSTC_CAUSE_INVALID,
    RSTC_CAUSE_BACKUP_HIBERNATE,
    RSTC_CAUSE_BACKUP_BATTERY_POWER_SWITCH,
    RSTC_CAUSE_BACKUP_RTC,
    RSTC_CAUSE_SYSTEM_RESET,                        /**< Cortex System reset */
    RSTC_CAUSE_WATCHDOG,                            /**< Watchdog reset */
    RSTC_CAUSE_EXTERNAL,                            /**< External reset */
    RSTC_CAUSE_NVM,
    RSTC_CAUSE_BOD33,
    RSTC_CAUSE_BOD12,
    RSTC_CAUSE_POR
} rstc_cause;

/**
 * @brief Returns the reset cause
 * 
 * @return rstc_cause Reset cause
 */
extern rstc_cause RSTC_GetCause(void);

#endif
