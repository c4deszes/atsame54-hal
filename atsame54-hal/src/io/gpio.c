/**
 * @file gpio.c
 * @author Balazs Eszes
 * @brief General Purpose Input Output abstraction
 */
#include "hal/io/gpio.h"

#include "device/same54p20a.h"

void GPIO_Initialize(void) {
    /* Enable MCLK for PORT */
    MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;
}

inline void GPIO_SetupPinStandby(uint8_t group, uint8_t pin, const gpio_pin_standby_configuration* conf) {
    uint32_t pin_mask = (1 << pin);
    uint8_t pin_cfg = 0;

    if (conf->pull != FLOATING) {
        pin_cfg |= PORT_PINCFG_PULLEN_Msk;
    }

    if (conf->pull == PULLUP) {
        PORT_REGS->GROUP[group].PORT_OUTSET = pin_mask;
    } else if (conf->pull == PULLDOWN) {
        PORT_REGS->GROUP[group].PORT_OUTCLR = pin_mask;
    }

    PORT_REGS->GROUP[group].PORT_PINCFG[pin] = pin_cfg;
    PORT_REGS->GROUP[group].PORT_DIRCLR = pin_mask;
}

inline void GPIO_SetupPinInput(uint8_t group, uint8_t pin, const gpio_pin_input_configuration* conf) {
    uint32_t pin_mask = (1 << pin);
    uint8_t pin_cfg = PORT_PINCFG_INEN_Msk;

    if (conf->pull != FLOATING) {
        pin_cfg |= PORT_PINCFG_PULLEN_Msk;
    }

    if (conf->pull == PULLUP) {
        PORT_REGS->GROUP[group].PORT_OUTSET = pin_mask;
    } else if (conf->pull == PULLDOWN) {
        PORT_REGS->GROUP[group].PORT_OUTCLR = pin_mask;
    }

    PORT_REGS->GROUP[group].PORT_PINCFG[pin] = pin_cfg;
    PORT_REGS->GROUP[group].PORT_DIRCLR = pin_mask;
}

inline void GPIO_SetupPinOutput(uint8_t group, uint8_t pin, const gpio_pin_output_configuration* conf) {
    uint32_t pin_mask = (1 << pin);
    uint8_t pin_cfg = 0;

    if (conf->input) {
        pin_cfg = PORT_PINCFG_INEN_Msk;
    } else {
        pin_cfg = 0;
    }

    PORT_REGS->GROUP[group].PORT_PINCFG[pin] = pin_cfg;
    PORT_REGS->GROUP[group].PORT_DIRSET = pin_mask;
}

inline void GPIO_EnableFunction(uint8_t group, uint8_t pin, uint8_t pmux) {
    PORT_REGS->GROUP[group].PORT_PMUX[pmux / 2] = 0;
    PORT_REGS->GROUP[group].PORT_PINCFG[pin] |= PORT_PINCFG_PMUXEN_Msk;
}

inline void GPIO_DisableFunction(uint8_t group, uint8_t pin) {
    PORT_REGS->GROUP[group].PORT_PINCFG[pin] &= ~((uint8_t)PORT_PINCFG_PMUXEN_Msk);
}

inline uint32_t GPIO_GroupRead(uint8_t group) {
    return PORT_REGS->GROUP[group].PORT_IN;
}

inline gpio_state GPIO_PinRead(uint8_t group, uint8_t pin) {
    return PORT_REGS->GROUP[group].PORT_IN & (1 << pin) ? HIGH : LOW;
}

inline void GPIO_GroupWrite(uint8_t group, uint32_t value) {
    PORT_REGS->GROUP[group].PORT_OUT = value;
}

inline void GPIO_PinWrite(uint8_t group, uint8_t pin, gpio_state value) {
    if (value == LOW) {
        GPIO_GroupClear(group, (1 << pin));
    }
    else if (value == HIGH) {
        GPIO_GroupSet(group, (1 << pin));
    }
}

inline void GPIO_GroupSet(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTSET = mask;
}

inline void GPIO_GroupClear(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTCLR = mask;
}

inline void GPIO_GroupToggle(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTTGL = mask;
}
