#ifndef HAL_COMPLEX_TRNG_H_
#define HAL_COMPLEX_TRNG_H_

#include <stdint.h>

typedef void (*trng_callback)(uint32_t);

/**
 * @brief Initializes the True Random Number Generator peripheral
 */
void TRNG_Initialize(void);

/**
 * @brief Returns a random number generated by the True Random Number Generator peripheral
 * 
 * @return uint32_t Generated random number
 */
uint32_t TRNG_GetSync(void);

/**
 * @brief 
 * 
 * @param callback 
 */
void TRNG_GetAsync(trng_callback callback);

/**
 * @brief Disables the True Random Number Generator peripheral
 */
void TRNG_Disable(void);

#endif
