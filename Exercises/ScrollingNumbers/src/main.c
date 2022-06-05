
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <usart.h>
#include <display.h>

int main()
{
    initDisplay();

    // done using 3 methods

    // Works but only does one number at a time

    // int displayedNumber = 0;
    // int segCounter = 0;

    // for ( int i = 0; i < 100; i++ )
    // {
    //     writeNumberToSegment( segCounter, displayedNumber );
    //     _delay_ms( 500 );
    //     segCounter++;
    //     if(segCounter == 4 ){
    //         segCounter = 0;
    //     }
    //     displayedNumber++;
    //     if (displayedNumber == 10)
    //     {
    //         displayedNumber = 1;
    //     }
    // }
    // int x = 0;
    // for ( int i = 0; i < 10000; i ++ )
    // {
        // writeNumber( x );
    //     printf("%d", x);
    //     x = (x+1) % 3;
    // }

    // works but is kinda wierd

    // int counter = 0;
    // for ( int i = 0; i < 10000; i++ )
    //     {
    //         counter++;
    //         if(counter == 7)
    //             counter=0;
    //         writeNumberToSegment( 0, (counter));
    //         _delay_ms(60);
    //         writeNumberToSegment( 1, (counter+1));
    //         _delay_ms(60);
    //         writeNumberToSegment( 2, (counter+2));
    //         _delay_ms(60);
    //         writeNumberToSegment( 3, (counter+3));
    //         _delay_ms(60);
    //     }
    

    // works perfectly except when th counter reaches 7 then it resets. and the cycle breaks. 6789 -> 0123  fix later

    int counter = 0; 
    while (1)
    {
        for (int i = 0; i < 1000 / 20; i++) {
        if(counter ==7)
            counter = 0;
        writeNumberToSegment(0, counter);
        _delay_ms(5);
        writeNumberToSegment(1, (counter+1));
        _delay_ms(5);
        writeNumberToSegment(2, (counter+2));
        _delay_ms(5);
        writeNumberToSegment(3, (counter+3));
        _delay_ms(5);
        }
        counter++;
    }
}