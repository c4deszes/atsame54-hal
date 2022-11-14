#include "xplained/board/init.h"
#include "xplained/io/user_io.h"

#include "app/main.h"

bool button_state = false;

void setup(void) {
    Xplained_Initialize();

    /* */
    Xplained_UserLed_InitializeDigital();
    Xplained_UserButton_Initialize();
}

void loop(void) {
    bool local_state = Xplained_UserButton_Read();
    if (local_state != button_state && button_state == true) {
        Xplained_UserLed_Toggle();
    }
    button_state = local_state;
}

int main(void) {
    setup();

    while (1) {
        loop();
    }

    return 0;
}
