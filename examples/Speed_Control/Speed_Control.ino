#include <ERO.h>
#include <EROHardware.h>

ERO BoBot(&EROHardware);

void setup()
{
  BoBot.begin();
}

void loop()
{
  int speed = BoBot.speedCtrl();
  BoBot.forward(speed);
}
