/**
 * @file mcu.c
 * @author Balazs Eszes
 * @brief Microcontroller system level functions
 */
#include "hal/system/mcu.h"

#include "device/system_same54.h"

void MCU_Initialize() {
    SystemInit();
}
