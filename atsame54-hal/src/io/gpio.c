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

void GPIO_SetupPinStandby(uint8_t group, uint8_t pin, const gpio_pin_standby_configuration* conf) {
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

void GPIO_SetupPinInput(uint8_t group, uint8_t pin, const gpio_pin_input_configuration* conf) {
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

void GPIO_SetupPinOutput(uint8_t group, uint8_t pin, const gpio_pin_output_configuration* conf) {
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

void GPIO_EnableFunction(uint8_t group, uint8_t pin, uint8_t pmux) {
    if (pin % 2 == 0) {
        PORT_REGS->GROUP[group].PORT_PMUX[pin / 2] = (PORT_REGS->GROUP[group].PORT_PMUX[pin / 2] & (0xF0)) | (pmux & 0x0F);
    } else {
        PORT_REGS->GROUP[group].PORT_PMUX[pin / 2] = (PORT_REGS->GROUP[group].PORT_PMUX[pin / 2] & (0x0F)) | (pmux << 4 & 0xF0);
    }
    PORT_REGS->GROUP[group].PORT_PINCFG[pin] |= PORT_PINCFG_PMUXEN_Msk;
}

void GPIO_DisableFunction(uint8_t group, uint8_t pin) {
    PORT_REGS->GROUP[group].PORT_PINCFG[pin] &= ~((uint8_t)PORT_PINCFG_PMUXEN_Msk);
}

uint32_t GPIO_GroupRead(uint8_t group) {
    return PORT_REGS->GROUP[group].PORT_IN;
}

gpio_state GPIO_PinRead(uint8_t group, uint8_t pin) {
    return PORT_REGS->GROUP[group].PORT_IN & (1 << pin) ? HIGH : LOW;
}

void GPIO_GroupWrite(uint8_t group, uint32_t value) {
    PORT_REGS->GROUP[group].PORT_OUT = value;
}

void GPIO_PinWrite(uint8_t group, uint8_t pin, gpio_state value) {
    if (value == LOW) {
        GPIO_GroupClear(group, (1 << pin));
    } else if (value == HIGH) {
        GPIO_GroupSet(group, (1 << pin));
    }
}

void GPIO_PinToggle(uint8_t group, uint8_t pin) {
    GPIO_GroupToggle(group, (1 << pin));
}

void GPIO_GroupSet(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTSET = mask;
}

void GPIO_GroupClear(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTCLR = mask;
}

void GPIO_GroupToggle(uint8_t group, uint32_t mask) {
    PORT_REGS->GROUP[group].PORT_OUTTGL = mask;
}
