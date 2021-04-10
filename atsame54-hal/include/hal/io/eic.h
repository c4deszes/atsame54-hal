/**
 * @file eic.h
 * @author Balazs Eszes
 * @brief External Interrupt Controller interface
 */
#ifndef HAL_IO_EIC_H_
#define HAL_IO_EIC_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    GENERIC,
    LOW_POWER
} eic_clock_selection;

typedef struct {
    uint8_t gclk;

} eic_configuration;

typedef enum {
    NONE = 0x00,
    RISE = 0x01,
    FALL = 0x02,
    BOTH = 0x03,
    HIGH = 0x04,
    LOW = 0x05
} eic_input_sense;

typedef void (*eic_callback)(void);

typedef struct {
    bool debounce;
    bool filter;
    eic_input_sense sense;
    eic_callback callback;
} eic_pin_configuration;

typedef struct {
    bool filter;
    eic_input_sense sense;
    eic_callback callback;
} eic_nmi_configuration;

/**
 * @brief Initializes the External Interrupt Controller
 */
void EIC_Initialize(void);

/**
 * @brief 
 * 
 * @param pin 
 * @param conf 
 */
void EIC_SetupPin(uint8_t pin, const eic_pin_configuration* conf);

void EIC_EnableInterrupt(uint8_t pin);

void EIC_DisableInterrupt(uint8_t pin);

#endif // HAL_IO_EIC_H_
