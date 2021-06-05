#include <ERO.h>
#include <EROHardware.h>

ERO __ERONAME__(__ &EROHardware_);

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
