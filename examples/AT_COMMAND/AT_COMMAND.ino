#include <ERO.h>
#include <EROBLE.h>
#include <EROHardware.h>

ERO BoBot(motorPin, signalPin, BEEPER, SPEED_CTRL);
EROBLE ble(RX_PIN, TX_PIN, &GamePad);

void setup()
{
  Serial.begin(9600);
  ble.begin(9600);
}

void loop()
{
  if (ble.available())
  {
    Serial.write(ble.read());
  }

  if (Serial.available())
  {
    ble.write(Serial.read());
  }
}
