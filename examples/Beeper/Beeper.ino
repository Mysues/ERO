#include <ERO.h>
#include "Hardware.h"

ERO BoBot(motorPin, signalPin, BEEPER, SPEED_CTRL);

void setup()
{
    BoBot.begin();
}

void loop()
{
    BoBot.beeper("ON",1);

    BoBot.beeper("OFF",1);
}
