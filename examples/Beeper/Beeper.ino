#include <ERO.h>
#include <EROHardware.h>

ERO BoBot(&EROHardware);

void setup()
{
    BoBot.begin();
}

void loop()
{
    BoBot.beeper("ON", 1);

    BoBot.beeper("OFF", 1);
}
