#include "JoystickDriver.c"

task main()
{
	int joyButtons_old=0;
	while (true){
		getJoystickSettings(joystick);
		if (joystick.joy1_Buttons!=joyButtons_old && joystick.joy1_Buttons!=0){
			writeDebugStreamLine("%d",joystick.joy1_Buttons);
		}
		joyButtons_old=joystick.joy1_Buttons;
	}
}
