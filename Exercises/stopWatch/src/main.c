#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <usart.h>

#include <timer.h>
#include <led.h>
#include <display.h>
#include <button.h>

uint32_t counter = 0;
int seconds = 30;
int minutes = 0;

void tick()
{
    // if ((minutes % 1) == 1)
    //     minutes = seconds/60;
    if (seconds > 60)
    {
        seconds = 0;
        minutes++;
    }
}
ISR(TIMER2_COMPA_vect)
{
    counter++;
    if (counter % 250 == 0)
    {
        seconds--;
        tick();
    }
}
void writeTimerAndWait(int delay)
{
    for (int i = 0; i < delay / 20; i++)
    {
        writeNumberToSegment(0, (minutes / 10) % 10);
        _delay_ms(5);
        writeNumberToSegment(1, (minutes % 10));
        _delay_ms(5);
        writeNumberToSegment(2, (seconds / 10) % 10);
        _delay_ms(5);
        writeNumberToSegment(3, (seconds % 10));
        _delay_ms(5);
    }
}

int main()
{
    initUSART();
    initDisplay();
    enableAllLeds();
    enableAllButtons();
    int oldSeconds;

    while (1)
    {
        if (buttonPushed(1) == 1)
        {
            initTimer(2, 2, 256);
            enableOCRA(2, 249);
        }
        
        if (buttonPushed(2) == 1)
        {
            stopTimer(2);
        }
        
        if (buttonPushed(3) == 1)
        {
            seconds = 0;
            minutes = 0;
        }

        if (seconds != oldSeconds)
        {
            printf("Seconds: %d \n", seconds);
            oldSeconds = seconds;
        }
        writeTimerAndWait(100);
    }
    return 0;
}