#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>
#include <display.h>


#include <stdio.h>
#include <ctype.h>


#define birthday 2001

int main()
{
    initUSART();
    initDisplay();
    while ( 1 )
    {
        // for ( int i = 0; i < 4; i++ )
        // {
        //     writeNumberToSegment( i, 8 );
        //     _delay_ms( 1000 );
        // }
        /* Use the writeNumber function if
         * you want to display a 4 digit number. */
        // writeNumber( 2011 );
        // _delay_ms( 1000 );
        /* Problem: this function shows the digits 1 by 1 and then
         * adds a delay. So, only the last digit is displayed. 
         * Solution: to display the complete number, repeat this in a loop. */
        for ( int i = 0; i < 10000; i ++ )
        {
                writeNumber(birthday);
        }
        /* Or you could use a function from the library.
         * Then you can also specify the display duration. */
        // writeNumberAndWait( 2001, 10000 );
    }
    return 0;
}