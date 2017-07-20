#include<avr/io.h>
#include<util/delay.h>

int main()
{

DDRB = 0xff;

while(1)
{
PORTB = 0b00001111;
_delay_ms(10);
PORTB = 0b0001110;
_delay_ms(100);

PORTB = 0b0001101;
_delay_ms(100);

PORTB = 0b0001011;
_delay_ms(1000);

PORTB = 0b0000111;
_delay_ms(1000);
}
return 0;
}
