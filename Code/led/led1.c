#include<avr/io.h>
#include<util/delay.h>

int main()
{

DDRD = 0xff;

while(1)
{
PORTD = 0b11110000;

}
return 0;
}
