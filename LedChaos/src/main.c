#define __DELAY_BACKWARD_COMPATIBLE__ 
#include <util/delay.h> 
#include <avr/io.h> 

#include <led.h>


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main () {

  time_t t;
  
  srand((unsigned) time(& t));
  
  enableAllLeds();
  // lightUpAllLeds();
  lightDownAllLeds();

  // lightToggleOneLed(3);

  while (1) 
  {
    int lednumber= (rand() % 4 );
    lightToggleOneLed(lednumber);
    _delay_ms(rand() % 100);
  }

  
  
}
