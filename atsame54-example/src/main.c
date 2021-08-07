#include "xplained/board/init.h"
#include "xplained/io/user_io.h"

#include "hal/io/gpio.h"
#include "hal/complex/trng.h"

bool button_state = false;

int main() {

    Xplained_Initialize();

    Xplained_UserLed_InitializeDigital();

    Xplained_UserButton_Initialize();

    while(1) {
        bool local_state = Xplained_UserButton_Read();
        if (local_state != button_state && button_state == true) {
            Xplained_UserLed_Toggle();
        }
        button_state = local_state;
    }
}
