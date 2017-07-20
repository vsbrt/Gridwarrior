void usart_init()
{	UCSRB |= (1 << RXEN)|(1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); 
	UBRRL = BAUD_PRESCALE; 
	UBRRH = (BAUD_PRESCALE>> 8); 
} 
void putch(char send)
{	while(!(UCSRA & (1<<UDRE)));
      UDR=send;
}
unsigned int getch()
{	while ((UCSRA & (1 << RXC)) == 0); 
	
	return UDR; 
} 

void putstr(char*send)
{
	int i=0;
  	while(send[i]!='\0')
   		{
		while(!(UCSRA & (1<<UDRE)));
	
		UDR=send[i];
		i++;
		};
}
//
