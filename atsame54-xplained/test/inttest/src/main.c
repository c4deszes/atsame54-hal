#include "unity.h"

#include "test_user_io.h"

void setUp(void) {
    // set stuff up here
    //GPIO_Initialize();
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_UserLedShouldInitializeCorrectlyInDigitalMode);
    RUN_TEST(test_UserLedShouldInitializeCorrectlyInPwmMode);
    RUN_TEST(test_UserLedShouldTurnOnTheCorrectPin);
    RUN_TEST(test_UserLedShouldTurnOffTheCorrectPin);
    RUN_TEST(test_UserButtonShouldInitializeCorrectly);
    RUN_TEST(test_UserButtonReadShouldReturnTrueWhenPinIsHigh);
    RUN_TEST(test_UserButtonReadShouldReturnFalseWhenPinIsLow);
    return UNITY_END();
}
