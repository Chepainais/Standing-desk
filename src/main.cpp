#include <Arduino.h>
#include "EncoderCounter.h"

const int green1Pin = 12;
const int blue1Pin = 13;
const int green2Pin = 12;
const int blue2Pin = 13;

unsigned MIN_POSITION = 0; // sould be set manually from controller (Hold programm button + btn1)
unsigned MAX_POSITION = 2000; // sould be set manually from controller (Hold programm button + btn2)
EncoderCounter encoder (green1Pin, blue1Pin);

void ICACHE_RAM_ATTR l1gI();
void ICACHE_RAM_ATTR l1bI();
void setup()
{
  // @TODO get last leg position from eeprom

  // @TODO get MAX / MIN leg position from EEPROM
  Serial.begin(9600);
  pinMode(green1Pin, INPUT_PULLUP);
  pinMode(blue1Pin, INPUT_PULLUP);
  pinMode(green2Pin, INPUT_PULLUP);
  pinMode(blue2Pin, INPUT_PULLUP);
  // ESP does not support multiple Interrupts to one pin (seccond one will overwrite the first one). So we should use only RISING interrupt
  attachInterrupt(green1Pin, l1gI, RISING);
  attachInterrupt(blue1Pin, l1bI, RISING);
}
void ICACHE_RAM_ATTR   l1gI()
{
    encoder.greenRisingInterrupt();
}
void ICACHE_RAM_ATTR  l1bI()
{
    encoder.blueRisingInterrupt();
}
void loop()
{
  Serial.write("Current position ");
  Serial.print(encoder.CURRENT_POSITION);
  Serial.write("\n");
  delay(1000);
  // put your main code here, to run repeatedly:
}