#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include <usart.h>
#include <display.h>
#include <led.h>
#include <buzzer.h>
#include <potentiometer.h>
#include <button.h>
#include <timer.h>

uint16_t timerValue;
uint16_t oldVal;

uint32_t counter = 0;

int button1 = 0;
    int button2 = 0;
    int button3 = 0;

// transformation and scaler from the 0-1023 to a 10-240 scale
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

ISR(TIMER1_COMPA_vect)
{
    counter++;
    if (counter % 250 == 0)
    {
        timerValue = timerValue - 1;
        playTone(100, 100);
        printf("Seconds = %d \n", timerValue);
        lightToggleOneLed(2);
    }
}
void deactivation(){
    if (buttonPushed(1) == 1)
        {
            button1 = 1;
        }
        if (button1 == 1)
        {
            if (buttonPushed(2) == 1)
            {
                button2 = 1;
            }
        }
        else
        {
            button1 = 0;
        }
        if ((button1 == 1) && (button2 == 1))
        {
            if (buttonPushed(3) == 1)
            {
                button3 = 1;
            }
        }
        else
        {
            button1 = 0;
            button2 = 0;
        }
        if ((button1 == 1) && (button2 == 1) && (button3 == 1))
        {
            stopTimer(2);
        }
        else
        {
            button1 = 0;
            button2 = 0;
            button3 = 0;
        }
}

int main()
{
    initADC();
    initDisplay();
    initUSART();
    enableBuzzer();
    enableAllButtons();
    enableAllLeds();

    uint16_t adcValue;

    while (1)
    {
        analogToDigital();
        adcValue = ADC;
        timerValue = map(adcValue, 0, 1023, 10, 240);
        writeNumberAndWait(timerValue, 1000);
        if (buttonPushed(2) == 1)
        {
            break;
        }
    }
    initTimer(1, 2, 256);
    enableOCRA(1, 249);

    while (1)
    {

        analogToDigital();
        writeNumberAndWait(timerValue, 100);
        deactivation();
    }
    return 0;
}