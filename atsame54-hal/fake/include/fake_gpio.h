#if !defined(ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_)
#define ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_

#include <stddef.h>

#define PORT_SIZE 4

extern bool gpio_initialized;
extern uint32_t gpio_ports[PORT_SIZE];

void GPIO_Reset();

#endif // ATSAME54_HAL_FAKE_INCLUDE_FAKE_GPIO_H_
