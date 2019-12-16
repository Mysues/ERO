#include <ERO.h>
#include <EROBLE.h>
#include "Hardware.h"

ERO BoBot(motorPin, signalPin, BEEPER, SPEED_CTRL);
EROBLE ble(RX_PIN, TX_PIN, &GamePad);

void setup()
{
  Serial.begin(9600);
  ble.begin(9600);
  BoBot.begin();
}

void loop()
{
  if(ble.available()>7)
  {
    ble.process();
  }

  if(GamePad.UP){
    BoBot.forward(50);
  }
  else if(GamePad.DOWN){
    BoBot.backward(50);
  }
  else{
    BoBot.stop();
  }
}