#include "hal/complex/trng.h"

#include <stdint.h>
#include <stddef.h>
#include "device/same54p20a.h"

trng_callback trng_handle = NULL;

void TRNG_Initialize(void) {
    // Initialize the Main clock

    // Enable interrupts in NVIC
    NVIC_EnableIRQ(TRNG_IRQn);

    // Enable
    TRNG_REGS->TRNG_CTRLA = TRNG_CTRLA_ENABLE_Msk;
}

uint32_t TRNG_GetSync(void) {
    /* Wait for a new random number */
    while ((TRNG_REGS->TRNG_INTFLAG & TRNG_INTFLAG_DATARDY_Msk) == 0);

    return TRNG_REGS->TRNG_DATA;
}

void TRNG_GetAsync(trng_callback callback) {
    trng_handle = callback;

    TRNG_REGS->TRNG_INTENSET = TRNG_INTENSET_Msk;
}

void TRNG_Disable(void) {
    TRNG_REGS->TRNG_CTRLA &= ~TRNG_CTRLA_ENABLE_Msk;
    TRNG_REGS->TRNG_INTENCLR = TRNG_INTENCLR_DATARDY_Msk;
}

void TRNG_Handler(void) {
    /* Disable the interrupt and clear the interrupt flag */
    TRNG_REGS->TRNG_INTENCLR = TRNG_INTENCLR_DATARDY_Msk;
    TRNG_REGS->TRNG_INTFLAG = TRNG_INTFLAG_DATARDY_Msk;
    
    /* Call the callback function */
    if (trng_handle != NULL) {
        trng_handle(TRNG_REGS->TRNG_DATA);
    }
}
