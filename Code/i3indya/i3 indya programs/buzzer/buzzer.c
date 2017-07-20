#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRC = 0xff;
while(1)
{
PORTC = 0b00100000;
_delay_ms(10000000);
PORTC = 0b00000000;
_delay_ms(1000000);
PORTC = 0b00100000;
_delay_ms(10000000);
PORTC = 0b00000000;
_delay_ms(100000);
PORTC = 0b00100000;
_delay_ms(10000);
PORTC = 0b00000000;
_delay_ms(1000);
PORTC = 0b00100000;
_delay_ms(100);
PORTC = 0b00000000;
_delay_ms(10);
PORTC = 0b00100000;
_delay_ms(100);
PORTC = 0b00000000;
_delay_ms(1000);
PORTC = 0b00000000;
_delay_ms(10000);
PORTC = 0b00000000;
_delay_ms(1000000);
}
return 0;
}
