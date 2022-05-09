#ifndef button_c
#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>

void enableButton( int button ){
    if (button < 1 || button > 3)
        return;
    DDRC &=  ( 1 << (PC1 + button) );
    PORTC |= ( 1 << (PC1 + button) ); 
}

int buttonPushed( int button ){
    if (( PINC & ( 1 << (PC0 + button) )) == 0 )
    {printf("Button %s pressed!\n",button);
    return 1;}
    else
    return 0;    
}

int buttonReleased( int button ){
    if (( PINC & ( 1 << (PC0 + button) )) == 0 )
    {printf("Button %s released!\n",button);
    return 1;}
    else 
    return 0;
}

#endif