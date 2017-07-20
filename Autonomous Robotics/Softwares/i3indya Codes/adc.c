
#define ref 0x40


void adc_init(void)        // Initialization of ADC
{
ADMUX=ref & 0xff;
ADCSRA=0x81;
}
 
unsigned int adc_read(unsigned char adc_input)
{
ADMUX=adc_input|ref;
// Delay needed for the stabilization of the ADC input voltage
_delay_us(9);
// Start the AD conversion
ADCSRA|=0x48;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);

return ADCW;
}