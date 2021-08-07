/**
 * @file gpio.h
 * @author Balazs Eszes
 * @brief General Purpose Input Output interface
 */
#ifndef ATSAME54_HAL_INCLUDE_HAL_IO_GPIO_H_
#define ATSAME54_HAL_INCLUDE_HAL_IO_GPIO_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * Port A group number
 */
#define PORT_GROUP_A 0

/**
 * Port B group number
 */
#define PORT_GROUP_B 1

/**
 * Port C group number
 */
#define PORT_GROUP_C 2

/**
 * Port D group number
 */
#define PORT_GROUP_D 3

typedef enum {
    LOW,
    HIGH
} gpio_state;

/**
 * Input pullup mode
 */
typedef enum {
    FLOATING,   /**< No pull-up or pull-down is configured, pin is floating */
    PULLUP,     /**< Pull-up resistor is enabled*/
    PULLDOWN    /**< Pull-down resistor is enabled*/
} gpio_pin_pull_mode;

/**
 * Output drive strength
 */
typedef enum {
    NORMAL,     /**< Normal output drive */
    STRONG      /**< Strong output drive */
} gpio_pin_drive_strength;

/**
 * Input sampling mode
 */
typedef enum {
    ONDEMAND,   /**< Input bit is only updated when requested */
    CONTINUOUS  /**< Input bit is updated continuously */
} gpio_pin_sample_mode;

/**
 * Pin configuration for non configured pins
 */
typedef struct {
    gpio_pin_pull_mode pull;    /**< Pull configuration */
} gpio_pin_standby_configuration;

/**
 * Pin configuration for inputs
 */
typedef struct {
    gpio_pin_pull_mode pull;
    gpio_pin_sample_mode sample;
} gpio_pin_input_configuration;

/**
 * Pin configuration for outputs
 */
typedef struct {
    bool input;
    gpio_pin_drive_strength drive;
} gpio_pin_output_configuration;

/**
 * @brief Initializes the GPIO peripheral
 */
void GPIO_Initialize(void);

/**
 * @brief Configures the pin for standby operation, meaning that the pin is
 * not used as an input or as an output.
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @param conf Pointer to standby configuration
 */
void GPIO_SetupPinStandby(uint8_t group, uint8_t pin, const gpio_pin_standby_configuration* conf);

/**
 * @brief Configures the pin for input operation
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @param conf Pointer to input configuration
 */
void GPIO_SetupPinInput(uint8_t group, uint8_t pin, const gpio_pin_input_configuration* conf);

/**
 * @brief Configures the pin for output operation
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @param conf Pointer to output configuration
 */
void GPIO_SetupPinOutput(uint8_t group, uint8_t pin, const gpio_pin_output_configuration* conf);

/**
 * @brief Sets the function of the given pin
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @param pmux 
 */
void GPIO_EnableFunction(uint8_t group, uint8_t pin, uint8_t pmux);

/**
 * @brief Disable the function of the given pin
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 */
void GPIO_DisableFunction(uint8_t group, uint8_t pin);

/**
 * @brief Returns the state of the input of the given port group
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @return uint32_t 
 */
uint32_t GPIO_GroupRead(uint8_t group);

/**
 * @brief Returns the state of the input of the given pin
 * 
 * @param group Port group number, eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @return gpio_state HIGH if the input is high, LOW if the input is low
 */
gpio_state GPIO_PinRead(uint8_t group, uint8_t pin);

/**
 * @brief Sets the port registers of the group to the given value
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param value Value to write
 */
void GPIO_GroupWrite(uint8_t group, uint32_t value);

/**
 * @brief Sets the output state of the given pin
 * 
 * @param group Port group number, eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 * @param value Value to write, if the value is HIGH the output will
 * be enabled, if the value is LOW the output will be disabled
 */
void GPIO_PinWrite(uint8_t group, uint8_t pin, gpio_state value);

/**
 * @brief Toggle the output state of the given pin
 * 
 * @param group Port group number, eg. #PORT_GROUP_A
 * @param pin Pin number, eg. 12
 */
void GPIO_PinToggle(uint8_t group, uint8_t pin);

/**
 * @brief Sets the port registers of the group with the given mask
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param mask Mask of the pins to toggle eg. #PORT_PA12 or 0xf0000000
 */
void GPIO_GroupSet(uint8_t group, uint32_t mask);

/**
 * @brief Clears the port registers of the group with the given mask
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param mask Mask of the pins to toggle eg. #PORT_PA12 or 0xf0000000
 */
void GPIO_GroupClear(uint8_t group, uint32_t mask);

/**
 * @brief Toggles the port registers of the group with the given mask
 * 
 * @param group Port group number eg. #PORT_GROUP_A
 * @param mask Mask of the pins to toggle eg. #PORT_PA12 or 0xf0000000
 */
void GPIO_GroupToggle(uint8_t group, uint32_t mask);

#endif  // ATSAME54_HAL_INCLUDE_HAL_IO_GPIO_H_
