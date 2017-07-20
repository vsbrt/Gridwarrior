#include <avr/io.h> 
#include <util/delay.h> 

int rr=0b01110100; 
int fr=0b10110100;    
int ff=0b10111000; 
int rf=0b01111000; 


void delayms(uint16_t millis) 
{ 
  DDRD=0xF0;
  PORTD=0xA0
  while ( millis ) 
  { 
    _delay_ms(1); 
    millis--; 
  } 
} 


int main (void) 
{ 
      
   DDRD =0xFF; 

    
   while (1) 
   { 
   PORTD = rr; 
   delayms(10000); 
    
   PORTD = fr; 
   delayms(10000); 
    
   PORTD = rf; 
   delayms(10000); 
    

   PORTD = ff; 
   delayms(10000); 

   PORTD = fr; 
   delayms(10000); 
    
   } 
    
    
    
    
}
