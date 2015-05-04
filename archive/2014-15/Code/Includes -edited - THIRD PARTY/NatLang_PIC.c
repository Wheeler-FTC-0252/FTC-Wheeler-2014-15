/*------------------------------------------*\
|*	- Natural Language for VEX PIC -		*|
|*                                      	*|
|*	This file includes all of the 			*|
|*	Natural Language functions for VEX PIC.	*|
\*-------------------------------------4246-*/

#pragma systemFile            	// eliminates warning for "unreferenced" functions


// enum for RIGHT and LEFT direction:
typedef enum
{
  right = 0,
  left  = 1
}tDirections;

// enum for VEX LCD buttons:
typedef enum
{
  leftBtnVEX            = 1,
  centerBtnVEX          = 2,
  //leftANDcenterBtnVEX   = 3,
  rightBtnVEX           = 4//,
  //leftANDrightBtnVEX    = 5,
  //centerANDrightBtnVEX  = 6,
  //allBtnsVEX            = 7
}tVEXLCDButtons;

// enum for Robot Types:
typedef enum
{
  none		= 0,
  recbot	= 1,
  swervebot = 2,
  squarebot = 3,
}tRobotType;

// enum for LED (on or off):
typedef enum
{
	ledOff	= 0,
	ledOn	= 1
}tLedCommand;


/*********************\
|*  SETUP FUNCTIONS  *|
\*********************************************************************************************************************************************/

//-------------------------------------------| RobotType |--------------------------------------------
#ifndef _ROBOTTYPE_H_GUARD
#define _ROBOTTYPE_H_GUARD

void robotType(tRobotType type = none)
{
  if(type == 0)                   // None
  {
	bMotorReflected[port2] = false;
    bMotorReflected[port3] = false;
  }
  else if(type == 1 || type == 3) // Recbot + Squarebot
  {
    bMotorReflected[port2] = true;
    bMotorReflected[port3] = false;
  }
  else if(type == 2)              // Swervebot
  {
    bMotorReflected[port2] = false;
    bMotorReflected[port3] = true;
  }
}

#endif
//----------------------------------------------------------------------------------------------------

/*********************************************************************************************************************************************\
																													|*  END SETUP FUNCTIONS  *|
																													\*************************/
/************************\
|*  MOVEMENT FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| startMotor |-------------------------------------------
#ifndef _STARTMotorTypes_H_GUARD
#define _STARTMotorTypes_H_GUARD

void startMotor(tMotor motorPort = port6, signed byte speed = 95)
{
  motor[motorPort] = speed;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| StopMotor |--------------------------------------------
#ifndef _STOPMOTOR_H_GUARD
#define _STOPMOTOR_H_GUARD

void stopMotor(tMotor motorPort = port6)
{
  motor[motorPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| SetServo |--------------------------------------------
#ifndef _SETSERVO_H_GUARD
#define _SETSERVO_H_GUARD

void setServo(tMotor servoPort = port6, signed byte position = 0)
{
  motor[servoPort] = position;
}

#endif
//----------------------------------------------------------------------------------------------------

/********************************************************************************************************************************************\
																												|*  END MOVEMENT FUNCTIONS  *|
																												\****************************/
/**********************\
|*  "WAIT" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//----------------------------------------------| Wait |----------------------------------------------
#ifndef _WAIT_H_GUARD
#define _WAIT_H_GURAD

void wait(int waitTime = 1)
{
  int mins = (abs(waitTime) / 60);
  int time = ((abs(waitTime) % 60 ) * 1000);

  for(int i=0; i<mins; i++)      // minutes loop
  {
    wait10Msec(6000);
  }

  for(int j=0; j<time; j++)      // remainder loop
  {
    wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| WaitInMilliseconds |---------------------------------------
#ifndef _WAITINMILLISECONDS_H_GUARD
#define _WAITINMILLISECONDS_H_GUARD

void waitInMilliseconds(int waitTime = 1000)
{
  wait1Msec((int)waitTime);
}

#endif
//----------------------------------------------------------------------------------------------------
/******************************************************************************************************************************************\
																												|*  END "WAIT" FUNCTIONS  *|
																												\**************************/
/***********************\
|*  "UNTIL" FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| UntilTouch |-------------------------------------------
#ifndef _UNTILTOUCH_H_GUARD
#define _UNTILTOUCH_H_GUARD

void untilTouch(tSensors sensorPort)// = in4)
{
  while(SensorValue[sensorPort] != 1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//------------------------------------------| UntilRelease |------------------------------------------
#ifndef _UNTILRELEASE_H_GUARD
#define _UNTILRELEASE_H_GUARD

void untilRelease(tSensors sensorPort)// = in4)
{
  while(SensorValue[sensorPort] != 0){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilBump |--------------------------------------------
#ifndef _UNTILBUMP_H_GUARD
#define _UNTILBUMP_H_GUARD

void untilBump(tSensors sensorPort, int delayTimeMS = 10)// = in4)
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

void untilSonarLessThan(short distance, tSensors sensorPort)// = 30, tSensors sensorPort = in5)
{
  while(SensorValue[sensorPort] > distance || SensorValue[sensorPort] == -1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| UntilSonarGreaterThan |--------------------------------------
#ifndef _UNTILSONARGREATERTHAN_H_GUARD
#define _UNTILSONARGREATERTHAN_H_GUARD

void untilSonarGreaterThan(short distance, tSensors sensorPort)// = 30, tSensors sensorPort = in5)
{
  while(SensorValue[sensorPort] < distance || SensorValue[sensorPort] == -1){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------| UntilPotentiometerLessThan |-----------------------------------
#ifndef _UNTILPOTENTIOMETERLESSTHAN_H_GUARD
#define _UNTILPOTENTIOMETERLESSTHAN_H_GUARD

void untilPotentiometerLessThan(int position, tSensors sensorPort)// = 511, tSensors sensorPort = in6)
{
  while(SensorValue[sensorPort] > abs(position)){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------| UntilPotentiometerGreaterThan |----------------------------------
#ifndef _UNTILPOTENTIOMETERGREATERTHAN_H_GUARD
#define _UNTILPOTENTIOMETERGREATERTHAN_H_GUARD

void untilPotentiometerGreaterThan(int position, tSensors sensorPort)// = 511, tSensors sensorPort = in6)
{
  while(SensorValue[sensorPort] < abs(position)){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| UntilButtonPress |----------------------------------------
#ifndef _UNTILBUTTONPRESS_H_GUARD
#define _UNTILBUTTONPRESS_H_GUARD

void untilButtonPress(short button = centerBtnVEX)
{
  while(true)
  {
    if(nLCDButtons == button)
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

void untilDark(int threshold, tSensors sensorPort)// = 511, tSensors sensorPort = in8)
{
  while(SensorValue[sensorPort] < threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| UntilLight |-------------------------------------------
#ifndef _UNTILLIGHT_H_GUARD
#define _UNTILLIGHT_H_GUARD

void untilLight(int threshold, tSensors sensorPort)// = 511, tSensors sensorPort = in8)
{
  while(SensorValue[sensorPort] > threshold){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//-----------------------------------------| UntilRotations |-----------------------------------------
#ifndef _UNTILROTATIONS_H_GUARD
#define _UNTILROTATIONS_H_GUARD

void untilRotations(int rotations, tSensors sensorPort)// = 1, tSensors sensorPort = in2)
{
  SensorValue[sensorPort] = 0;

   while(abs(SensorValue[sensorPort]) < (abs(rotations) * 360)){wait1Msec(1);}
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| UntilEncoderCounts |---------------------------------------
#ifndef _UNTILENCODERCOUNTS_H_GUARD
#define _UNTILENCODERCOUNTS_H_GUARD

void untilEncoderCounts(int distance, tSensors sensorPort)// = 360, tSensors sensorPort = in2)
{
  SensorValue[sensorPort] = 0;

  while(abs(SensorValue[sensorPort]) < abs(distance)){wait1Msec(1);}
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

void forward(signed byte speed = 95)
{
  motor[port2] = abs(speed);
  motor[port3] = abs(speed);
}

#endif
//----------------------------------------------------------------------------------------------------

//--------------------------------------------| Backward |--------------------------------------------
#ifndef _BACKWARD_H_GUARD
#define _BACKWARD_H_GUARD

void backward(signed byte speed = -95)
{
  motor[port2] = abs(speed) * -1;
  motor[port3] = abs(speed) * -1;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| SwingTurn |--------------------------------------------
#ifndef _SWINGTURN_H_GUARD
#define _SWINGTURN_H_GUARD

void swingTurn(tDirections direction = right, signed byte speed = 95)
{
  if(direction == left)      // LEFT
  {
    if(speed >= 0)
    {
      motor[port2] = speed;
      motor[port3] = 0;
    }
    else if(speed < 0)
    {
      motor[port2] = 0;
      motor[port3] = speed;
    }
  }
  else if(direction == right) // RIGHT
  {
    if(speed >= 0)
    {
      motor[port2] = 0;
      motor[port3] = abs(speed);
    }
    else if(speed < 0)
    {
      motor[port2] = speed;
      motor[port3] = 0;
    }
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| PointTurn |--------------------------------------------
#ifndef _POINTTURN_H_GUARD
#define _POINTTURN_H_GUARD

void pointTurn(tDirections direction = right, signed byte speed = 95)
{
  if(direction == left)      // LEFT
  {
    motor[port2] = abs(speed);
    motor[port3] = abs(speed) * -1;
  }
  else if(direction == right) // RIGHT
  {
    motor[port2] = abs(speed) * -1;
    motor[port3] = abs(speed);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------------| Stop |----------------------------------------------
#ifndef _STOP_H_GUARD
#define _STOP_H_GUARD

void stop()
{
  motor[port2] = 0;
  motor[port3] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------| MoveStraightROTATIONS |--------------------------------------
#ifndef _MOVESTRAIGHTROTS_H_GUARD
#define _MOVESTRAIGHTROTS_H_GUARD

void moveStraightForRotations(int rotations = 1, tSensors rightEncoderPort = in2, tSensors leftEncoderPort = in3)
{
  SensorValue[rightEncoderPort] = 0;
  SensorValue[leftEncoderPort] = 0;

  while(SensorValue[rightEncoderPort] < (abs(rotations) * 360))
  {
		if(SensorValue[rightEncoderPort] == SensorValue[leftEncoderPort]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else if(SensorValue[rightEncoderPort] > SensorValue[leftEncoderPort])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[port2] = 65;		// Right Motor is run at power level 65
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 65;		// Left Motor is run at power level 65
		}
		wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| MoveStraightTIME |----------------------------------------
#ifndef _MOVESTRAIGHTTIME_H_GUARD
#define _MOVESTRAIGHTTIME_H_GUARD

void moveStraightForTime(int seconds, tSensors rightEncoderPort, tSensors leftEncoderPort)// = 5, tSensors rightEncoderPort = in2, tSensors leftEncoderPort = in3)
{
  SensorValue[rightEncoderPort] = 0;
  SensorValue[leftEncoderPort] = 0;

  int timeStart = ((int)nPgmTime / 1000);

  while(((int)nPgmTime / 1000) - timeStart < seconds)
  {
		if(SensorValue[rightEncoderPort] == SensorValue[leftEncoderPort]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else if(SensorValue[rightEncoderPort] > SensorValue[leftEncoderPort])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[port2] = 65;		// Right Motor is run at power level 65
			motor[port3]  = 85;		// Left Motor is run at power level 85
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[port2] = 85;		// Right Motor is run at power level 85
			motor[port3]  = 65;		// Left Motor is run at power level 65
		}
		wait1Msec(1);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

/********************************************************************************************************************************************\
																											|*  END ROBOT MOTION FUNCTIONS  *|
																											\********************************/
/***********************\
|*  SPECIAL FUNCTIONS  *|
\*******************************************************************************************************************************************/

//-------------------------------------------| TurnLEDON |--------------------------------------------
#ifndef _TURNLEDON_H_GUARD
#define _TURNLEDON_H_GUARD

void turnLEDOn(tSensors digitalPort = in12)
{
  SensorValue[digitalPort] = (word)ledOn;
}

#endif
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| TurnLEDOFF |-------------------------------------------
#ifndef _TURNLEDOFF_H_GUARD
#define _TURNLEDOFF_H_GUARD

void turnLEDOff(tSensors digitalPort = in12)
{
  SensorValue[digitalPort] = (word)ledOff;
}

#endif
//----------------------------------------------------------------------------------------------------

//----------------------------------------| TurnFlashlightON |----------------------------------------
#ifndef _TURNFLASHLIGHTON_H_GUARD
#define _TURNFLASHLIGHTON_H_GUARD

void turnFlashlightOn(tMotor flashlightPort = port7, short brightness = 63)
{
  if(bMotorReflected[flashlightPort] == false)
  {
    motor[flashlightPort] = abs(brightness) * -1;
  }
  else
  {
    motor[flashlightPort] = abs(brightness);
  }
}

#endif
//----------------------------------------------------------------------------------------------------

//---------------------------------------| TurnFlashlightOFF |----------------------------------------
#ifndef _TURNFLASHLIGHTOFF_H_GUARD
#define _TURNFLASHLIGHTOFF_H_GUARD

void turnFlashlightOff(tMotor flashlightPort = port7)
{
  motor[flashlightPort] = 0;
}

#endif
//----------------------------------------------------------------------------------------------------

/*******************************************************************************************************************************************\
																												|*  END SPECIAL FUNCTIONS  *|
																												\***************************/
