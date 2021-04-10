#include "xplained/io/pdec.h"

#include "hal/complex/pdec.h"
#include "hal/io/gpio.h"

#define PDEC_A_PORT PORT_GROUP_C
#define PDEC_A_PIN 16

#define PDEC_B_PORT PORT_GROUP_C
#define PDEC_B_PIN 17

const gpio_pin_input_configuration xplained_pdec_pin = {
    .sample = ONDEMAND,
    .pull = PULLUP
};

void Xplained_PDEC_Initialize(void) {
    GPIO_SetupPinInput(PDEC_A_PORT, PDEC_A_PIN, &xplained_pdec_pin);
    GPIO_SetupPinInput(PDEC_B_PORT, PDEC_B_PIN, &xplained_pdec_pin);
    GPIO_EnableFunction(PDEC_A_PORT, PDEC_A_PIN, 0);
    GPIO_EnableFunction(PDEC_B_PORT, PDEC_B_PIN, 0);
}
