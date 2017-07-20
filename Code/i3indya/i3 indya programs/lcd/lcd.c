#define F_CPU 1000000
#include<avr/io.h>
#include<util/delay.h>
#include<i3indya/lcd.h>
int main()
{

lcd_init('D');
while(1)

{

lcd_gotoxy(0,0);
lcd_printstr(" ultimate  ");
lcd_clear();
}
return 0;
}
