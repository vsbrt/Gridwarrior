#include<avr/io.h>
#include<util/delay.h>
int main()
{
unsigned int a;
DDRA=0x00;
DDRD=0xFF;
DDRC=0xff;
PORTD = 0xff;
while(1)
{
a=PINA & 0b00000011;

if(a==0b00000011)
{PORTC=0b10101010;}

if(a==0b00000000)
{PORTC=0b01010101;}
}
return 0;
}	


