#ifndef LED_h
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/io.h>

#include <time.h>

void enableOneLed(int);

void enableMultipleLeds(uint8_t);

void enableAllLeds();

void lightUpOneLed(int);

void lightUpMultipleLeds(uint8_t);

void lightUpAllLeds();

void lightDownOneLed(int);

void lightDownMultipleLeds(uint8_t);

void lightDownAllLeds();

void lightToggleOneLed(int);

void dimLed(int lednumber, double percentage, int duration);

#endif