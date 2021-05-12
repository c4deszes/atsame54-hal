#include "xplained/board/init.h"

#include "hal/system/mcu.h"

#include "hal/io/gpio.h"

void Xplained_Initialize(void) {
    MCU_Initialize();

    GPIO_Initialize();
}
