#include "JoystickDriver.c"

TJoystick joystick;
void Initialization();
task Autonomous();
task Human_Control();

void stopMotors()
{
  motor[motorA] = 0;
  motor[motorB] = 0;
  motor[motorC] = 0;
  FTCMotor[motorA] = 0;
  FTCMotor[motorB] = 0;
}

task main()
{
  stopMotors();
  Initialization();
  wait1Msec(1000);

#if defined(bUserControlTestModeOnly)

	// Enables unlimited testing of user control mode. Does not look at the "stop" flag or the
	// autonomous vs user mode flag. NO timeout to end user control phase.

	#warning "*************************************************************************************"
	#warning "*** Configured for 'USER MODE' testing. Will not operate in live competiton mode  ***"
	#warning "*************************************************************************************"

	StartTask(Human_Control);
	while (true)
	{
		wait1Msec(10000);
	}

#else

	// Real competition control mode

  while (joystick.bStopPgm)
  {
    getJoystickSettings(joystick);
    nxtDisplayTextLine(2, "Standing By");
    wait1Msec(50);
  }

  if (!joystick.bUserMode) // Autonomous Mode or skip to human control
  {
    StartTask(Autonomous);
    while(true)
    {
      getJoystickSettings(joystick);
      if (joystick.bStopPgm)
        break;
      if (joystick.bUserMode)
				break;
      wait1Msec(50);
    }
    StopTask(Autonomous);
  }

  while (joystick.bStopPgm)
  {
    stopMotors();
    getJoystickSettings(joystick);
    nxtDisplayTextLine(2, "Standing By");
    wait1Msec(50);
  }

  StartTask(Human_Control);
  while(true)
  {
    getJoystickSettings(joystick);
    if (joystick.bStopPgm)
			break;
    wait1Msec(50);
  }
  StopTask(Human_Control);
  stopMotors();
#endif
}
