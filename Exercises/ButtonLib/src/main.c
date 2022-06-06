#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <button.h>
#include <led.h>

#define LED_PORT PORTB
#define BUTTON_PORT PORTC
#define BUTTON_PIN PINC
#define LED_DDR DDRB
#define BUTTON_DDR DDRC
#define BUTTON1 PC1
#define BUTTON2 PC2
#define BUTTON3 PC3
#define LED1 PB2
#define LED2 PB3
#define LED3 PB4
#define LED4 PB5

ISR(PCINT1_vect)
{
    if (buttonPushed(1) == 1)
    {
        lightToggleOneLed(1);
    }
    if (buttonPushed(2) == 1)
    {
        lightToggleOneLed(2);
    }
    if (buttonPushed(3) == 1)
    {
        lightToggleOneLed(3);
    }
}

int main()
{
    enableAllButtons();

    enableAllLeds();
    lightDownAllLeds();
    sei();
    while (1)
    {
        _delay_ms(1000);
    }
}
