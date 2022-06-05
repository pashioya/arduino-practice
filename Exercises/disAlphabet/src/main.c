#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <usart.h>
#include <display.h>



int main(){
  initDisplay();

  writeStringAndWait("dang", 1000);
  writeStringAndWait("you", 1000);
  writeStringAndWait("are", 1000);
  writeStringAndWait("dumb", 1000);

  
  
}