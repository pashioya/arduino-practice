#ifndef timer_h

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <usart.h>

void initTimer(int timer, int mode, int scalefactor);

void stopTimer(int timer);

void enableOCRA(int timer, int OCRA);

void enableOVF(int timer);

#endif
