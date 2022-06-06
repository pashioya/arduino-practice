#ifndef timer_c

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <usart.h>

void mode0(int mode)
{
    switch (mode)
    {
    case 0:
        TCCR0A &= ~(_BV(WGM00) | _BV(WGM01));
        TCCR0B &= ~(_BV(WGM02));
        break;
    case 1:
        TCCR0A |= _BV(WGM00);
        break;
    case 2:
        TCCR0A |= _BV(WGM01);
    case 3:
        TCCR0A |= _BV(WGM00) | _BV(WGM01);
    case 4:
        TCCR0B |= _BV(WGM02);
    case 5:
        TCCR0A |= _BV(WGM00);
        TCCR0B |= _BV(WGM02);
    case 6:
        TCCR0A |= _BV(WGM01);
        TCCR0B |= _BV(WGM02);
    case 7:
        TCCR0A |= _BV(WGM00) | _BV(WGM01);
        TCCR0B |= _BV(WGM02);
    default:
        return;
    }
}
void mode1(int mode)
{
    switch (mode)
    {
    case 0:
        TCCR1A &= ~(_BV(WGM10) | _BV(WGM11));
        TCCR1B &= ~(_BV(WGM12));
        break;
    case 1:
        TCCR1A |= _BV(WGM10);
        break;
    case 2:
        TCCR1A |= _BV(WGM11);
    case 3:
        TCCR1A |= _BV(WGM10) | _BV(WGM11);
    case 4:
        TCCR1B |= _BV(WGM12);
    case 5:
        TCCR1A |= _BV(WGM10);
        TCCR1B |= _BV(WGM12);
    case 6:
        TCCR1A |= _BV(WGM11);
        TCCR1B |= _BV(WGM12);
    case 7:
        TCCR1A |= _BV(WGM10) | _BV(WGM11);
        TCCR1B |= _BV(WGM12);
    default:
        return;
    }
}
void mode2(int mode)
{
    switch (mode)
    {
    case 0:
        TCCR2A &= ~(_BV(WGM20) | _BV(WGM21));
        TCCR2B &= ~(_BV(WGM22));
        break;
    case 1:
        TCCR2A |= _BV(WGM20);
        break;
    case 2:
        TCCR2A |= _BV(WGM21);
    case 3:
        TCCR2A |= _BV(WGM20) | _BV(WGM21);
    case 4:
        TCCR2B |= _BV(WGM22);
    case 5:
        TCCR2A |= _BV(WGM20);
        TCCR2B |= _BV(WGM22);
    case 6:
        TCCR2A |= _BV(WGM21);
        TCCR2B |= _BV(WGM22);
    case 7:
        TCCR2A |= _BV(WGM20) | _BV(WGM21);
        TCCR2B |= _BV(WGM22);
    default:
        return;
    }
}

void stopTimer(int timer)
{
    switch (timer)
    {
    case 0:
        TCCR0B &= ~(_BV(CS02) | _BV(CS01) | _BV(CS00));
        break;
    case 1:
        TCCR1B &= ~(_BV(CS12) | _BV(CS11) | _BV(CS10));
        break;
    case 2:
        TCCR2B &= ~(_BV(CS22) | _BV(CS21) | _BV(CS20));
        break;
    default:
        break;
    }
}

void prescaler0(int scale)
{
    switch (scale)
    {
    case 0:
        stopTimer(0);
        break;
    case 1:
        TCCR0B |= _BV(CS00);
        break;
    case 8:
        TCCR0B |= _BV(CS01);
        break;
    case 64:
        TCCR0B |= _BV(CS02);
        break;
    case 128:
        TCCR0B |= (_BV(CS02) | _BV(CS00));
        break;
    case 256:
        TCCR0B |= (_BV(CS02) | _BV(CS01));
        break;
    case 1024:
        TCCR0B |= (_BV(CS02) | _BV(CS00) | _BV(CS01));
        break;
    default:
        break;
    }
}
void prescaler1(int scale)
{
    switch (scale)
    {
    case 0:
        stopTimer(1);
        break;
    case 1:
        TCCR1B |= _BV(CS10);
        break;
    case 8:
        TCCR1B |= _BV(CS11);
        break;
    case 64:
        TCCR1B |= _BV(CS12);
        break;
    case 128:
        TCCR1B |= (_BV(CS12) | _BV(CS10));
        break;
    case 256:
        TCCR1B |= (_BV(CS12) | _BV(CS11));
        break;
    case 1024:
        TCCR1B |= (_BV(CS12) | _BV(CS10) | _BV(CS11));
        break;
    default:
        break;
    }
}
void prescaler2(int scale)
{
    switch (scale)
    {
    case 0:
        stopTimer(2);
        break;
    case 1:
        TCCR2B |= _BV(CS20);
        break;
    case 8:
        TCCR2B |= _BV(CS21);
        break;
    case 64:
        TCCR2B |= _BV(CS22);
        break;
    case 128:
        TCCR2B |= (_BV(CS22) | _BV(CS20));
        break;
    case 256:
        TCCR2B |= (_BV(CS22) | _BV(CS21));
        break;
    case 1024:
        TCCR2B |= (_BV(CS22) | _BV(CS20) | _BV(CS21));
        break;
    default:
        break;
    }
}

void initTimer(int timer, int mode, int scalefactor)
{
    switch (timer)
    {
    case 0:
        // STEP 1: choose the WAVE FORM and by consequence the Mode of Operation
        mode0(mode);
        // STEP 2: *always* set a PRESCALER,
        prescaler0(scalefactor);
        break;
    case 1:
        mode1(mode);
        prescaler1(scalefactor);
        break;
    case 2:
        mode2(mode);
        prescaler2(scalefactor);
        break;
    default:
        break;
    }
    sei();
    // dont forget to activate the interupts
    // enbleOCRA(timer);
    // enbleOVF(timer);
}



void enableOCRA(int timer, int OCRA)
{
    // dont forget to set OCRXA
    switch (timer)
    {
    case 0:
        TIMSK0 |= _BV(OCIE0A);
        OCR0A = OCRA;
        break;
    case 1:
        TIMSK1 |= _BV(OCIE1A);
        OCR1A = OCRA;
        break;
    case 2:
        TIMSK2 |= _BV(OCIE2A);
        OCR2A = OCRA;
        break;
    default:
        break;
    }
}
void enableOVF(int timer)
{
    switch (timer)
    {
    case 0:
        TIMSK0 |= _BV(TOIE0);
        break;
    case 1:
        TIMSK1 |= _BV(TOIE0);
        break;
    case 2:
        TIMSK2 |= _BV(TOIE0);
        break;
    default:
        break;
    }
}
#endif