#ifndef LED_h
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/io.h>
#include <time.h>

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED1 PB2

void enableOneLed(int lednumber)
{
    lednumber = lednumber - 1;
    if (lednumber < 0 || lednumber > 3)
        return;
    LED_DDR |= (_BV(LED1 + lednumber));
}

void lightUpOneLed(int lednumber)
{
    lednumber = lednumber - 1;
    if (lednumber < 0 || lednumber > 4)
        return;
    LED_PORT &= ~(_BV(LED1 + lednumber));
}

void lightDownOneLed(int lednumber)
{
    lednumber = lednumber - 1;
    if (lednumber < 0 || lednumber > 3)
        return;
    LED_PORT |= (_BV(LED1 + lednumber));
}

void enableMultipleLeds(uint8_t lednumber)
{
    LED_DDR |= lednumber;
}
void lightDownAllLeds()
{
    for (int i = 1; i < 5; i++)
    {
        lightDownOneLed(i);
    }
}

void enableAllLeds()
{
    for (int i = 1; i < 5; i++)
    {
        enableOneLed(i);
    }
    lightDownAllLeds();
}

void lightUpMultipleLeds(uint8_t lednumbers)
{
    LED_PORT |= ~(lednumbers);
}

void lightUpAllLeds()
{
    for (int i = 1; i < 5; i++)
    {
        lightUpOneLed(i);
    }
}

void lightDownMultipleLeds(uint8_t lednumber)
{
    LED_PORT &= ~(lednumber);
}

void lightToggleOneLed(int lednumber)
{
    lednumber = lednumber - 1;
    if (lednumber < 0 || lednumber > 3)
        return;
    // Old Solution: not perfect but worked for the most part
    // if (PORTB && (1 << lednumber))
    // {
    //     lightUpOneLed(lednumber);
    // }
    // else
    // {
    //     lightDownOneLed(lednumber);
    // }
    LED_PORT ^= (_BV(LED1 + lednumber));
}

void dimLed(int lednumber, double percentage, int duration)
{
    double upTime = (percentage / 10);
    double downTime = 10 - (percentage / 10);

    double time_elapsed = 0;
    while (time_elapsed != duration)
    {

        lightUpOneLed(lednumber);
        _delay_ms(upTime);

        lightDownOneLed(lednumber);
        _delay_ms(downTime);

        time_elapsed = time_elapsed + 10;
    }
}

#endif
