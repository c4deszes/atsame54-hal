/**
 * @file clock.c
 * @author Balazs Eszes
 * @brief 
 */

#include "device/same54p20a.h"

void OSCCTRL_Initialize(void) {
    /****************** XOSC0 Initialization   ********************************/

    /* Configure External Oscillator */
    OSCCTRL_REGS->OSCCTRL_XOSCCTRL[0] = 
                  OSCCTRL_XOSCCTRL_STARTUP(0)
                | OSCCTRL_XOSCCTRL_IMULT(4)
                | OSCCTRL_XOSCCTRL_IPTAT(3)
                | OSCCTRL_XOSCCTRL_XTALEN_Msk
                | OSCCTRL_XOSCCTRL_ENABLE_Msk;
    while ((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_XOSCRDY0_Msk) != OSCCTRL_STATUS_XOSCRDY0_Msk)
    {
        /* Waiting for the XOSC Ready state */
    }
}
