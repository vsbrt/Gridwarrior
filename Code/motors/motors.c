#include<avr/io.h>
#include<util/delay.h>

int main()
{

DDRA = 0xff;
DDRD = 0xff;

while(1)
{
PORTD = 0xff;
PORTA = 0b10100000;

}
return 0;
}
