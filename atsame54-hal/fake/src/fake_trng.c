#include "fake_trng.h"
#include "hal/complex/trng.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

bool trng_initialized = false;
uint32_t trng_data = 0;

void TRNG_Initialize(void) {
    srand(time(0));
    
    trng_initialized = true;
}

uint32_t TRNG_GetSync(void) {
    if (trng_initialized) {
        trng_data = rand();
    }
    return trng_data;
}

void TRNG_GetAsync(trng_callback callback) {
    
}

void TRNG_Disable(void) {
    trng_initialized = false;
}
