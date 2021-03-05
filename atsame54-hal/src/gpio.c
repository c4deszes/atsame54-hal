#include "hal/gpio.h"

#include "device/system_same54.h"
#include "device/same54p20a.h"
#include "device/ports.h"

/**
 * @brief 
 * 
 * @param group 
 * @param pin 
 * @param dir 
 * @param out 
 */
void GPIO_SetupPort(uint8_t group, uint8_t pin, uint8_t dir, uint8_t out) {

}

/**
 * @brief 
 * 
 * @param group 
 * @param pin 
 * @param pincfg 
 * @param pmux 
 */
void GPIO_SetupFunction(uint8_t group, uint8_t pin, uint8_t pincfg, uint8_t pmux) {

}

/**
 * @brief 
 * 
 * @param group 
 * @return uint32_t 
 */
uint32_t GPIO_GroupRead(uint8_t group) {
    return 0;
}

/**
 * @brief 
 * 
 * @param group 
 * @param value 
 */
void GPIO_GroupWrite(uint8_t group, uint32_t value) {
    
}

/**
 * @brief 
 * 
 * @param group 
 * @param mask 
 */
void GPIO_GroupSet(uint8_t group, uint32_t mask) {

}

/**
 * @brief 
 * 
 * @param group 
 * @param mask 
 */
void GPIO_GroupClear(uint8_t group, uint32_t mask) {
    
}

/**
 * @brief 
 * 
 * @param group 
 * @param mask 
 */
void GPIO_GroupToggle(uint8_t group, uint32_t mask) {

}
