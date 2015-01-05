/*------------------------------------------*\
|*	- Natural Language for VEX IQ		 -			*|
\*------------------------------------------*/
#pragma once
#pragma systemFile            	// eliminates warning for "unreferenced" functions

/*
--------------- Enumerations and Defines ----------------------
*/

#define VexIQClawbot 0
#define noMotorOnPort ((tMotor)-1)
#define nMaxJoyScaleValue 100

// enum for units
typedef enum tMovementUnits
{
	degrees							= 0,
	rotations						= 1,
	milliseconds				= 2,
	seconds							= 3,
	minutes							= 4
} tMovementUnits;

typedef enum tIQLCDLine
{
	line1				= 0,
	line2				= 1,
	line3				= 2,
	line4				= 3,
	line5				= 4
} tIQLCDLine;

bool bPopulatedMotorDriveSides = false;
TMotorList leftMotors;
TMotorList rightMotors;
short nGlobalJoyScaledValue = nMaxJoyScaleValue;

/*
------------------- Utility Commands --------------------------
*/

void setJoystickScale(short nScaledPercentage = nMaxJoyScaleValue)
{
	if(nScaledPercentage > nMaxJoyScaleValue)
	{
		nGlobalJoyScaledValue = nMaxJoyScaleValue;
	}
	else if(nScaledPercentage < 0)
	{
		nGlobalJoyScaledValue = 0;
	}
	else
	{
		nGlobalJoyScaledValue = nScaledPercentage;
	}
}

void updateMotorDriveTrain()
{
	if(!bPopulatedMotorDriveSides)
	{
		getMotorsWithDriveSideType(driveRight, rightMotors);
		getMotorsWithDriveSideType(driveLeft,	 leftMotors);
		bPopulatedMotorDriveSides = true;
	}
}

//This command is here only for LEGACY reasons (to prevent compiler errors)
void setRobotType(short robotType)
{
	return;
}

void displayControllerValues(tIQLCDLine lineNumber = line1, const TVexJoysticks nJoystickValue = ChA)
{
	string sOutputString;
	string sJoystickTemp;

	switch(nJoystickValue)
	{
	case ChA:		sJoystickTemp = "Channel A:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChB:		sJoystickTemp = "Channel B:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChC:		sJoystickTemp = "Channel C:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case ChD:		sJoystickTemp = "Channel D:";
					sprintf(sOutputString, "%s %d", sJoystickTemp, getJoystickValue(nJoystickValue));
					break;
	case BtnEUp:	sJoystickTemp = "Btn EUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released" );
					break;
	case BtnEDown:	sJoystickTemp = "Btn EDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnFUp:	sJoystickTemp = "Btn FUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnFDown:	sJoystickTemp = "Btn FDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnLUp:	sJoystickTemp = "Btn LUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnLDown:	sJoystickTemp = "Btn LDown:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnRUp:	sJoystickTemp = "Btn RUp:";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	case BtnRDown:	sJoystickTemp = "Btn RDown";
					sprintf(sOutputString, "%s %s", sJoystickTemp, getJoystickValue(nJoystickValue) ? "Pressed" : "Released");
					break;
	}

	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

void displayMotorValues(tIQLCDLine lineNumber = line1, const tMotor nDeviceIndex = motor1)
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion;

	getVexIqDeviceInfo(nDeviceIndex, nDeviceType, nDeviceStatus, nDeviceVersion);
	string sOutputString;

	//No device found.
	if (nDeviceType != vexIQ_SensorMOTOR)
		return;

	sprintf(sOutputString, "Motor(%d) %d deg", nDeviceIndex + 1 , getMotorEncoder((tMotor)nDeviceIndex));
	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

void displaySensorValues(tIQLCDLine lineNumber = line1, const tSensors nDeviceIndex = port1)
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion = 0;
	string sOutputString;
	string sColorTemp;
	int tempValue = 0;

	getVexIqDeviceInfo(nDeviceIndex, nDeviceType, nDeviceStatus, nDeviceVersion);

	if (nDeviceType == vexIQ_SensorNone || nDeviceType == vexIQ_SensorMOTOR)
		return;

	switch (nDeviceType)
	{
	case vexIQ_SensorMOTOR:
		sprintf(sOutputString, "Motor(%d) %d deg", nDeviceIndex + 1 , getMotorEncoder((tMotor)nDeviceIndex));
		break;

	case vexIQ_SensorLED:
		sprintf(sOutputString, "LED(%d) %s", nDeviceIndex + 1, getTouchLEDValue(nDeviceIndex) ? "Pressed" : "Released");
		break;

	case vexIQ_SensorRGB:
		if(getColorMode(nDeviceIndex) == colorTypeGrayscale_Reflected)
		{
			tempValue = getColorGrayscale(nDeviceIndex);
			sprintf(sOutputString, "Color(%d) %d/%d", nDeviceIndex + 1, tempValue, getColorProximity(nDeviceIndex));
		}
		else if(getColorMode(nDeviceIndex) == colorTypeRGB_Hue_Ambient)
		{
			tempValue = getColorHue(nDeviceIndex);
			sprintf(sOutputString, "Color(%d) %d/%d", nDeviceIndex + 1, tempValue, getColorProximity(nDeviceIndex));
		}
		else if(getColorMode(nDeviceIndex) == colorTypeRGB_12Colors_Ambient)
		{
			switch(getColorName(nDeviceIndex))
			{
				case colorRedViolet:	sColorTemp = "RedViolet";	break;
				case colorRed:			sColorTemp = "Red";			break;
				case colorDarkOrange:	sColorTemp = "DarkOrange";	break;
				case colorOrange:		sColorTemp = "Orange";		break;
				case colorDarkYellow:	sColorTemp = "DarkYellow";	break;
				case colorYellow:		sColorTemp = "Yellow";		break;
				case colorLimeGreen:	sColorTemp = "LimeGreen";	break;
				case colorGreen:		sColorTemp = "Green";		break;
				case colorBlueGreen:	sColorTemp = "BlueGreen";	break;
				case colorBlue:			sColorTemp = "Blue";		break;
				case colorDarkBlue:		sColorTemp = "DarkBlue";	break;
				case colorViolet:		sColorTemp = "Violet";		break;

				case colorNone:
				default:				sColorTemp = "None";		break;
			}

			sprintf(sOutputString, "Color(%d) %s", nDeviceIndex + 1, sColorTemp);
		}
		else
		{
			sprintf(sOutputString, "Bad Color Mode (%d)", nDeviceIndex + 1);
		}
		break;

	case vexIQ_SensorGYRO:
		sprintf(sOutputString, "Gyro(%d) %d deg", nDeviceIndex + 1, getGyroDegrees(nDeviceIndex));
		break;

	case vexIQ_SensorSONAR:
			sprintf(sOutputString, "Dist(%d) %d mm", nDeviceIndex + 1, getDistanceValue(nDeviceIndex));
		break;

	case vexIQ_SensorBUMPER:
		sprintf(sOutputString, "Bumper(%d) %s", nDeviceIndex + 1, getBumperValue(nDeviceIndex) ? "Pressed" : "Released");
		break;
	}

	int nLineNumber = lineNumber;
	displayTextLine(nLineNumber, sOutputString);
}

/*
------------------- Low Level Commands ------------------------
*/

void lowLevelMoveDistance(const float quantity, short nLeftSpeed, short nRightSpeed, const tMovementUnits nUnitType)
{
	long nConvertedUnitsLeft = 0;
	long nConvertedUnitsRight = 0;

	if(nUnitType == degrees)
	{
		nConvertedUnitsLeft = quantity;
		nConvertedUnitsRight = quantity;
	}
	else if(nUnitType == rotations)
	{
		nConvertedUnitsLeft = quantity * 360.0;
		nConvertedUnitsRight = quantity * 360.0;
	}
	else
	{
		return;
	}

	updateMotorDriveTrain();

	if(nLeftSpeed < 0)
	{
		nConvertedUnitsLeft *= -1;
		//nLeftSpeed *= -1;
	}

	if(nRightSpeed < 0)
	{
		nConvertedUnitsRight *= -1;
		//nRightSpeed *= -1;
	}

	if(leftMotors[0] != noMotorOnPort)	moveMotorTarget(leftMotors[0], nConvertedUnitsLeft, nLeftSpeed);
	if(leftMotors[1] != noMotorOnPort)	moveMotorTarget(leftMotors[1], nConvertedUnitsLeft, nLeftSpeed);
	if(leftMotors[2] != noMotorOnPort)	moveMotorTarget(leftMotors[2], nConvertedUnitsLeft, nLeftSpeed);
	if(leftMotors[3] != noMotorOnPort)	moveMotorTarget(leftMotors[3], nConvertedUnitsLeft, nLeftSpeed);

	if(rightMotors[0] != noMotorOnPort)	moveMotorTarget(rightMotors[0], nConvertedUnitsRight, nRightSpeed);
	if(rightMotors[1] != noMotorOnPort)	moveMotorTarget(rightMotors[1], nConvertedUnitsRight, nRightSpeed);
	if(rightMotors[2] != noMotorOnPort)	moveMotorTarget(rightMotors[2], nConvertedUnitsRight, nRightSpeed);
	if(rightMotors[3] != noMotorOnPort)	moveMotorTarget(rightMotors[3], nConvertedUnitsRight, nRightSpeed);

	sleep(100);

	while(getMotorDriveTrainMoving())
		sleep(1);

	sleep(25);
}

void lowLevelMoveTiming(float quantity, const short nLeftSpeed, const short nRightSpeed, const tMovementUnits nUnitType)
{
	updateMotorDriveTrain();

	if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], nLeftSpeed);
	if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], nLeftSpeed);
	if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], nLeftSpeed);
	if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], nLeftSpeed);

	if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], nRightSpeed);
	if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], nRightSpeed);
	if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], nRightSpeed);
	if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], nRightSpeed);

	if(nUnitType == milliseconds)
		sleep(quantity);
	else if(nUnitType == seconds)
		sleep(quantity * 1000);
	else if(nUnitType == minutes)
		sleep(quantity * 1000 * 60);
	else
		sleep(1);

	if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], 0);
	if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], 0);
	if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], 0);
	if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], 0);

	if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], 0);
	if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], 0);
	if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], 0);
	if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], 0);

	sleep(25);
}

/*
------------------- Wait Commands -------------------------
*/
void wait(const float quantity = 1.0, const tMovementUnits unitType = seconds)
{
	if(unitType == seconds)
		sleep(quantity * 1000.0);
	else if(unitType == minutes)
		sleep(quantity * 1000.0 * 60.0);
	else if(unitType == milliseconds)
		sleep(quantity);
}

#define waitUntil(condition) while(!(condition)) sleep(1)

/*
------------------- Discrete Movement -------------------------
*/

void forward(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void backward(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed) * -1;
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void turnLeft(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, -adjustedSpeed, adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, -adjustedSpeed, adjustedSpeed, unitType);
		break;
	}
}

void turnRight(const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	case rotations:
	case degrees:
		lowLevelMoveDistance(adjustedQuantity, adjustedSpeed, -adjustedSpeed, unitType);
		break;

	case milliseconds:
	case seconds:
	case minutes:
		lowLevelMoveTiming(adjustedQuantity, adjustedSpeed, -adjustedSpeed, unitType);
		break;
	}
}

void moveMotor(const tMotor motorPort = motor10, const float quantity = 1.0, const tMovementUnits unitType = rotations, const short speed = 50)
{
	short adjustedSpeed = abs(speed);
	float adjustedQuantity = abs(quantity);

	switch(unitType)
	{
	//Rotations - moves in reverse if speed and/or quantity are set negative
	case rotations:
		if(speed < 0 || quantity < 0)
			moveMotorTarget(motorPort, -(adjustedQuantity * 360.0), -adjustedSpeed);
		else
			moveMotorTarget(motorPort, (adjustedQuantity * 360.0), adjustedSpeed);
		waitUntilMotorStop(motorPort);
		break;

	//Degrees - moves in reverse if speed and/or quantity are set negative
	case degrees:
		if(speed < 0 || quantity < 0)
			moveMotorTarget(motorPort, -adjustedQuantity, -adjustedSpeed);
		else
			moveMotorTarget(motorPort, adjustedQuantity, adjustedSpeed);
		waitUntilMotorStop(motorPort);
		break;

	//Milliseconds
	case milliseconds:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity);
		setMotorSpeed(motorPort, 0);
		break;

	//Seconds
	case seconds:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity * 1000.0);
		setMotorSpeed(motorPort, 0);
		break;

	//Minutes
	case minutes:
		setMotorSpeed(motorPort, speed);
		sleep(adjustedQuantity * 1000.0 * 60.0);
		setMotorSpeed(motorPort, 0);
		break;
	}

	sleep(25);
}

/*
------------------- Constant Movements -------------------------
*/

void setMotor(const tMotor motorPort = motor1, const short speed = 50)
{
	setMotorSpeed(motorPort, speed);
}

void stopMotor(const tMotor motorPort = motor1)
{
	setMotorSpeed(motorPort, 0);
}

void stopAllMotors()
{
	TVexIQDeviceTypes nDeviceType;
	TDeviceStatus nDeviceStatus;
	short nDeviceVersion;

	for (short nPortIndex = 0; nPortIndex < 12; ++nPortIndex)
	{
		getVexIqDeviceInfo(nPortIndex, nDeviceType, nDeviceStatus, nDeviceVersion);

		if (nDeviceType != vexIQ_SensorMOTOR)
			continue;

		setMotorSpeed(nPortIndex, 0);
	}
}

void setMultipleMotors(const short speed = 50, const tMotor firstMotor = motor1, const tMotor secondMotor = noMotorOnPort, const tMotor thirdMotor = noMotorOnPort, const tMotor fourthMotor = noMotorOnPort)
{
	if(firstMotor != noMotorOnPort) 		setMotorSpeed(firstMotor, speed);
	if(secondMotor != noMotorOnPort) 	setMotorSpeed(secondMotor, speed);
	if(thirdMotor != noMotorOnPort) 		setMotorSpeed(thirdMotor, speed);
	if(fourthMotor != noMotorOnPort) 	setMotorSpeed(fourthMotor, speed);
}

void stopMultipleMotors(const tMotor firstMotor = motor1, const tMotor secondMotor = noMotorOnPort, const tMotor thirdMotor = noMotorOnPort, const tMotor fourthMotor = noMotorOnPort)
{
	if(firstMotor != noMotorOnPort) 		setMotorSpeed(firstMotor, 0);
	if(secondMotor != noMotorOnPort) 	setMotorSpeed(secondMotor, 0);
	if(thirdMotor != noMotorOnPort) 		setMotorSpeed(thirdMotor, 0);
	if(fourthMotor != noMotorOnPort) 	setMotorSpeed(fourthMotor, 0);
}

/*
------------------- Timer Commands -------------------------
*/

void resetTimer(TTimers currentTimer = T1)
{
	clearTimer(currentTimer);
}

float getTimer(TTimers currentTimer = T1, const tMovementUnits unitType = seconds)
{
	if(unitType == milliseconds)
		return (time1[currentTimer]);
	else if(unitType == seconds)
		return ((float)time1[currentTimer]/1000.0);
	else if(unitType == minutes)
		return (((float)time1[currentTimer] / 1000.0) / 60.0);

	return 0.0;
}

void lineTrackLeft(const tSensors sensorName = port1, const short threshold = 50, const short speedPrimary = 50, const short speedSecondary = 0)
{
	if(getColorMode(sensorName) != colorTypeGrayscale_Reflected)
		setColorMode(sensorName, colorTypeGrayscale_Reflected);

	updateMotorDriveTrain();

	if(getColorGrayscale(sensorName) > threshold)
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], speedPrimary);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], speedPrimary);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], speedPrimary);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], speedPrimary);

		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], speedSecondary);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], speedSecondary);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], speedSecondary);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], speedSecondary);

	}
	else
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], speedSecondary);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], speedSecondary);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], speedSecondary);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], speedSecondary);

		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], speedPrimary);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], speedPrimary);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], speedPrimary);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], speedPrimary);
	}
}

void lineTrackRight(const tSensors sensorName = port1, const short threshold = 50, const short speedPrimary = 50, const short speedSecondary = 0)
{
	if(getColorMode(sensorName) != colorTypeGrayscale_Reflected)
		setColorMode(sensorName, colorTypeGrayscale_Reflected);

	updateMotorDriveTrain();

	if(getColorGrayscale(sensorName) < threshold)
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], speedPrimary);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], speedPrimary);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], speedPrimary);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], speedPrimary);

		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], speedSecondary);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], speedSecondary);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], speedSecondary);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], speedSecondary);

	}
	else
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], speedSecondary);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], speedSecondary);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], speedSecondary);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], speedSecondary);

		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], speedPrimary);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], speedPrimary);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], speedPrimary);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], speedPrimary);
	}
}

/*
------------------- Remote Control Movements -------------------------
*/

void tankControl(TVexJoysticks rightJoystick = ChD, TVexJoysticks leftJoystick = ChA, short threshold = 10)
{
	short nRightSideSpeed = 0;
	short nLeftSideSpeed = 0;

	updateMotorDriveTrain();

	nRightSideSpeed = getJoystickValue(rightJoystick);
	nLeftSideSpeed = getJoystickValue(leftJoystick);

	if(nGlobalJoyScaledValue != nMaxJoyScaleValue)
	{
		nRightSideSpeed = nRightSideSpeed * (nGlobalJoyScaledValue / 100.0);
		nLeftSideSpeed 	= nLeftSideSpeed * (nGlobalJoyScaledValue / 100.0);
	}

	if(abs(getJoystickValue(rightJoystick)) <= abs(threshold))
	{
		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], 0);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], 0);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], 0);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], 0);
	}
	else
	{
		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], nRightSideSpeed);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], nRightSideSpeed);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], nRightSideSpeed);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], nRightSideSpeed);
	}

	if(abs(getJoystickValue(leftJoystick)) <= abs(threshold))
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], 0);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], 0);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], 0);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], 0);
	}
	else
	{
		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], nLeftSideSpeed);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], nLeftSideSpeed);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], nLeftSideSpeed);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], nLeftSideSpeed);
	}
}

void arcadeControl(TVexJoysticks verticalJoystick = ChA, TVexJoysticks horizontalJoystick = ChB, short threshold = 10)
{
	short nRightSideSpeed = 0;
	short nLeftSideSpeed = 0;

	updateMotorDriveTrain();

	if(abs(vexRT[verticalJoystick]) <= abs(threshold) && abs(vexRT[horizontalJoystick]) <= abs(threshold))
	{
		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], 0);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], 0);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], 0);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], 0);

		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], 0);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], 0);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], 0);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], 0);
	}
	else
	{
	 	nRightSideSpeed = ((getJoystickValue(verticalJoystick) - getJoystickValue(horizontalJoystick))/2);
		nLeftSideSpeed = ((getJoystickValue(verticalJoystick) + getJoystickValue(horizontalJoystick))/2);

		if(nGlobalJoyScaledValue != nMaxJoyScaleValue)
		{
			nRightSideSpeed = nRightSideSpeed * (nGlobalJoyScaledValue / 100.0);
			nLeftSideSpeed 	= nLeftSideSpeed * (nGlobalJoyScaledValue / 100.0);
		}

		if(rightMotors[0] != noMotorOnPort)	setMotorSpeed(rightMotors[0], nRightSideSpeed);
		if(rightMotors[1] != noMotorOnPort)	setMotorSpeed(rightMotors[1], nRightSideSpeed);
		if(rightMotors[2] != noMotorOnPort)	setMotorSpeed(rightMotors[2], nRightSideSpeed);
		if(rightMotors[3] != noMotorOnPort)	setMotorSpeed(rightMotors[3], nRightSideSpeed);

		if(leftMotors[0] != noMotorOnPort)	setMotorSpeed(leftMotors[0], nLeftSideSpeed);
		if(leftMotors[1] != noMotorOnPort)	setMotorSpeed(leftMotors[1], nLeftSideSpeed);
		if(leftMotors[2] != noMotorOnPort)	setMotorSpeed(leftMotors[2], nLeftSideSpeed);
		if(leftMotors[3] != noMotorOnPort)	setMotorSpeed(leftMotors[3], nLeftSideSpeed);
	}
}

void armControl(tMotor armMotorPort = motor10, TVexJoysticks upButton = BtnLUp, TVexJoysticks downButton = BtnLDown, short armSpeed = 75)
{
	if(vexRT[upButton])
	{
		setMotorSpeed(armMotorPort, armSpeed);
	}
	else if(vexRT[downButton])
	{
		setMotorSpeed(armMotorPort, -armSpeed);
	}
	else
	{
		setMotorSpeed(armMotorPort, 0);
	}
}
