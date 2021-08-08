#if !defined(ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_)
#define ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_

#include <stddef.h>

#define PORT_SIZE 4

extern bool gpio_initialized;
extern uint32_t gpio_ports[PORT_SIZE];

/**
 * @brief Resets the GPIO peripheral
 */
void GPIO_FakeReset();

/**
 * @brief 
 * 
 * @param group 
 * @param pin 
 * @param state 
 */
void GPIO_FakeSetState(uint8_t group, uint8_t pin, gpio_state state);

#endif // ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_
