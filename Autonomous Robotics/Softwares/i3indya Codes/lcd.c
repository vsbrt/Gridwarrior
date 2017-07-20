//Function declaration
int port;
//LCD init
 void lcd_init(char p)
 {
    if(p=='D')port=0;
	if(p=='C')port=3;
	if(p=='B')port=6;
	if(p=='A')port=9;
	_SFR_IO8(0x11+port)=0xFF;
	_delay_ms(100);
	lcd_printcom(0x01);        //clear LCD
    	_delay_ms(200);   
    	lcd_printcom(0x02);        //cursor in home position and Returns display to its original state if shifted
    
    	lcd_printcom(0x28);        //selecting data is writen in CGRAM or DDRAM
     	_delay_ms(20);   
	

   	lcd_printcom(0x06); 	//Sets mode to increment the
                            	          		//address by one and to shift the
                            			//cursor to the right at the time of
                            			//write to the DD/CGRAM.
                            			//Display is not shifted.
    
    	lcd_printcom(0x0C);        //Turns on display and cursor off.
    	lcd_userdefine();     
    
 }


//LCD 8bit to 4 bit mode for command
void lcd_printcom(char val)
{
   char div;
    
    div = val & 0xF0;        //mask lower nibble because PA4-PA7 pins are used. 
    lcd_com(div);            // send to LCD
 
    div = ((val<<4) & 0xF0);    //shift 4-bit and mask
    lcd_com(div);    

}
//LCD 8bit to 4 bit mode for data
void lcd_printchar(char val1)
{
   char div1;
    div1 = val1 & 0xF0;        //mask lower nibble because PA4-PA7 pins are used. 
    lcd_data(div1);            // send to LCD
 
    div1 = ((val1<<4) & 0xF0);    //shift 4-bit and mask
    lcd_data(div1);    
    
}

//LCD command line
 void lcd_com(char val2)
 {
 //int port=0;
  	_SFR_IO8(0x12+port)=val2;
	_delay_ms(10);
  	_SFR_IO8(0x12+port) &=~(1<<rs);
	_delay_ms(1);
    _SFR_IO8(0x12+port)&=~(1<<rw);
	_delay_ms(1);
    _SFR_IO8(0x12+port)|=(1<<en);
    _delay_ms(1);
    _SFR_IO8(0x12+port)&=~(1<<en);
 }

 //LCD DATA line
 void lcd_data(char val3)
 {
    //int port=0;
    _SFR_IO8(0x12+port)=val3;
	_delay_ms(1);
    _SFR_IO8(0x12+port)|=(1<<rs);
    _delay_ms(1);
	_SFR_IO8(0x12+port)&=~(1<<rw);
    _delay_ms(1);
	_SFR_IO8(0x12+port)|=(1<<en);
    _delay_ms(1);
    _SFR_IO8(0x12+port)&=~(1<<en);


 }

//LCD cursor possition
 void lcd_gotoxy(int x,int y)
 {
    pos=15-x;

    int xk=0x80,yk=0xC0;    
    if(y==1)
    {
    lcd_printcom(0xC0);
    yk = x | 0xC0;
    lcd_printcom(yk);
      }
    else
    {
    xk = x | 0x80;
    lcd_printcom(xk);
    }
 } 

 //LCD print
 void lcd_printstr(char *data0)
 {
     int i=0;

     
     while(data0[i]!='\0')
        {
       if(i<16)
        {
        lcd_printchar(data0[i]);
       }

     if(i == pos)
        {
        lcd_printcom(0xC0);
        }

        if(i>15)
        {
        lcd_printchar(data0[i]);
       }
        i++;
        }

 }

//////////////////////LCD number/////////////////////////////////////////////////////
void lcd_printnum(long int val)
{    
    char str;
    if(val==0)
    lcd_printchar(48);
    while(val)
    {
    str=val%10;
    val=val/10;
   lcd_printcom(0x04);
     lcd_printchar(48+str);
    lcd_printcom(0x06);
    }

}
//LCD clear

void lcd_clear()
    {

    lcd_printcom(0x01);
    _delay_ms(300);
    }
//animation
void lcd_userdefine()
{
 lcd_printcom(0x40);
_delay_ms(100);
 lcd_printchar(0b00000000);
 lcd_printchar(0b00000000);
 lcd_printchar(0b00000001);
 lcd_printchar(0b00000011);
 lcd_printchar(0b00000111);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00000000);
 lcd_printcom(0x48);
_delay_ms(100);
 lcd_printchar(0b00000000);
 lcd_printchar(0b00000100);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00011111);
 lcd_printchar(0b000001000);
 lcd_printchar(0b00000000);
 lcd_printcom(0x50);
_delay_ms(100);
 lcd_printchar(0b00000000);
 lcd_printchar(0b00000100);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00000001);
 lcd_printchar(0b00000000);
 lcd_printcom(0x58);
_delay_ms(100);
 lcd_printchar(0b00000000);
 lcd_printchar(0b00000100);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00010000);
 lcd_printchar(0b00000000);
 lcd_printcom(0x60);
_delay_ms(100);
 lcd_printchar(0b00000100);
 lcd_printchar(0b00001110);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00010001);
 lcd_printchar(0b00010001);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00011111);
 lcd_printchar(0b00011111);
 lcd_printcom(0x68);
_delay_ms(100);
 lcd_printchar(0b00000001);
 lcd_printchar(0b00000001);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00001111);
 lcd_printchar(0b00001111);
 }
//custom pattern
void lcd_printpattern(int x)
{
if(x==1)
 lcd_printchar(0);
if(x==2)
 lcd_printchar(1);
if(x==3)
 lcd_printchar(2);
if(x==4)
 lcd_printchar(3);
if(x==5)
 lcd_printchar(4);
if(x==6)
 lcd_printchar(5);
if(x==7)
 lcd_printchar(6);
}

//lcd Animation
void lcd_animation(int x)
{
 lcd_printchar(1);
_delay_ms(50);
 lcd_printchar(2);
_delay_ms(50);
 lcd_printchar(3);
}