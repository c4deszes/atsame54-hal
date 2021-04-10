/**
 * @file eic.c
 * @author Balazs Eszes
 * @brief External Interrupt Controller implementation
 */
#include "hal/io/eic.h"

#include "device/same54p20a.h"

eic_callback eic_handles[16];

void EIC_Initialize(void) {
    EIC_REGS->EIC_CTRLA;

    /* Enable External Interrupt Controller */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

    while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) == EIC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for sync */
    }
}

void EIC_SetupPin(uint8_t pin, const eic_pin_configuration* conf) {
    EIC_REGS->EIC_INTENSET;
}

void NonMaskableInt_Handler(void) {
    EIC_REGS->EIC_NMIFLAG = EIC_NMIFLAG_NMI_Msk;


}

void EIC_EXTINT_0_Handler(void) {
    EIC_REGS->EIC_INTFLAG = (1 << 0);
}

void EIC_EXTINT_1_Handler(void) {

}

void EIC_EXTINT_2_Handler(void) {

}

void EIC_EXTINT_3_Handler(void) {

}
