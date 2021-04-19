#include "hal/complex/tcc.h"

#include "device/same54p20a.h"

void TCC_Initialize(void) {
    // select prescaler and prescaler sync
    //MCLK->MCLK_APB

    // wavegen mode, polarity
    TCC0_REGS->TCC_WAVE = TCC_WAVE_WAVEGEN(TC_WAVE_WAVEGEN_NPWM);
    TCC0_REGS->TCC_CC[2] = 0xA000;
    TCC0_REGS->TCC_PER = 0xFFFF;
    //TCC0_REGS->

    /* Enable TCC0 */
    TCC0_REGS->TCC_CTRLA |= TCC_CTRLA_ENABLE_Msk;
}
