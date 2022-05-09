#include <Arduino.h>


byte leds = 0;


void setup() 
{
  pinMode(PD4, OUTPUT);
  pinMode(PB0, OUTPUT);  
  pinMode(PD7, OUTPUT);
  Serial.begin(9600);
  while (! Serial); // Wait until Serial is ready - Leonardo
  Serial.println("A");
}
void updateShiftRegister(){
  digitalWrite(PD4, LOW);
  shiftOut(PB0, PD7, LSBFIRST, 0);
  digitalWrite(PD4, HIGH);
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 'x')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}