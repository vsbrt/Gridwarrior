/*****************************************************
Project : Gridwarrior
Version : 3.8
Date : 07-01-2013
Author : vsbrt
Chip type : ATmega16
Program type : Application
Clock frequency : 8.000000 MHz
Memory model : Small
External SRAM size : 0
Data Stack size : 256
*****************************************************/
#include <mega16.h>
#include <delay.h>
#include <stdlib.h>
// Alphanumeric LCD Module functions
#asm
.equ __lcd_port=0x15 ;PORTC
#endasm
#include <lcd.h>
#define ADC_VREF_TYPE 0x60
#define MAX 130;
#define MIN 60;
// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input|ADC_VREF_TYPE;
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}
// Declare your global variables here
int a,b,c,d,e,f,i,tmp,gtmp=0;
int dw,dg,dgt,dwt,dtmp;
char chdw[10], chdg[10];
char cha,chb,chc,chd,che,chf;
lcdfunc()
{
lcd_clear();
a=read_adc(7);
b=read_adc(6);
c=read_adc(5);
d=read_adc(4);
e=read_adc(3);
f=read_adc(2);
if(a<=95)
cha='w';
if(a>95&&a<=150)
cha='x';
if(a>150&&a<220)
cha='g';
if(a>=220)
cha='b';
if(b<=70)
chb='w';
if(b>70&&b<=150)
chb='x';
if(b>150&&b<200)
chb='g';
if(b>=200)
chb='b';
if(c<=40)
chc='w';
if(c>40&&c<=140)
chc='x';
if(c>140&&c<200)
chc='g';
if(c>=200)
chc='b';
if(d<30)
chd='w';
if(d>=30&&d<=100)
chd='x';
if(d>100&&d<210)
chd='g';
if(d>=210)
chd='b';
if(e<=30)
che='w';
if(e>30&&e<=105)
che='x';
if(e>105&&e<200)
che='g';
if(e>=200)
che='b';
if(f<=70)
chf='w';
if(f>70&&f<=135)
chf='x';
if(f>135&&f<200)
chf='g';
if(f>=200)
chf='b';
lcd_gotoxy(0,0); lcd_putchar(cha);
lcd_gotoxy(3,0); lcd_putchar(chb);
lcd_gotoxy(6,0); lcd_putchar(chc);
lcd_gotoxy(9,0); lcd_putchar(chd);
lcd_gotoxy(12,0); lcd_putchar(che);
lcd_gotoxy(15,0); lcd_putchar(chf);
// delay_ms(100);
}
open()
{
PORTB.0=0;
PORTB.1=0;
PORTB.2=0;
PORTD.6=0;
OCR0=0;
OCR2=0;
delay_ms(1);
}
/*lock()
{
PORTB.0=1;
PORTB.1=1;
PORTB.2=1;
PORTD.6=1;
} */
steepright()
{
tmp=0;
OCR0=0;
OCR2=MAX;
PORTB.0=0;
PORTB.1=1;
PORTB.2=0;
PORTD.6=1;
delay_ms(1);
/* OCR0=0; // to turn steep right
OCR2=MAX;
PORTD.6=1;
PORTB.2=0;
delay_ms(1); */
}
steepleft()
{ //steepleft
tmp=1;
OCR0=MAX;
OCR2=0;
PORTB.0=1;
PORTB.1=0;
PORTB.2=1;
PORTD.6=0;
delay_ms(1);
/* OCR0=MAX;
OCR2=0;
PORTB.0=1;
PORTB.1=0;
delay_ms(1); */
}
right()
{
OCR0=MIN; // to turn right
OCR2=MAX;
PORTD.6=1;
PORTB.2=0;
PORTB.0=1;
PORTB.1=0;
delay_ms(1);
}
left()
{
OCR0=MAX; // to turn left
OCR2=MIN;
PORTD.6=1;
PORTB.2=0;
PORTB.0=1;
PORTB.1=0;
delay_ms(1);
}
wuturn()
{
lcdfunc();
while(!(cha=='x'&&(chc=='w'||chc=='g')&&che=='x'))
{
lcdfunc();
tmp=1;
OCR0=130;
OCR2=130;
PORTB.0=1;
PORTB.1=0;
PORTB.2=1;
PORTD.6=0;
delay_ms(1);
open();
}
}
guturn()
{
lcdfunc();
while(!(cha=='x'&&chc=='g'&&chf=='x'))
{
lcdfunc();
tmp=1;
OCR0=130;
OCR2=130;
PORTB.0=1;
PORTB.1=0;
PORTB.2=1;
PORTD.6=0;
delay_ms(1);
open();
}
}
forward()
{
OCR0=MAX; // to go forwrd
OCR2=MAX;
PORTD.6=1;
PORTB.2=0;
PORTB.0=1;
PORTB.1=0;
delay_ms(1);
}
whiteline()
{
while(cha!='b' && chd!='b')
{
lcdfunc();
if(cha=='w'&&chc=='w'&&che=='w')
{
wuturn();
}
else if (chd=='w') // right sensor active
{
tmp=0;
right();
}
else if (chb =='w') // left sensor active
{
tmp=1;
left();
}
else if (chc=='w') // middle sensor active || extreme sensors active
forward();
if (chb !='w' && chc!='w' && chd!='w') // no sensor active
{
if (tmp==0)
steepright();
if (tmp==1)
steepleft();
}
open();
dw++;
}
}
greenline()
{
while(cha!='b'&& chc!='b' && chd!='b')
{
lcdfunc();
if(cha=='g'&&che=='g'&&gtmp==0)
{
guturn();
gtmp=1;
}
else if (chd=='g') // right sensor active
{
tmp=0;
right();
}
else if (chb =='g') // left sensor active
{
tmp=1;
left();
}
else if (chc=='g') // middle sensor active || extreme sensors active
forward();
if (chb !='g' && chc!='g' && chd!='g') // no sensor active
{
if (tmp==0)
steepright();
if (tmp==1)
steepleft();
}
open();
dg++;
}
}
left90()
{
tmp=1;
OCR0=60;
OCR2=0;
PORTB.0=1;
PORTB.1=0;
delay_ms(180);
open();
}
right90()
{
tmp=0;
OCR2=60;
OCR0=0;
PORTB.2=0;
PORTD.6=1;
delay_ms(180);
open();
}
glowled()
{
PORTD.4=1;
delay_ms(50);
PORTD.4=0;
for(i=0;i<5;i++)
{forward();open();}
}
void main(void)
{
// Declare your local variables here
// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=Out Func0=Out
// State7=T State6=T State5=T State4=T State3=T State2=T State1=0 State0=0
PORTA=0x00;
DDRA=0x03;
// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out
Func0=Out
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
PORTB=0x00;
DDRB=0xFF;
// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTC=0x00;
DDRC=0x00;
// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out
Func0=Out
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
PORTD=0x00;
DDRD=0xFF;
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=FFh
// OC0 output: Non-Inverted PWM
TCCR0=0x6A;
TCNT0=0xFF;
OCR0=0xA0;
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Fast PWM top=FFh
// OC2 output: Non-Inverted PWM
ASSR=0x00;
TCCR2=0x6A;
TCNT2=0xFF;
OCR2=0xA0;
// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;
// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;
// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: None
// Only the 8 most significant bits of
// the AD conversion result are used
ADMUX=ADC_VREF_TYPE;
ADCSRA=0x86;
// LCD module initialization
lcd_init(16);
while (1)
{
// Place your code here
lcdfunc();
if(dw>0 && dg>0)
{
if(dg>dw)
{
dgt=dg;dwt=dw;
if(cha=='g'&& che=='g' && chf=='g' && dtmp==0)
{
glowled();
dtmp=1;
}
if(cha=='w'&&che=='w'&&chf=='w' && dtmp==1)
{
glowled();
dtmp=2;
}
if(dtmp==2 && cha!='x' && che!='x' && chf!='x' && !(cha=='w'&&che=='w')
&& chc!='x'&&chd!='x'&&chb!='x'&& !(cha=='g'&&che=='g'))
{
open();delay_ms(150);
if(cha=='g')
left90();
else if(che=='g')
right90();
else
{
for(i=0;i<10;i++)
{forward();
open();}
}
lcdfunc();
greenline();
dg=dgt;
dtmp=3;
}
if(dtmp==3 && cha!='x' && che!='x' && chf!='x'&&
!(cha=='w'&&che=='w')&& !(cha=='g'&&che=='g'))
{
open();delay_ms(50);
if(cha=='w')
left90();
else if(che=='w')
right90();
else
{
for(i=0;i<5;i++)
{forward();
open();}
}
lcdfunc();
whiteline();
dw=dwt;
dtmp=4;
}
}
if(dw>dg)
{
dwt=dw;dgt=dg;
if(cha=='g'&& che=='g' && chf=='g' && dtmp==1)
{
glowled();
dtmp=2;
}
if(cha=='w'&&che=='w'&&chf=='w' && dtmp==0)
{
glowled();
dtmp=1;
}
if(dtmp==2 && cha!='x' && che!='x' && chf!='x'&&
!(cha=='w'&&che=='w')&&chc!='x'&&chb!='x'&&chd!='x'&& !(cha=='g'&&che=='g'))
{
open();delay_ms(50);
if(cha=='w')
left90();
else if(che=='w')
right90();
else
{
for(i=0;i<5;i++)
{forward();
open();}
}
lcdfunc();
whiteline();
dw=dwt;
dtmp=3;
}
if(dtmp==3 && cha!='x' && che!='x' && chf!='x'&&
!(cha=='w'&&che=='w')&& !(cha=='g'&&che=='g'))
{
open();delay_ms(50);
if(cha=='g')
left90();
else if(che=='g')
right90();
else
{
for(i=0;i<5;i++)
{forward();
open();}
}
lcdfunc();
greenline();
dg=dgt;
dtmp=4;
}
}
}
if((cha=='w'||chb=='w')&&dw==0)
{
tmp=1;dw=0;
left90();
lcdfunc();
whiteline();
itoa(dw,chdw); lcd_gotoxy(0,1); lcd_puts(chdw);
left90();
}
else if(cha=='g'&&dg==0)
{
tmp=1;dg=0;
left90();
lcdfunc();
greenline();
itoa(dg,chdg); lcd_gotoxy(7,1); lcd_puts(chdg);
left90();
}
else if (chc=='b'||chc=='g') // middle sensor active || extreme sensors active
forward();
else if (chb =='b'||chb=='g'||cha=='g'||cha=='b') // left sensor active
{
tmp=1;
left();
}
else if (chd=='b'||chd=='g') // right sensor active
{
tmp=0;
right();
}
if (chb !='b' && chc!='b' && chd!='b' && chb !='g' && chc!='g' && chd!='g') // no
sensor active
{
if (tmp==0)
steepright();
if (tmp==1)
steepleft();
}
open();
};
}