#include <Arduino.h>

const int green1Pin = 12;
const int blue1Pin = 13;
const int green2Pin = 12;
const int blue2Pin = 13;

unsigned MIN_POSITION = 0; // sould be set manually from controller (Hold programm button + btn1)
unsigned MAX_POSITION = 2000; // sould be set manually from controller (Hold programm button + btn2)

#include "encoder_counter.h"

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
  attachInterrupt(green1Pin, legg1greenRisingInterrupt, RISING);
  attachInterrupt(blue1Pin, legg1blueRisingInterrupt, RISING);
}

void loop()
{
  Serial.write("Current position ");
  Serial.print(CURRENT_LEFT_LEGG_POSITION);
  Serial.write("\n");
  delay(200);
  // put your main code here, to run repeatedly:
}

