/**
 * @file eic.c
 * @author Balazs Eszes
 * @brief External Interrupt Controller implementation
 */
#include "hal/io/eic.h"

#include "device/same54p20a.h"

eic_callback eic_handles[16];

eic_callback nmi_handle;

void EIC_Initialize(const eic_configuration* conf) {
    /* Enable Main clock for EIC */
    MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_EIC_Msk;

    /* Enable peripheral clock for EIC */
    EIC_REGS->EIC_CTRLA = EIC_CTRLA_CKSEL_Msk;

    /* Load pin settings */
    //EIC_REGS->EIC_CONFIG[0] = EIC_CONFIG_FILTEN0();

    /* Enable External Interrupt Controller */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

    while ((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) == EIC_SYNCBUSY_ENABLE_Msk) {
        /* Wait for sync */
    }
}

void EIC_EnableInterrupt(uint8_t pin) {
    EIC_REGS->EIC_INTENSET = (1 << pin);
}

void EIC_DisableInterrupt(uint8_t pin) {
    EIC_REGS->EIC_INTENCLR = (1 << pin);
}

void NonMaskableInt_Handler(void) {
    EIC_REGS->EIC_NMIFLAG = EIC_NMIFLAG_NMI_Msk;
}

#define EIC_EXTINT_HANDLER(INDEX) \
    void EIC_EXTINT_##INDEX##_Handler(void) { \
        EIC_REGS->EIC_INTFLAG = (1 << INDEX); \
    }

EIC_EXTINT_HANDLER(0)
EIC_EXTINT_HANDLER(1)
EIC_EXTINT_HANDLER(2)
EIC_EXTINT_HANDLER(3)
EIC_EXTINT_HANDLER(4)
EIC_EXTINT_HANDLER(5)
EIC_EXTINT_HANDLER(6)
EIC_EXTINT_HANDLER(7)
