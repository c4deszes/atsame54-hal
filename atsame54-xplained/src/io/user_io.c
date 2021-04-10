#include "xplained/io/user_io.h"

#include "hal/io/gpio.h"

#define LED0_PORT PORT_GROUP_C
#define LED0_PIN 18

#define SW0_PORT PORT_GROUP_B
#define SW0_PIN 31

/**
 * @brief User LED0 configuration
 */
const gpio_pin_output_configuration led0 = {
    .input = false,
    .drive = NORMAL
};

/**
 * @brief User Switch0 configuration
 */
const gpio_pin_input_configuration sw0 = {
    .sample = CONTINUOUS,
    .pull = PULLUP
};

void Xplained_UserLed_InitializeDigital(void) {
    GPIO_SetupPinOutput(LED0_PORT, LED0_PIN, &led0);
}

void Xplained_UserLed_Set(bool enabled) {
    GPIO_PinWrite(LED0_PIN, LED0_PIN, enabled ? HIGH : LOW);
}

void Xplained_UserButton_Initialize(void) {
    GPIO_SetupPinInput(SW0_PORT, SW0_PIN, &sw0);
}

bool Xplained_UserButton_Read(void) {
    return GPIO_PinRead(SW0_PORT, SW0_PIN) == HIGH ? true : false;
}
