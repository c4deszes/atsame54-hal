#include <stdio.h>

#ifdef __arm__
/* Declaration of these functions are missing in stdio.h for ARM parts*/
int _mon_getc(int canblock);
void _mon_putc(char c);
#endif //__arm__

int _mon_getc(int canblock)
{
   volatile int c = 0;
   while(SERCOM4_USART_Read((void*)&c, 1) != true);
   return c;
}

void _mon_putc(char c)
{
   uint8_t size = 0;
   do
   {
       size = SERCOM4_USART_Write((void*)&c, 1);
   }while (size != 1);
}