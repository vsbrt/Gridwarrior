#include<avr/io.h>
#include<util/delay.h>
void main()
{
    DDRD=0x0F; // Make PORTD as output
	PORTD=0x0A;

	 while(1)
    {
        PORTD=0x10; // Rotate motor clockwise
        _delay_ms(2000); // delay of 2000 millisecond
        PORTD=0x20; // Rotate motor anticlockwise
        _delay_ms(2000); // delay of 2000 millisecond
}
}
