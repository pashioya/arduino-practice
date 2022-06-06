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

int seconds = 0;
uint16_t adcValue;
uint32_t counter = 0;

int button1 = 0;
int button2 = 0;
int button3 = 0;

ISR(TIMER2_COMPA_vect)
{
    counter++;
    if (counter % 250 == 0)
    {
        if (seconds > 5)
        {
            seconds--;
            playTone(100, 1);
            printf("Seconds = %d \n", seconds);
        }
        else
        {
            if (seconds == 5)
                    {playTone(100, 10);
                    printf("Seconds = %d \n", seconds);
                    }
            if (seconds == 4)
                    {playTone(500, 10);
                    printf("Seconds = %d \n", seconds);
                    }
            if (seconds == 3)
                    {playTone(1000, 10);
                    lightUpOneLed(1);
                    printf("Seconds = %d \n", seconds);
                    }
            if (seconds == 2)
                    {playTone(2000, 10);
                    lightUpOneLed(2);
                    printf("Seconds = %d \n", seconds);
                    }
            if (seconds == 1)
                    {playTone(4000, 10);
                    lightUpOneLed(3);
                    printf("Seconds = %d \n", seconds);
                    }
            if (seconds == 0)
                    {playTone(50, 1);
                    lightUpOneLed(4);
                    printf("Seconds = %d \n", seconds);
                    cli();
                stopTimer(2);
            writeStringAndWait("BOOM",20000);
                    }    
            seconds--;
        }
    }
}

void deactivation()
{
    if (buttonPushed(1) == 1)
    {
        button1 = 1;
        printf("Button1 pushed \n");
        if (buttonPushed(2) == 1)
        {
            button2 = 1;
            printf("Button2 pushed \n");
            if (buttonPushed(3) == 1)
            {
                button3 = 1;
                printf("Button3 pushed \n");

                if ((button1 == 1) && (button2 == 1) && (button3 == 1))
                {
                    printf("3: Deactivation complete \n");
                    stopTimer(2);
                    cli();
                }
            }
        }
    }
    //     else if (buttonReleased(3) || buttonReleased(1))
    //     {
    //         button1 = 0;
    //         printf("1: Deactivation failed \n");
    //     }
    // }

    // if ((button1 == 1) && (button2 == 1))
    // {

    //     else if (buttonReleased(2) || buttonReleased(1))
    //     {
    //         button1 = 0;
    //         button2 = 0;
    //         printf("2: Deactivation failed \n");
    //     }
    // }

    // else
    // {
    //     button1 = 0;
    //     button2 = 0;
    //     button3 = 0;
    //     printf("4: Deactivation failed \n");
    // }
}

// transformation and scaler from the 0-1023 to a 10-240 scale
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
// from arduino official website. its the map() function

int main()
{
    initADC();
    initDisplay();
    initUSART();
    enableBuzzer();
    enableAllLeds();
    while (1)
    {
        analogToDigital();
        adcValue = ADC;
        seconds = map(adcValue, 0, 1023, 10, 240);
        writeNumberAndWait(seconds, 100);

        if (buttonPushed(1) == 1)
            break;
    }
    initTimer(2, 2, 256);
    enableOCRA(2, 249);
    while (1)
    {

            writeNumberAndWait(seconds, 100);
            // deactivation();

        
    }
    return 0;
}