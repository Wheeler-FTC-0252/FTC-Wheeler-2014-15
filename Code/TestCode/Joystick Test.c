#include "JoystickDriver.c"

task main()
{
	while (true){
		getJoystickSettings(joystick);
		writeDebugStreamLine("%d",joystick.joy1_Buttons);
	}
}
