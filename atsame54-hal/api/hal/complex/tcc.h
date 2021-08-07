#ifndef ATSAME54_HAL_INCLUDE_HAL_COMPLEX_TCC_H_
#define ATSAME54_HAL_INCLUDE_HAL_COMPLEX_TCC_H_

#include "device/same54p20a.h"

#include <stdint.h>

typedef enum {
    DIV1 = 0x01
} tcc_prescaler;

typedef struct {
    tcc_prescaler prescaler;
} tcc_configuration;

typedef struct tcc_instance* tcc_handle;

/**
 * @brief Creates 
 * 
 * @param peripheral 
 * @return tcc_handle 
 */
tcc_handle TCC_Create(volatile const tcc_registers_t* peripheral);

/**
 * @brief 
 * 
 * @param handle 
 * @param configuration 
 */
void TCC_Initialize(const tcc_handle handle, const tcc_configuration* configuration);

/**
 * @brief 
 * 
 * @param handle 
 */
void TCC_Start(const tcc_handle handle);

/**
 * @brief 
 * 
 * @param handle 
 */
void TCC_Stop(const tcc_handle handle);

/**
 * @brief 
 * 
 * @param handle 
 * @param period 
 */
void TCC_SetPeriod(const tcc_handle handle, const uint32_t period);

/**
 * @brief 
 * 
 * @param handle 
 * @param channel 
 */
void TCC_SetDuty(const tcc_handle handle, const uint8_t channel);

#endif  //ATSAME54_HAL_INCLUDE_HAL_COMPLEX_TCC_H_
