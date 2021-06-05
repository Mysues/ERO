#include <ERO.h>
#include <EROHardware.h>

ERO BoBot(&EROHardware);

void setup()
{
    BoBot.begin();
}

void loop()
{
    BoBot.forward(100);
    delay(1000);

    BoBot.backward(100);
    delay(1000);

    BoBot.turnLeft(100);
    delay(1000);

    BoBot.turnRight(100);
    delay(1000);
}
