/**
 * @file eic.h
 * @author Balazs Eszes
 * @brief External Interrupt Controller interface
 */
#ifndef ATSAME54_HAL_INCLUDE_HAL_IO_EIC_H_
#define ATSAME54_HAL_INCLUDE_HAL_IO_EIC_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    GENERIC,
    LOW_POWER
} eic_clock_source;

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

typedef struct {
    eic_clock_source clock_selection;
    uint8_t gclk;
    eic_nmi_configuration nmi;
    eic_pin_configuration 
} eic_configuration;

/**
 * @brief Initializes the External Interrupt Controller
 */
void EIC_Initialize(const eic_configuration* conf);

/**
 * @brief 
 * 
 * @param pin 
 */
void EIC_EnableInterrupt(uint8_t pin);

/**
 * @brief 
 * 
 * @param pin 
 */
void EIC_DisableInterrupt(uint8_t pin);

#endif  // ATSAME54_HAL_INCLUDE_HAL_IO_EIC_H_
