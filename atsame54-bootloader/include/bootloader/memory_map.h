#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "device/same54p20a.h"

#define BOOTLOADER_FLASH_START SAME54P20_ROM_START
#define BOOTLOADER_FLASH_SIZE 0x1000
#define APPLICATION_FLASH_START (BOOTLOADER_FLASH_START + BOOTLOADER_FLASH_SIZE)
#define APPLICATION_FLASH_SIZE (SAME54P20_ROM_SIZE - BOOTLOADER_FLASH_SIZE)

extern int __bootloader_start__;
extern int __bootloader_size__;
extern int __application_start__;
extern int __application_size__;

#endif // MEMORY_MAP_H
