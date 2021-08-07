#include "hal/io/gpio.h"
#include "fake_gpio.h"

#include <string.h>

bool gpio_initialized = false;

uint32_t gpio_ports[PORT_SIZE];
uint8_t pmux[PORT_SIZE * 32];

void GPIO_Reset(void) {
    gpio_initialized = false;
    memset(gpio_ports, 0, sizeof(gpio_ports));
}

void GPIO_Initialize(void) {
    gpio_initialized = true;
}

void GPIO_SetupPinStandby(uint8_t group, uint8_t pin, const gpio_pin_standby_configuration* conf) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);
}

void GPIO_SetupPinInput(uint8_t group, uint8_t pin, const gpio_pin_input_configuration* conf) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);
}

void GPIO_SetupPinOutput(uint8_t group, uint8_t pin, const gpio_pin_output_configuration* conf) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);
}

void GPIO_EnableFunction(uint8_t group, uint8_t pin, uint8_t pmux) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);
}

void GPIO_DisableFunction(uint8_t group, uint8_t pin) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);
}

uint32_t GPIO_GroupRead(uint8_t group) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);

    return gpio_ports[group];
}

gpio_state GPIO_PinRead(uint8_t group, uint8_t pin) {
    CUSTOM_ASSERT(gpio_initialized);
    CUSTOM_ASSERT(group >= 0 && group < PORT_SIZE);
    CUSTOM_ASSERT(pin >= 0 && pin < 32);

    return LOW;
}

void GPIO_GroupWrite(uint8_t group, uint32_t value) {

}

void GPIO_PinWrite(uint8_t group, uint8_t pin, gpio_state value) {

}

void GPIO_PinToggle(uint8_t group, uint8_t pin) {

}

void GPIO_GroupSet(uint8_t group, uint32_t mask) {

}

void GPIO_GroupClear(uint8_t group, uint32_t mask) {

}

void GPIO_GroupToggle(uint8_t group, uint32_t mask) {

}