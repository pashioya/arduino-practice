#include <Arduino.h>

#include <util/delay.h>
#include <avr/io.h> 
#include <led.h>

void countDown(){
    lightUpOneLed(3);
    _delay_ms(1000);
    lightUpOneLed(2);
    _delay_ms(1000);
    lightUpOneLed(1);
    _delay_ms(1000);
    lightUpOneLed(0);
    _delay_ms(1000);
    lightDownAllLeds();
}


void morseA(){
    lightUpAllLeds();
    _delay_ms(1000);
    lightDownAllLeds();
    _delay_ms(500);
    lightUpAllLeds();
    _delay_ms(2000);
    lightDownAllLeds();
}
void morseB(){
    lightUpAllLeds();
    _delay_ms(2000);
    lightDownAllLeds();
    _delay_ms(1000);
    lightUpAllLeds();
    _delay_ms(500);
    lightDownAllLeds();
    _delay_ms(500);
    lightUpAllLeds();
    _delay_ms(500);
    lightDownAllLeds();
    _delay_ms(500);
    lightUpAllLeds();
    _delay_ms(500);
    lightDownAllLeds();
    _delay_ms(500);
}

void end(){
  lightUpOneLed(3);
  lightUpOneLed(0);
}
void endChar(){
  lightUpOneLed(2);
  lightUpOneLed(1);
}


int main() //Start of the program
{

  enableAllLeds();
  lightDownAllLeds();
  countDown();
  _delay_ms(1000);

  char tea[5] = "ABB";

  for (int i = 0; i < sizeof tea; i++)
  {
    switch (tea[i])
    {
    case 'A':
      morseA();
      endChar();
      _delay_ms(500);
      break;
    case 'B':
      morseB();
      endChar();
      _delay_ms(500);
      break;
    // case 'C':
    //   morseC();
    //   break;
    // case 'D':
    //   morseD();
    //   break;
    // case 'E':
    //   morseE();
    //   break;
    // case 'F':
    //   morseF();
    //   break;
    // case 'G':
    //   morseG();
    //   break;    
    default:
      break;
    }
  }
  lightDownAllLeds();
  end();
}


