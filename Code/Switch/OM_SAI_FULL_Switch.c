#include<avr/io.h>
#include<util/delay.h>
unsigned int a;
int p,q,r,s,x,y,xa,ya,h,part2=0,set=0;
int dp,dq,dx,dy,dxa,dya;

void leftcount(void)
{
   y++;   
}


void rightcount(void)
{
   x++;
}



int main(void)
{
DDRA = 0x00;
DDRC = 0xFF;
DDRD = 0xFF;


  while(dxa != xa   &&   dya != ya)
  {
   
     a = PINA & 0b00000111;


/*
1) considering that only white is recognised by sensors else '0'
   and when whit is detected o/p is '1'
   
2) 10000010 will give the forward motion of motors
*/

		if(part2 == 0)
		{


		    while(a != 00000111  &&  a != 00000101)    //to check for part1
		    {
        
			   if(a == 00000111)
			   {
			   		part2++;
			   }


			   a = PINA & 0b00000111;


				switch(a)
				{
			
					case 00000001 :  //right turn
							
									 if(set != 0)
									 {
		 
									 	h++;

									 }
		 

							  		PORTC = 0b10000000;

									break;



			
					case 00000100 : //left turn
							
									if(set != 0)
									 {
		 
									 	h++;

									 }


									 PORTC = 0b00000010;

									 break;


			


					//counting begins

					case 00000011 : //patch on the right
							
									rightcount();
							
							
									if(p == 0  &&  h == 0)      // setting "set" to 1 = set A
									{
									    set++;
									}

		 					
									if(h != 0)
									{
										set++;
										h=0;
									}

							

									switch(set)
									{

										case 1: 
												p++;
												break;

										case 2:
												q++;
												break;

										case 3:
												r++;
												break;

										case 4:
												s++;
												break;

								
										default: break;

									}



										
					case 00000110 : //patch on left
							
									leftcount();
							
							
									if(p == 0  &&  h == 0)     // setting "set" to 1 = set A
									{
									    set++;
									}

		 					
									if(h != 0)
									{
										set++;
										h=0;
									}

							
									switch(set)
									{

										case 1: 
												p++;
												break;

										case 2:
												q++;
												break;

										case 3:
												r++;
												break;

										case 4:
												s++;
												break;

								
										default: break;

									}


				 }	
	   	
		      }

            }//end of first if


			
			//"********PART II*********"


  
  			if(part2 == 1)
			{
				
				while(dxa != xa   &&   dya != ya)
				{
					//kjfhiseu
				}

			}
  
  
  
  
  
  
  
   }

   return 0; 

}
