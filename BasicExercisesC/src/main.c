#define __DELAY_BACKWARD_COMPATIBLE__ 
#include <util/delay.h> 
#include <avr/io.h> 

#include <led.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 3
void blinker(int ledNumber,int blinkCount)
  {
    for(int i = 0; i <= blinkCount; i++){
    lightUpOneLed(ledNumber);
    _delay_ms(500);
    lightDownOneLed(ledNumber);
  } 
  }

int main(){
  enableAllLeds();
  lightDownAllLeds();

  // 1
  countDown();


  // 2
  for(int i = 0; i <= 10; i++){
    lightUpOneLed(0);
    _delay_ms(500);
    lightDownOneLed(0);
  } 

  // 3
  blinker(3,10);

  // 4
  lightDownAllLeds();
  int burnTime = 10;

  while (burnTime != 1000)
  {
    lightUpOneLed(2);
    _delay_ms(burnTime);
    lightDownOneLed(2);
    burnTime = burnTime+50;
  };


  // 5
  time_t t; 
  srand ((unsigned) time (& t));

  int ledArray[10];

  for (int i = 0; i <= 10; i++)
  {
    ledArray[i] = (rand() % 4);
  }
  for (int i = 0; i < 10; i++)
  {
    lightToggleOneLed(ledArray[i]);
  }
  
  // 6
  int ledArray[10];

  for (int i = 0; i <= 10; i++)
  {
    ledArray[i] = (rand() % 4);
  }

  return 0;
}
// minimum + (rand() % (maximum – minimum + 1)); 
