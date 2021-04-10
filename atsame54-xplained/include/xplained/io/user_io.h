#ifndef ATSAME54_XPLAINED_INCLUDE_IO_H_
#define ATSAME54_XPLAINED_INCLUDE_IO_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the user LED present on the board
 */
void Xplained_UserLed_InitializeDigital(void);

void Xplained_UserLed_InitializePwm(void);

/**
 * @brief Toggles the user LED
 * 
 */
void Xplained_UserLed_Toggle(void);

/**
 * @brief Turns on the user LED
 */
void Xplained_UserLed_On(void);

/**
 * @brief Turns off the user LED
 */
void Xplained_UserLed_Off(void);

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
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Xplained_UserButton_Read(void);

#endif // ATSAME54_XPLAINED_INCLUDE_IO_H_
