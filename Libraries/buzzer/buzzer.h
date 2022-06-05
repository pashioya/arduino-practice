#ifndef buzzer_h

#define __DELAY_BACKWARD_COMPATIBLE__
#include <led.h>
#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>

void enableBuzzer();

void frequencySelector(char *note);

void playTone(float frequency, uint32_t duration);

void playNote(char *note, uint32_t duration);

#endif