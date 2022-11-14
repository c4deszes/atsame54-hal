#include "bootloader/memory_map.h"

MEMORY
{
    bootloader (rx) : ORIGIN = BOOTLOADER_FLASH_START, LENGTH = BOOTLOADER_FLASH_SIZE
    application (rx): ORIGIN = APPLICATION_FLASH_START, LENGTH = APPLICATION_FLASH_SIZE
    ram (rwx): ORIGIN = 
}

__bootloader_start__ = ORIGIN(bootloader);
__bootloader_end__ = ORIGIN(bootloader) + LENGTH(bootloader)
__bootloader_size__ = LENGTH(bootloader);

__application_start__ = ORIGIN(application);
__application_end__ = ORIGIN(application) + LENGTH(application)
__application_size__ = LENGTH(application);
