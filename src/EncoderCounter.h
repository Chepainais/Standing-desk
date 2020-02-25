// const int LeftLeg[2] = {green1Pin, blue1Pin};
// const int RightLeg[2] = {green2Pin, blue2Pin};
class EncoderCounter {
  public:
     int greenPin, bluePin;

public: bool CURRENT_DIRECTION;

const int DIRECTION_UP = 1;
const int DIRECTION_DOWN = 0;
const double turnsPerCmRatio = 6.25;

unsigned CURRENT_POSITION = 0;

public: 
EncoderCounter (int greenPin, int bluePin)
{

}

public: 
void ICACHE_RAM_ATTR  greenRisingInterrupt()
{

  if(CURRENT_DIRECTION){
    CURRENT_POSITION += 1;
  } else
  {
    CURRENT_POSITION -= 1;
  }
}

public: 
void ICACHE_RAM_ATTR  blueRisingInterrupt()
{
  byte greenStatus = digitalRead(greenPin);
  if(greenStatus == HIGH){
    CURRENT_DIRECTION = DIRECTION_DOWN;
  } else {
      CURRENT_DIRECTION = DIRECTION_UP;
  }
}

};