#ifndef Button_C
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/io.h>

#include <time.h>

void enableOneButton(int button);

void enableAllButtons();

int buttonPushed(int button);

int buttonReleased(int button);

#endif