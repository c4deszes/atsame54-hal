#ifndef MOCK_HAL_GPIO
#define MOCK_HAL_GPIO

#include "hal/io/gpio.h"

#include "fff.h"

DECLARE_FAKE_VOID_FUNC3(GPIO_SetupPort, uint8_t, uint8_t, uint8_t);

#endif // MOCK_HAL_GPIO
