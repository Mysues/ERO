#include <ERO.h>
#include <EROBLE.h>
#include <EROHardware.h>

ERO BoBot(&EROHardware);
EROBLE ble(&EROHardware, &GamePad);

void setup()
{
    Serial.begin(9600);
    ble.begin(9600);
    BoBot.begin();
}

void loop()
{
    ReceiveData();
    BoBot.loop();
}

void ReceiveData()
{
    if (ble.process())
        robotController();   
}

void robotController()
{
    robotKinematicControl();
    backLightControl();
    hornControl();
}

void robotKinematicControl()
{
    
    if (GamePad.UP)
    {
        BoBot.forward();
    }
    else if (GamePad.DOWN)
    {
        BoBot.backward();
    }
    else if (GamePad.LEFT)
    {
        BoBot.turnLeft();
    }
    else if (GamePad.RIGHT)
    {
        BoBot.turnRight();
    }
    else if (GamePad.MOTOR_STOP)
    {
        BoBot.stop();
    }
}

void backLightControl()
{
    if (GamePad.BACK_LIGHT)
    {
        BoBot.leftSignal("ON");
        BoBot.rightSignal("ON");
    }
    else
    {
        BoBot.leftSignal("OFF");
        BoBot.rightSignal("OFF");
    }
}

void hornControl()
{
    if (GamePad.HORN)
    {
        BoBot.beeper("ON");
    }
    else
    {
        BoBot.beeper("OFF");
    }
}