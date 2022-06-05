#ifndef Button_c
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define BUTTON_PORT PORTC
#define BUTTON_PIN PINC
#define BUTTON_DDR DDRC
#define BUTTON1 PC1
#define BUTTON2 PC2
#define BUTTON3 PC3

void enableOneButton(int buttonNumber)
{
    buttonNumber = buttonNumber - 1;
    if (buttonNumber < 1 || buttonNumber > 3)
        return;

    BUTTON_DDR &= ~_BV(BUTTON1 + buttonNumber);
    BUTTON_PORT |= _BV(BUTTON1 + buttonNumber);

    PCICR |= _BV(PCIE1);
    PCMSK1 |= _BV(BUTTON1 + buttonNumber);
    sei();
}
void enableAllButtons()
{
    for (int i = 1; i < 3; i++)
    {
        enableOneButton(i);
    }
}

int buttonPushed(int button)
{
    switch (button)
    {
    case 1:
        button = BUTTON1;
        break;
    case 2:
        button = BUTTON2;
        break;
    case 3:
        button = BUTTON3;
        break;
    default:
        // wont do anything if incorrect button number input
        return 0;
    };
    // button is pressed (bit set to 0);
    if (bit_is_clear(BUTTON_PIN, button))
    {
        // We wait 1000 microseconds and check again (debounce!);
        _delay_us(1000);
        // button is pressed (bit is set to 0)?
        if (bit_is_clear(BUTTON_PIN, button))
        {
            return 1;
        }
    }
    return 0;
}

int buttonReleased(int button)
{
    switch (button)
    {
    case 1:
        button = BUTTON1;
        break;
    case 2:
        button = BUTTON2;
        break;
    case 3:
        button = BUTTON3;
        break;
    default:
        return 0;
    };
    // button released
    if (!bit_is_clear(BUTTON_PIN, button))
    {
        // We wait 1000 microseconds and check again (debounce!);
        _delay_us(1000);
        // button 0 is released (bit is set to 0)?
        if (!bit_is_clear(BUTTON_PIN, button))
        {
            return 1;
        }
    }
    return 0;
}

#endif