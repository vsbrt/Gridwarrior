#include<avr/io.h>
#include<util/delay.h>
unsigned int a;
int p,q,r,s,x,y,xa,ya,h,set=0;
int dp,dq,dx,dy,dxa,dya;

int leftcount()
{
   y++;   
}


int rightcount()
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



    while(a != 00000111)    //to check for part1
    {
        
		
	   a = PINA & 0b00000111;


	   if(a == 00000001)                 //right turn
	   {
	     
				 
				 if(set != 0)
				 {
		 
				 	h++;

				 }
		 

		  		PORTC = 0b10000000;
	   
	   
	   }



	   if(a == 00000100)                 //left turn 
	   {

	     PORTC = 0b00000010;
	   
	   }




    //counting begins

	   if(a == 00000110)          //patch on the right
	   {
	     


		 if(p == 0)      // setting "set" to 1 = set A
		 {
		    set++;
		 }

		 
		 
		 rightcount();
		 
		 		   
		   if(p == 1)
		   {
		     set++;
		   }




		   if(set == 1)   // count p
		   {
		     p++;
		   }



		   
         if(p != 0 && q == 0 && h != 0 )      // setting "set" to 2 = set B
		 {
		    set++;
		 }



		   if(set == 2)   // count q
		   {
		     p++;
		   }

	   		 
	   }


	   
	   
	   
	   
	   	   
	   if(a == 00000101)          //patch on the left
	   {
	     q++;
		   
		   if(q == 1)
		   {
		     set++;
		   }

	   }
	   

    }

}
