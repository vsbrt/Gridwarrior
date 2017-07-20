
#ifndef USART_BAUDRATE 
#warning "USART_BAUDRATE is not defined"
#endif	
#define BAUD_PRESCALE ((F_CPU/(USART_BAUDRATE*16))- 1)

void usart_init();
void putch(char);
unsigned int getch();
void putstr(char*);
#include<i3indya/usart.c>
