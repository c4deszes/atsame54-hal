#ifndef TEST_USER_IO_H_
#define TEST_USER_IO_H_

extern void test_UserLedShouldInitializeCorrectlyInDigitalMode(void);

extern void test_UserLedShouldInitializeCorrectlyInPwmMode(void);

extern void test_UserLedShouldTurnOnTheCorrectPin(void);

extern void test_UserLedShouldTurnOffTheCorrectPin(void);

extern void test_UserButtonShouldInitializeCorrectly(void);

extern void test_UserButtonReadShouldReturnTrueWhenPinIsHigh(void);

extern void test_UserButtonReadShouldReturnFalseWhenPinIsLow(void);

#endif // TEST_USER_IO_H_
