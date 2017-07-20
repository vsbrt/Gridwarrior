#include<avr/io.h>
#include<util/delay.h>

int main()
{

DDRD = 0xff;
DDRA = 0xff;
DDRB = 0xff;
DDRC = 0xff;


while(1)
{
PORTD = 0xff
PORTA = 0b00000000;
PORTC = 0b01010101;
PORTB = 0b11110000;

}
return 0;
}
