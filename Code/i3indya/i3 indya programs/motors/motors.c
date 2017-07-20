#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRB = 0xff;

while(1)
{
PORTB = 0b00001001;//forward
_delay_ms(1000);
PORTB = 0b00000110;//backward
_delay_ms(1000);
PORTB = 0b00001000;//rigt
_delay_ms(1000);
PORTB = 0b00000010;//left
_delay_ms(1000);
}
return 0;
}
