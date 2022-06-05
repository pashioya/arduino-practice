#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>
#include <display.h>
#include <led.h>
#include <potentiometer.h>

void initADC()
{   
    // can change REFS0 to REFS1 and it changes things.  5v to 2.5 v
    ADMUX |= (1 << REFS0);   
    ADCSRA |= ( 1 << ADPS2 ) | ( 1 << ADPS1 ) | ( 1 << ADPS0 );  //Determine a sample rate by setting a division factor. Used division factor: 128
    ADCSRA |= ( 1 << ADEN ); //Enable the ADC
}

int main()
{
    initUSART();
    initDisplay();
    initADC();
    while ( 1 )
    {
        ADCSRA |= ( 1 << ADSC );    //Start the analog --> digital conversion
        loop_until_bit_is_clear( ADCSRA, ADSC );    //Wait until the conversion is completed
        uint16_t value = ADC;   //Read the result
        value = value - 400;
        writeNumberAndWait(value,100);
    }
    return 0;
}