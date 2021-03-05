#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include <stdint.h>

#define PORT_GROUP_A 0
#define PORT_GROUP_B 1
#define PORT_GROUP_C 2
#define PORT_GROUP_D 3

// Setup
void GPIO_SetupPort(uint8_t group, uint8_t pin, uint8_t dir, uint8_t out);
void GPIO_SetupFunction(uint8_t group, uint8_t pin, uint8_t pincfg, uint8_t pmux);

// Input
uint32_t GPIO_GroupRead(uint8_t group);

// Output / Pullup
void GPIO_GroupWrite(uint8_t group, uint32_t mask);
void GPIO_GroupSet(uint8_t group, uint32_t mask);
void GPIO_GroupClear(uint8_t group, uint32_t mask);
void GPIO_GroupToggle(uint8_t group, uint32_t mask);

#endif
