/**
 * @file pdec.c
 * @author Balazs Eszes
 * @brief Position Decoder implementation
 */
#include "hal/complex/pdec.h"

#include "device/same54p20a.h"

void PDEC_ClockInitialize(uint8_t gclk) {
    // Enable generic clock for the PDEC peripheral
    GCLK_REGS->GCLK_PCHCTRL[GCLK_PDEC] =  GCLK_PCHCTRL_GEN(gclk)
                                        | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[GCLK_PDEC] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk) {
        /* Wait for synchronization */
    }

    // Enable peripheral clock for the PDEC peripheral
    MCLK_REGS->MCLK_APBCMASK |= MCLK_APBCMASK_PDEC_Msk;
}

void PDEC_QdecInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_qdec_configuration* qdec_conf) {

    PDEC_ClockInitialize(peripheral->gclk_source);

    PDEC_REGS->PDEC_CTRLA =
                      PDEC_CTRLA_MODE_QDEC
                    | PDEC_CTRLA_CONF_X4
                    | PDEC_CTRLA_PINEN(0x3)
                    | PDEC_CTRLA_PINVEN(0x0)
                    | PDEC_CTRLA_ANGULAR(0x07)
                    | PDEC_CTRLA_MAXCMP(4);
    PDEC_REGS->PDEC_PRESC = PDEC_PRESC_PRESC_DIV1;
    PDEC_REGS->PDEC_FILTER = PDEC_FILTER_FILTER(0);
    PDEC_REGS->PDEC_CC[0] = 32;

    // Enable PDEC
    PDEC_REGS->PDEC_CTRLA |= PDEC_CTRLA_ENABLE_Msk;
}

void PDEC_HallInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_hall_configuration* hall_conf) {

    PDEC_ClockInitialize(peripheral->gclk_source);
}

void PDEC_CounterInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_counter_configuration* counter_conf) {

    PDEC_ClockInitialize(peripheral->gclk_source);
}

uint8_t PDEC_Start() {
    // TODO(Balazs Eszes): detect if already started
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_START;

    // TODO(Balazs Eszes): detect start failure
    return 0;
}

uint8_t PDEC_Stop() {
    return 0;
}

uint32_t PDEC_GetCount() {
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_READSYNC;
    while (PDEC_REGS->PDEC_SYNCBUSY) {
        /* Wait for read Synchronization */
    }
    while ((PDEC_REGS->PDEC_CTRLBSET & PDEC_CTRLBSET_CMD_Msk) != PDEC_CTRLBSET_CMD_NONE) {
        /* Wait for CMD to become zero */
    }
    return PDEC_REGS->PDEC_COUNT;
}
