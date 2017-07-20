



#ifndef _LCD_H
#define _LCD_H

//define pin config.for LCD 
//#define port x
#define rs PD0    //rs=register select 0 for comm. 1 for Data
#define rw PD1    //rw=read/write to LCD 1 for read and 0 for write
#define en PD2    //enable lcd 1 or disable lcd 0 lcd prepare for geting data

#define porta 'A'
#define portb 'B'
#define portc 'C'
#define portd 'D'
#define bell 17
//define function
void lcd_init(char);            //initialisation for lcd
void lcd_clear();
void lcd_printcom(char);           //function for sending 8bit data in 4 bit mode
void lcd_printchar(char); 
void lcd_com(char);            //function for sending comm line
void lcd_data(char);         //usre data
void lcd_printstr(char *str);
void lcd_printnum(long int);
void lcd_gotoxy(int,int);        // goto row or coll possition
void lcd_userdefine();
void lcd_animation();
void lcd_printpattern();

//Global veriable define here
int pos;
//start main funtion
//calling function define after main function
 

#include<i3indya/lcd.c>
//Function declaration
#endif
