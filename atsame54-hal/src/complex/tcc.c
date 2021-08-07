/**
 * @file tcc.c
 * @author Balazs Eszes
 * @brief 
 */
#include "hal/complex/tcc.h"
#include "hal/complex/tcc_internal.h"

#include <stddef.h>

#include "device/same54p20a.h"

uint8_t tcc_instance_cntr = 0;
struct tcc_instance tcc_instances[TCC_INSTANCE_COUNT];

tcc_handle TCC_Create(volatile const tcc_registers_t* peripheral) {
    if (tcc_instance_cntr >= TCC_INSTANCE_COUNT) {
        return NULL;
    }
    tcc_instances[tcc_instance_cntr].peripheral = peripheral;

    return &tcc_instances[tcc_instance_cntr++];
}

void TCC_Initialize(const tcc_handle handle, const tcc_configuration* configuration) {
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
