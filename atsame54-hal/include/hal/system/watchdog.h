/**
 * @file watchdog.h
 * @author Balazs Eszes
 * @brief Watchdog interface
 */
#ifndef HAL_SYSTEM_WATCHDOG_H_
#define HAL_SYSTEM_WATCHDOG_H_

#include <stdbool.h>

/**
 * Watchdog timeout values
 */
typedef enum {
    CYC8 = 0x00,
    CYC16 = 0x01,
    CYC32 = 0x02,
    CYC64 = 0x03,
    CYC128 = 0x04,
    CYC256 = 0x05,
    CYC512 = 0x06,
    CYC1024 = 0x07,
    CYC2048 = 0x08,
    CYC4096 = 0x09,
    CYC8192 = 0x0A,
    CYC16384 = 0x0B
} wdt_timeout;

/**
 * Watchdog Early warning interrupt callback pointer
 */
typedef void (*wdt_ew_callback)(void);

/**
 * Watchdog Normal mode configuration
 */
typedef struct {
    bool always_on;                 /**< Watchdog state will persist across resets */
    wdt_timeout period;             /**< Watchdog period */
    wdt_timeout ew_period;          /**< Early warning period */
    wdt_ew_callback ew_callback;    /**< Early warning callback function */
} wdt_normal_configuration;

/**
 * Watchdog Window mode configuration
 */
typedef struct {
    bool always_on;         /**< Watchdog state will persist across resets */
    wdt_timeout closed;     /**< Watchdog closed window timeout */
    wdt_timeout open;       /**< Watchdog open window timeout */
    wdt_timeout ew_period;  /**< Early warning period */
    wdt_ew_callback ew_callback;      /**< Early warning callback function */
} wdt_window_configuration;

/**
 * @brief Initializes the Watchdog in normal mode
 * 
 * @param wdt_conf Pointer to Watchdog window configuration
 */
void WDT_InitializeNormal(const wdt_normal_configuration* wdt_conf);

/**
 * @brief Initializes the Watchdog in window mode
 * 
 * @param wdt_conf Pointer to Watchdog window configuration
 */
void WDT_InitializeWindow(const wdt_window_configuration* wdt_conf);

/**
 * @brief Enables the Watchdog Early Warning interrupt
 * 
 * @param handle Callback function that handles the interrupt
 */
void WDT_EnableInterrupt(wdt_ew_callback handle);

/**
 * @brief Disables the Watchdog Early Warning interrupt
 */
void WDT_DisableInterrupt(void);

/**
 * @brief Disables the Watchdog peripheral
 */
void WDT_Disable(void);

/**
 * @brief Acknowledges the Watchdog
 * 
 * In NORMAL mode this function can be called anytime
 * 
 * In WINDOWED mode this function can only be called within the Watchdog timeout
 * window, otherwise it will reset the microcontroller
 */
void WDT_Acknowledge(void);

/**
 * @brief Forces the microcontroller to self reset by writing the incorrect
 * value into the Watchdog clear register
 */
void WDT_SelfReset(void);

#endif // HAL_SYSTEM_WATCHDOG_H_
