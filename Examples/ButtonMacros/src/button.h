#ifndef button_c
#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>

void enableButton( int button );
int buttonPushed( int button );
int buttonReleased( int button );



#endif