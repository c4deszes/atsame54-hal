#include "xplained/io/user_io.h"

#include "unity.h"

#include "mock/hal/mock_gpio.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/**
 * Tests whether the IO initialization functions call the BSW correctly
 */
void test_IoInitialization(void) {
    
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_IoInitialization);
    return UNITY_END();
}
