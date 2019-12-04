#include <ERO.h>
#include "Hardware.h"

ERO BoBot(motorPin, signalPin, BEEPER, SPEED_CTRL);

void setup()
{
    BoBot.begin();
}

void loop()
{
  int speed = BoBot.speedCtrl();
  BoBot.forward(speed);
}
