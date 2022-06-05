#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <usart.h>

#include <button.h>
#include <led.h>

#define BUTTON_PIN PINC
#define BUTTON1 PC1

int main(){
    enableAllButtons();
    enableAllLeds();
    lightDownAllLeds();
    initUSART();

    while (1)
    {
        if (( BUTTON_PIN & ( 1 << BUTTON1 )) == 0 ) 
        {
            lightToggleOneLed(1);
            for (int i = 0; i < 100; i++)
            {
                printf("%d: I am not allowed to speak in class.\n", i);
            }
            
        }
    }
    


}