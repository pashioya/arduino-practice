#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>
#include <led.h>
#include <button.h>

int main()
{
    initUSART();
    // DDRC &= ~(1 << PC1); /* Button 1 is connected to C1.
    //                       * We set the corresponding bit in the Data Direction Register to 0. */
    
    
    enableOneButton(0);
    // replaced commented out code with a simple enable one button function

    printf("DDRC: ");
    printBinaryByte(DDRC);
    // PORTC |= (1 << PC1); /* Activate the Pull-up of C1: PINC will be set to high */
    printf("\nPORTC: ");
    printBinaryByte(PORTC);
    enableOneLed(2);
    while (1)
    {
        printf("\nPINC: ");
        printBinaryByte(PINC);
        if ((PINC & (1 << PC1)) == 0) /* This way we can test whether the PC1 bit
                                       * of PINC is set to 0 (button is pressed) */
        {
            printf(" - Button 0 pressed!\n");

            lightToggleOneLed(2);
        }
        else//pinc is 1 (not grounded) so its not being pressed
        {
            printf(" - Button 0 NOT pressed!!\n");
        }
        _delay_ms(1000);
    }
    return 0;
}