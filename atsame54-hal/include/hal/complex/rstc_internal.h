#ifndef RSTC_INTERNAL_H_
#define RSTC_INTERNAL_H_

#include "hal/complex/rstc.h"
#include <stdint.h>

/**
 * @brief 
 * 
 * @param bkupexit 
 * @return rstc_cause 
 */
rstc_cause RSTC_GetBackupExitCause(uint8_t bkupexit);

#endif
