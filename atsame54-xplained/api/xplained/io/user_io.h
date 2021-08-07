/**
 * @file user_io.h
 * @author Balazs Eszes
 * @brief User peripheral support
 */
#ifndef ATSAME54_XPLAINED_INCLUDE_XPLAINED_IO_USER_IO_H_
#define ATSAME54_XPLAINED_INCLUDE_XPLAINED_IO_USER_IO_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the user LED in digital mode (On / Off)
 */
void Xplained_UserLed_InitializeDigital(void);

/**
 * @brief Initializes the user LED in analog mode (0-100% duty)
 */
void Xplained_UserLed_InitializePwm(void);

/**
 * @brief Turns on the user LED
 */
void Xplained_UserLed_On(void);

/**
 * @brief Turns off the user LED
 */
void Xplained_UserLed_Off(void);

/**
 * @brief Toggles the user LED
 */
void Xplained_UserLed_Toggle(void);

/**
 * @brief Sets the user LED state
 * @param enabled if true the user LED will be turned on, else the user LED will
 * be turned off
 */
void Xplained_UserLed_Set(bool enabled);

/**
 * @brief Initializes the user button present on the board
 */
void Xplained_UserButton_Initialize(void);

/**
 * @brief Returns the user button state
 * 
 * @return true if the user button is pressed, false otherwise
 */
bool Xplained_UserButton_Read(void);

#endif  // ATSAME54_XPLAINED_INCLUDE_XPLAINED_IO_USER_IO_H_
