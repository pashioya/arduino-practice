#ifndef buzzer_c

#define __DELAY_BACKWARD_COMPATIBLE__
#include <led.h>
#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>
#include <string.h>

#define STRING char[]
// DURATION IS IN MILLISECONDS
#define DURATION 250

// FREQUENCIES OF THE NOTES
//  #define C5  523.250
//  #define D5  587.330
//  #define E5  659.250
//  #define F5  698.460
//  #define G5  783.990
//  #define A5  880.00
//  #define B5  987.770
//  #define C6  1046.500

void enableBuzzer()
{
    DDRD |= (1 << PD3); // Buzzer is connected to PD3
    PORTD |= (1 << PD3);
}

float frequencySelector(char *note)
{

    char c5[2] = {"C5"};
    char d5[2] = {"D5"};
    char e5[2] = {"E5"};
    char f5[2] = {"F5"};
    char g5[2] = {"G5"};
    char a5[2] = {"A5"};
    char b5[2] = {"B5"};
    char c6[2] = {"C6"};

    if (strcmp(note, c5) == 0)
    {
        return 523.250;
    }
    else if (strcmp(note, d5) == 0)
    {
        return 587.330;
    }
    else if (strcmp(note, e5) == 0)
    {
        return 659.250;
    }
    else if (strcmp(note, f5) == 0)
    {
        return 698.460;
    }
    else if (strcmp(note, g5) == 0)
    {
        return 783.990;
    }
    else if (strcmp(note, a5) == 0)
    {
        return 880.00;
    }
    else if (strcmp(note, b5) == 0)
    {
        return 987.770;
    }
    else if (strcmp(note, c6) == 0)
    {
        return 1046.500;
    }
    return 0;
}

void playTone(float frequency, uint32_t duration)
{
    uint32_t periodInMicro = (uint32_t)(1000000 / frequency);              // Calculate the period in microsecs from the freq
    uint32_t durationInMicro = duration * 1000;                            // We express duration in microsecs
    for (uint32_t time = 0; time < durationInMicro; time += periodInMicro) // See tutorial on Music for more info!
    {
        PORTD &= ~(1 << PD3);         // turn the buzzer on
        _delay_us(periodInMicro / 2); // Wait for the half of the period
        PORTD |= (1 << PD3);          // Turn the buzzer off
        _delay_us(periodInMicro / 2); // Wait again for half of the period
    }
}

void playNote(char *note, uint32_t duration)
{
    float frequency = frequencySelector(note);
    playTone(frequency, duration);
}

#endif