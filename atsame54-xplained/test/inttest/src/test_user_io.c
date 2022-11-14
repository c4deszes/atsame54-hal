#include "xplained/io/user_io.h"
#include "hal/io/gpio.h"

#include "unity.h"

/**
 * @brief Tests 
 * 
 */
void test_UserLedShouldInitializeCorrectlyInDigitalMode(void) {
    Xplained_UserLed_InitializeDigital();
}

void test_UserLedShouldInitializeCorrectlyInPwmMode(void) {
    Xplained_UserLed_InitializePwm();
}

void test_UserLedShouldTurnOnTheCorrectPin(void) {
    Xplained_UserLed_On();
}

void test_UserLedShouldTurnOffTheCorrectPin(void) {
    Xplained_UserLed_Off();
}

void test_UserButtonShouldInitializeCorrectly(void) {
    Xplained_UserButton_Initialize();
}

void test_UserButtonReadShouldReturnTrueWhenPinIsHigh(void) {

}

void test_UserButtonReadShouldReturnFalseWhenPinIsLow(void) {

}
