#include <util/delay.h> 
#include <avr/io.h> 
#include <led.h>
#include <button.h>
#include <usart.h>
#include <stdio.h>
int main() //Start of the program
{
    enableAllLeds();
    lightUpAllLeds();
    lightDownAllLeds();
    // if(bit_is_set(PINB,10))
    //     {lightDownAllLeds();
    //     printf("Its on");}
    
    //  if(bit_is_clear(PINB,11))
    //     {lightDownAllLeds();
    //     printf("Its on");}
    
        if(PORTB && (1 << 3))
            lightToggleOneLed(2);
        // if the thing is on, lightdown all leds

    //  if(bit_is_clear(PINB,13))
    //     {lightDownAllLeds();
    //     printf("Its on");}

    // if (!bit_is_set(PINB,11))∏
    //     lightUpAllLeds();
    
        // lightDownAllLeds();
        
    // while(1){
    // lightToggleOneLed(rand() % 5);
    // _delay_ms(5000);
    // }
    // // enableButton(1);
}