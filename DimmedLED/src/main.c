#include <util/delay.h> 
#include <avr/io.h> 
#include <led.h>
#include <button.h>
#include <usart.h>
#include <stdio.h>
int main() //Start of the program
{
    enableAllLeds();
    lightDownAllLeds();
    dimLed(0,10,1000);
    dimLed(1,30,2000);
    dimLed(2,50,3000);
    dimLed(3,70,4000);


}