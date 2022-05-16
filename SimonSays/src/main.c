#include <Arduino.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#include <led.h>
#include <button.h>
#include <usart.h>
#include <time.h>


void correct(){
  for (int i = 0; i < 4; i++)
  {
    lightToggleOneLed(3);
    _delay_ms(500);
  }
  
}

bool test(int buttonNumber){
  while(1){
    if (( PINC & ( 1 << PC1 )) == 0 )
    {
      return true;
      break;
    }
    if (( PINC & ( 1 << (PC1 + buttonNumber) )) == 0 )
    {
      return false;
      break;
    }
    if (( PINC & ( 1 << (PC1 + buttonNumber) )) == 0 )
    {
      return false;
      break;
    }
  }
}

bool patternOne(){
  lightUpOneLed(0);
  lightDownOneLed(0);
  _delay_ms(1000);
  lightUpOneLed(2);
  lightDownOneLed(2);
  _delay_ms(1000);

  if(test(0)){
    printf("You pressed button 1, Correct!\n");
  }
  else
  {
    printf("You pressed the wrong button, Incorrect!\n");
    return false;
  }

  if(test(2)){
    printf("You pressed button 3, Correct!\n");
    return true;
  }
  else
  {
    printf("You pressed the wrong button, Incorrect!\n");
    return false;
  }
}
// void patternTwo(){
//   lightUpOneLed(0);
//   lightToggleOneLed(0);
//   _delay_ms(1000);
//   lightUpOneLed(2);
//   lightToggleOneLed(2);
//   _delay_ms(1000);
//   lightUpOneLed(1);
//   lightToggleOneLed(1);
//   _delay_ms(1000);
//   lightDownAllLeds();
// }
// void patternThree(){
//   lightUpOneLed(1);
//   lightToggleOneLed(1);
//   _delay_ms(1000);
//   lightUpOneLed(0);
//   lightToggleOneLed(0);
//   _delay_ms(1000);
//   lightUpOneLed(2);
//   lightToggleOneLed(2);
//   _delay_ms(1000);
//   lightUpOneLed(2);
//   lightToggleOneLed(2);
//   _delay_ms(1000);
//   lightDownAllLeds();
// }

void endPattern(){
  printf("end of pattern");
  for (int i = 0; i < 3; i++)
  {
    lightToggleOneLed(1);
    lightToggleOneLed(2);
    _delay_ms(500);
  } 
}

void blinkingLED(){
  while(1){
  lightUpOneLed(3);
  _delay_ms(1000);
  lightDownOneLed(3);
  _delay_ms(1000);
  }
}

int main(){
  initUSART();
  enableAllButtons();
  enableAllLeds();
  lightDownAllLeds();

  printf("Press Button 1 to start the game\n");
  while(1){
    lightUpOneLed(3);
    _delay_ms(1000);
    lightDownOneLed(3);
    _delay_ms(1000);

    if (( PINC & ( 1 << PC1 )) == 0 )
    {
      break;
    }
  }

  printf("Game Started\n");
  lightDownAllLeds();
  patternOne();
  endPattern();
  
}