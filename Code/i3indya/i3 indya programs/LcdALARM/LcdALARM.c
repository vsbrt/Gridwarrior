#define F_CPU 1000000
#include<avr/io.h>
#include<util/delay.h>
#include<i3indya/lcd.h>

int main()
{
lcd_init('D');
int i;

DDRC = 0xff;

while(i<15)
{

lcd_gotoxy(0,0);
lcd_printstr("TIME LEFT: ");

_delay_ms(1000);
lcd_clear();
lcd_printchar(i++);

lcd_clear();

if(i==15)
{
PORTC = 0b00100000;
_delay_ms(10);
PORTC = 0b00000000;
_delay_ms(10);
}

lcd_clear();
}
return 0;
}

