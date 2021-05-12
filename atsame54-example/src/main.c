#include "xplained/board/init.h"
#include "xplained/io/user_io.h"

int main() {

    Xplained_Initialize();

    Xplained_UserLed_InitializeDigital();

    Xplained_UserButton_Initialize();

    while(1) {
        Xplained_UserLed_Set(Xplained_UserButton_Read());
    }
}
