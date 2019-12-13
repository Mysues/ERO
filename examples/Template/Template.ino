#include <ERO.h>
#include "Hardware.h"

ERO __ERONAME__ (__MotorPinArray__, __SignalPinArray__, __BUZZERPIN__, _SPEED_CTRLPIN_);

void setup()
{
  __ERONAME__.begin();
}

void loop()
{
  __ERONAME__.leftSignal("ON");
  __ERONAME__.rightSignal("OFF");
  delay(_delayTime_);

  __ERONAME__.leftSignal("ON");
  __ERONAME__.rightSignal("OFF");

  delay(_delayTime_);
}
