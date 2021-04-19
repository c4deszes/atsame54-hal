/**
 * @file pdec.h
 * @author Balazs Eszes
 * @brief Position Decoder interface 
 */
#ifndef ATSAME54_HAL_INCLUDE_HAL_COMPLEX_PDEC_H_
#define ATSAME54_HAL_INCLUDE_HAL_COMPLEX_PDEC_H_

#include <stdint.h>

/**
 * Position Decoder Start Ok status
 */
#define PDEC_START_OK 0

/**
 * Position Decoder Stop Ok status
 */
#define PDEC_STOP_OK 0

/**
 * Position decoder peripheral configuration
 */
typedef struct {
    uint8_t gclk_source; /**< Position decoder peripheral clock source */
} pdec_peripheral_configuration;

/**
 * Quadrature decoder operation modes
 */
typedef enum {
    X4, /**< X4 mode : Quadrature decoder */
    X4S, /**< X4S mode: Secure Quadrature decoder */
    X2, /**< X2 mode: Decoder */
    X2S, /**< X2S mode: Secure Decoder */
    AUTOC /**< AUTOC mode: Auto correction */
} pdec_qdec_mode;

/**
 * Quadrature decoder configuration
 */
typedef struct {
    pdec_qdec_mode conf; /**< Quadrature encoder mode */
} pdec_qdec_configuration;

/**
 * Hall effect configuration
 */
typedef struct {
    uint8_t dummy; /**< Dummy member */
} pdec_hall_configuration;

/**
 * Counter configuration
 */
typedef struct {
    uint8_t dummy; /**< Dummy member */
} pdec_counter_configuration;

/**
 * @brief Initializes the position decoder in Quadrature Decoder mode
 * 
 * @param peripheral pointer to peripheral settings
 * @param qdec pointer to Quadrature decoder configuration
 */
void PDEC_QdecInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_qdec_configuration* qdec);

/**
 * @brief Initializes the position decoder in Hall Effect sensor mode
 * 
 * @param peripheral pointer to peripheral settings
 * @param hall pointer to Hall effect settings
 */
void PDEC_HallInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_hall_configuration* hall);

/**
 * @brief Initializes the position decoder in Counter mode
 * 
 * @param peripheral pointer to peripheral settings
 * @param counter pointer to Counter settings
 */
void PDEC_CounterInitialize(
    pdec_peripheral_configuration* peripheral,
    pdec_counter_configuration* counter);

/**
 * @brief Starts the position decoder
 * 
 * @return uint8_t #PDEC_START_OK if the start succeeded
 */
uint8_t PDEC_Start(void);

/**
 * @brief Stops the position decoder
 * 
 * @return uint8_t #PDEC_STOP_OK if the start succeeded
 */
uint8_t PDEC_Stop(void);

/**
 * @brief Returns the current position of the position 
 * 
 * @return uint16_t Current decoder position
 */
uint16_t PDEC_GetPosition(void);

/**
 * @brief Returns the number of revolutions since the position decoder start
 * 
 * @return uint16_t Number of revolutions
 */
uint16_t PDEC_GetRevolutions(void);

#endif  // ATSAME54_HAL_INCLUDE_HAL_COMPLEX_PDEC_H_
