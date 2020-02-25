const int LeftLeg[2] = {green1Pin, blue1Pin};
// const int RightLeg[2] = {green2Pin, blue2Pin};
bool CURRENT_DIRECTION;

const int DIRECTION_UP = 1;
const int DIRECTION_DOWN = 0;
const double turnsPerCmRatio = 6.25;

unsigned CURRENT_LEFT_LEGG_POSITION = 0;
unsigned CURRENT_RIGHT_LEGG_POSITION = 0;

void legg1greenRisingInterrupt();
void legg1greenFallingInterrupt();
void legg1blueRisingInterrupt();
void legg1blueFallingInterrupt();


void legg1greenRisingInterrupt()
{

  if(CURRENT_DIRECTION){
    CURRENT_LEFT_LEGG_POSITION += 1;
  } else
  {
    CURRENT_LEFT_LEGG_POSITION -= 1;
  }
}

void legg1blueRisingInterrupt()
{
  byte greenStatus = digitalRead(green1Pin);
  if(greenStatus == HIGH){
    CURRENT_DIRECTION = DIRECTION_DOWN;
  } else {
      CURRENT_DIRECTION = DIRECTION_UP;
  }
}
void legg1blueFallingInterrupt()
{

}