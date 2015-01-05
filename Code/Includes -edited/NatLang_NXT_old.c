/*--------------------------------------*\
|*	- Natural Language for NXT -		*|
|*                                      *|
|*	This file includes all of the 		*|
|*	Natural Language functions for NXT.	*|
\*---------------------------------4246-*/

#pragma systemFile            	// eliminates warning for "unreferenced" functions
#include "JoystickDriver.c"		// for use with joystick commands

// enum for RIGHT and LEFT direction:
typedef enum
{
	right = 0,
	left  = 1
}tDirections;

// enum for NXT buttons:
typedef enum
{
	cancelBtnNXT = 0,
	rightBtnNXT  = 1,
	leftBtnNXT   = 2,
	centerBtnNXT = 3
}tNxtButtons;

// enum for Robot Types:
typedef enum
{
	none		= 0,
	rembot    = 1
}tRobotType;


/*********************\
|*  SETUP FUNCTIONS  *|
\*********************************************************************************************************************************************/

//-------------------------------------------| RobotType |--------------------------------------------
#ifndef _ROBOTTYPE_H_GUARD
#define _ROBOTTYPE_H_GUARD

void robotType(tRobotType type = none)
{
	// MOTORS:
	if(type == none)	// NONE
	{
		bMotorReflected[motorB] = false;
		bMotorReflected[motorC] = false;
		return; // skip sensors setup
	}

	// SENSORS:
	if(type == rembot)   // REMBOT
	{
		if(SensorType[S1] == sensorNone)
		{
			SensorType[S1] = sensorTouch;
		}

		if(SensorType[S2] == sensorNone)
		{
			SensorType[S2] = sensorSoundDB;
		}

		if(SensorType[S3] == sensorNone)
		{
			SensorType[S3] = sensorLightActive;
		}

		if(SensorType[S4] == sensorNone)
		{
			SensorType[S4] = sensorSONAR;
		}
	}
}

#endif
//----------------------------------------------------------------------------------------------------

/*********************************************************************************************************************************************\
|*  END SETUP FUNCTIONS  *|
\*************************/
/************************\
|*  MOVEMENT FUNCTIONS  *|
\*********************************************************************************************************************************************/

//-------------------------------------------| startMotor |-------------------------------------------
#ifndef _STARTMotorTypes_H_GUARD
#define _STARTMotorTypes_H_GUARD

void startMotor(tMotor motorPort = motorA, byte speed = 75)
{
	motor[motorPort] = speed;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| StopMotor |--------------------------------------------
#ifndef _STOPMOTOR_H_GUARD
#define _STOPMOTOR_H_GUARD

void stopMotor(tMotor motorPort = motorA)
{
	motor[motorPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------


/********************************************************************************************************************************************\
|*  END MOVEMENT FUNCTIONS  *|
\****************************/
/**********************\
|*  "WAIT" FUNCTIONS  *|
\********************************************************************************************************************************************/

//----------------------------------------------| Wait |----------------------------------------------
#ifndef _WAIT_H_GUARD
#define _WAIT_H_GURAD

void wait(float waitTime = 1.0)
{
	long mins = (abs(waitTime) / 60.0);
	long secs = ((abs(waitTime) * 1000) / 1000) - (mins * 60);
	long millisecs = (abs(waitTime) * 1000) - ((abs((long)waitTime) * 1000));

	for(long i=0; i<mins; i++)      // minutes loop
	{
		sleep(60000);
	}

	for(long j=0; j<secs; j++)      // seconds loop
	{
		wait1Msec(1000);
	}

	wait1Msec(millisecs);
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| WaitInMilliseconds |---------------------------------------
#ifndef _WAITINMILLISECONDS_H_GUARD
#define _WAITINMILLISECONDS_H_GUARD

void waitInMilliseconds(long waitTime = 1000)
{
	wait1Msec((long)waitTime);
}

#endif
//----------------------------------------------------------------------------------------------------
/*********************************************************************************************************************************************\
|* END "WAIT" FUNCTIONS  *|
\*************************/
/***********************\
|*  "UNTIL" FUNCTIONS  *|
\*********************************************************************************************************************************************/

//-------------------------------------------| UntilTouch |-------------------------------------------
#ifndef _UNTILTOUCH_H_GUARD
#define _UNTILTOUCH_H_GUARD

void untilTouch(tSensors sensorPort = S1)
{
	while(SensorValue[sensorPort] != 1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| UntilRelease |------------------------------------------
#ifndef _UNTILRELEASE_H_GUARD
#define _UNTILRELEASE_H_GUARD

void untilRelease(tSensors sensorPort = S1)
{
	while(SensorValue[sensorPort] != 0){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilBump |--------------------------------------------
#ifndef _UNTILBUMP_H_GUARD
#define _UNTILBUMP_H_GUARD

void untilBump(tSensors sensorPort = S1, int delayTimeMS = 10)
{
  while(SensorValue[sensorPort] != 1)
  		wait1Msec(1);

  int tempvar = delayTimeMS;
  wait1Msec(tempvar);

  while(SensorValue[sensorPort] == 1)
  		wait1Msec(1);
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilSonarLessThan |---------------------------------------
#ifndef _UNTILSONARLESSTHAN_H_GUARD
#define _UNTILSONARLESSTHAN_H_GUARD

void untilSonarLessThan(short distance = 30, tSensors sensorPort = S4)
{
	while(SensorValue[sensorPort] > distance || SensorValue[sensorPort] == 255){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| UntilSonarGreaterThan |--------------------------------------
#ifndef _UNTILSONARGREATERTHAN_H_GUARD
#define _UNTILSONARGREATERTHAN_H_GUARD

void untilSonarGreaterThan(short distance = 30, tSensors sensorPort = S4)
{
	while(SensorValue[sensorPort] < distance || SensorValue[sensorPort] == 255){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| UntilButtonPress |----------------------------------------
#ifndef _UNTILBUTTONPRESS_H_GUARD
#define _UNTILBUTTONPRESS_H_GUARD

void untilButtonPress(short button = centerBtnNXT)
{
	while(true)
	{
		if(nNxtButtonPressed == button)
		{
			break;
		}
		wait1Msec(1);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilDark |--------------------------------------------
#ifndef _UNTILDARK_H_GUARD
#define _UNTILDARK_H_GUARD

void untilDark(int threshold = 30, tSensors sensorPort = S3)
{
	while(SensorValue[sensorPort] > threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilLight |-------------------------------------------
#ifndef _UNTILLIGHT_H_GUARD
#define _UNTILLIGHT_H_GUARD

void untilLight(int threshold = 30, tSensors sensorPort = S3)
{
	while(SensorValue[sensorPort] < threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| UntilSoundGreaterThan |--------------------------------------
#ifndef _UNTILSOUNDGREATER_H_GUARD
#define _UNTILSOUNDGREATER_H_GUARD

void untilSoundGreaterThan(int threshold = 50, tSensors sensorPort = S2)
{
	while(SensorValue[sensorPort] <= threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilSoundLessThan |---------------------------------------
#ifndef _UNTILSOUNDLESS_H_GUARD
#define _UNTILSOUNDLESS_H_GUARD

void untilSoundLessThan(int threshold = 50, tSensors sensorPort = S2)
{
	while(SensorValue[sensorPort] >= threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| UntilRotations |-----------------------------------------
#ifndef _UNTILROTATIONS_H_GUARD
#define _UNTILROTATIONS_H_GUARD

void untilRotations(float rotations = 1.0, tMotor motorPort = motorB)
{
	nMotorEncoder[motorPort] = 0;

	while(nMotorEncoder[motorPort] < (abs(rotations) * 360.0)  &&  nMotorEncoder[motorPort] > (abs(rotations) * (360.0 * -1.0))){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilEncoderCounts |---------------------------------------
#ifndef _UNTILENCODERCOUNTS_H_GUARD
#define _UNTILENCODERCOUNTS_H_GUARD

void untilEncoderCounts(long distance = 360, tMotor motorPort = motorB)
{
	nMotorEncoder[motorPort] = 0;

	while(nMotorEncoder[motorPort] < (abs(distance))  &&  nMotorEncoder[motorPort] > (abs(distance) * -1)){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
|*  END "UNTIL" FUNCTIONS  *|
\***************************/
/****************************\
|*  ROBOT MOTION FUNCTIONS  *|
\*******************************************************************************************************************************************/

//--------------------------------------------| Forward |---------------------------------------------
#ifndef _FORWARD_H_GUARD
#define _FORWARD_H_GUARD

void forward(byte speed = 75)
{
	motor[motorB] = abs(speed);
	motor[motorC] = abs(speed);
}

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| Backward |--------------------------------------------
#ifndef _BACKWARD_H_GUARD
#define _BACKWARD_H_GUARD

void backward(byte speed = -75)
{
	motor[motorB] = abs(speed) * -1;
	motor[motorC] = abs(speed) * -1;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| SwingTurn |--------------------------------------------
#ifndef _SWINGTURN_H_GUARD
#define _SWINGTURN_H_GUARD

void swingTurn(tDirections direction = right, byte speed = 75)
{
	if(direction == left)      	// LEFT
	{
		if(speed >= 0)
		{
			motor[motorB] = speed;
			motor[motorC] = 0;
		}
		else if(speed < 0)
		{
			motor[motorB] = 0;
			motor[motorC] = speed;
		}
	}
	else if(direction == right) 	// RIGHT
	{
		if(speed >= 0)
		{
			motor[motorB] = 0;
			motor[motorC] = abs(speed);
		}
		else if(speed < 0)
		{
			motor[motorB] = speed;
			motor[motorC] = 0;
		}
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| PointTurn |--------------------------------------------
#ifndef _POINTTURN_H_GUARD
#define _POINTTURN_H_GUARD

void pointTurn(tDirections direction = right, byte speed = 75)
{
	if(direction == left)      	// LEFT
	{
		motor[motorB] = abs(speed);
		motor[motorC] = abs(speed) * -1;
	}
	else if(direction == right) 	// RIGHT
	{
		motor[motorB] = abs(speed) * -1;
		motor[motorC] = abs(speed);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------------| Stop |----------------------------------------------
#ifndef _STOP_H_GUARD
#define _STOP_H_GUARD

void stop()
{
	motor[motorB] = 0;
	motor[motorC] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| LineTrackTIME |------------------------------------------
#ifndef _LINETRACKTIME_H_GUARD
#define _LINETRACKTIME_H_GUARD

void lineTrackForTime(float trackTime = 5.0, int threshold = 45, tSensors sensorPort = S3)
{
	float timeStart = ((float)nPgmTime / 1000);

	while(((float)nPgmTime / 1000) - timeStart < trackTime)
	{
		//nxtDisplayBigTextLine(3, "%0.4f", ((float)nPgmTime / 1000));  // debug
		//Line Follow:
		if(SensorValue[sensorPort] < threshold)        // DARK:
		{
			motor[motorB] = 25;
			motor[motorC] = 55;
		}
		else if(SensorValue[sensorPort] >= threshold)  // LIGHT:
		{
			motor[motorB] = 55;
			motor[motorC] = 25;
		}
		wait1Msec(1);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| LineTrackROTATIONS |---------------------------------------
#ifndef _LINETRACKROTS_H_GUARD
#define _LINETRACKROTS_H_GUARD

void lineTrackForRotations(float rotations = 3.0, int threshold = 45, tSensors sensorPort = S3)
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;

	while((nMotorEncoder[motorB] < (rotations * 360))  &&  (nMotorEncoder[motorC] < (rotations * 360)))
	{
		//nxtDisplayBigTextLine(3, "%0.4f", ((float)nPgmTime / 1000));  // debug
		//Line Follow:
		if(SensorValue[sensorPort] < threshold)        // DARK:
		{
			motor[motorB] = 25;
			motor[motorC] = 55;
		}
		else if(SensorValue[sensorPort] >= threshold)  // LIGHT:
		{
			motor[motorB] = 55;
			motor[motorC] = 25;
		}
		wait1Msec(1);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| StartJoystickControl |----------------------------------
#ifndef _STARTJOYCONTROL_H_GUARD
#define _STARTJOYCONTROL_H_GUARD

void startJoystickControl()
{
	startTask(readMsgFromPC);
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| StopJoystickControl |-----------------------------------
#ifndef _STOPJOYCONTROL_H_GUARD
#define _STOPJOYCONTROL_H_GUARD

void stopJoystickControl()
{
	//Reset joystick values
	bool bUserModeTemp = joystick.UserMode;
	bool bStopPgmTemp = joystick.StopPgm;

	memset(joystickCopy, 0, sizeof(joystickCopy));

	joystick.UserMode = bUserModeTemp;
	joystick.StopPgm = bStopPgmTemp;
	joystick.joy1_TopHat = -1;
	joystick.joy2_TopHat = -1;
	stopTask(readMsgFromPC);
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| TankControl |-------------------------------------------
#ifndef _TANKCONTROL_H_GUARD
#define _TANKCONTROL_H_GUARD

void tankControl(short &rightJoystick = joystick.joy1_y2, short &leftJoystick = joystick.joy1_y1, short threshold = 10)
{
	getJoystickSettings(joystick);
	if(rightJoystick <= abs(threshold)  &&  rightJoystick >= (abs(threshold) * -1))
		motor[motorB] = 0;
	else
		motor[motorB] = rightJoystick;

	if(leftJoystick <= abs(threshold)  &&  leftJoystick >= (abs(threshold) * -1))
		motor[motorC] = 0;
	else
		motor[motorC] = leftJoystick;
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| ArcadeControl |------------------------------------------
#ifndef _ARCADECONTROL_H_GUARD
#define _ARCADECONTROL_H_GUARD

void arcadeControl(short &verticalJoystick = joystick.joy1_y2, short &horizontalJoystick = joystick.joy1_x2, short threshold = 10)
{
	getJoystickSettings(joystick);
	if( (verticalJoystick <= abs(threshold)  &&  verticalJoystick >= (abs(threshold) * -1))  &&
		(horizontalJoystick <= abs(threshold)  &&  horizontalJoystick >= (abs(threshold) * -1)))
	{
		motor[motorB] = 0;
		motor[motorC] = 0;
	}
	else
	{
		motor[motorB] = (verticalJoystick + horizontalJoystick) / 2;
		motor[motorC] = (verticalJoystick - horizontalJoystick) / 2;
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| MoveStraightROTATIONS |--------------------------------------
#ifndef _MOVESTRAIGHTROTS_H_GUARD
#define _MOVESTRAIGHTROTS_H_GUARD

void moveStraightForRotations(float rotations = 1.0, tMotor rightEncoderPort = motorB, tMotor leftEncoderPort = motorC)
{
	nMotorEncoder[rightEncoderPort] = 0;
	nMotorEncoder[leftEncoderPort]  = 0;

	while(nMotorEncoder[rightEncoderPort] < (abs(rotations) * 360))
	{
		if(nMotorEncoder[rightEncoderPort] == nMotorEncoder[leftEncoderPort])     // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightEncoderPort] = 75;		// Right Motor is run at power level 75
			motor[leftEncoderPort]  = 75;		// Left Motor is run at power level 75
		}
		else if(nMotorEncoder[rightEncoderPort] > nMotorEncoder[leftEncoderPort]) // If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightEncoderPort] = 50;		// Right Motor is run at power level 50
			motor[leftEncoderPort]  = 75;		// Left Motor is run at power level 75
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightEncoderPort] = 75;		// Right Motor is run at power level 75
			motor[leftEncoderPort]  = 50;		// Left Motor is run at power level 50
		}
		wait1Msec(1);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| MoveStraightTIME |----------------------------------------
#ifndef _MOVESTRAIGHTTIME_H_GUARD
#define _MOVESTRAIGHTTIME_H_GUARD

void moveStraightForTime(float seconds = 5.0, tMotor rightEncoderPort = motorB, tMotor leftEncoderPort = motorC)
{
	nMotorEncoder[rightEncoderPort] = 0;
	nMotorEncoder[leftEncoderPort] = 0;

	float timeStart = ((float)nPgmTime / 1000);

	while(((float)nPgmTime / 1000) - timeStart < seconds)
	{
		if(nMotorEncoder[rightEncoderPort] == nMotorEncoder[leftEncoderPort])     // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightEncoderPort] = 75;		// Right Motor is run at power level 75
			motor[leftEncoderPort]  = 75;		// Left Motor is run at power level 75
		}
		else if(nMotorEncoder[rightEncoderPort] > nMotorEncoder[leftEncoderPort]) // If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightEncoderPort] = 50;		// Right Motor is run at power level 50
			motor[leftEncoderPort]  = 75;		// Left Motor is run at power level 75
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightEncoderPort] = 75;		// Right Motor is run at power level 75
			motor[leftEncoderPort]  = 50;		// Left Motor is run at power level 50
		}
		wait1Msec(1);
	}
}

#endif
//----------------------------------------------------------------------------------------------------

/********************************************************************************************************************************************\
|*  END ROBOT MOTION FUNCTIONS  *|
\********************************/
