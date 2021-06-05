#include <ERO.h>
#include <EROHardware.h>

ERO BoBot(motorPin, signalPin, BEEPER, SPEED_CTRL);

void setup()
{
    BoBot.begin();
}

void loop()
{
    BoBot.leftSignal("OFF");
    BoBot.rightSignal("OFF");
    delay(1000);

    BoBot.leftSignal("ON");
    BoBot.rightSignal("ON");
    delay(1000);
}
