#pragma config(Sensor, S1,     lightLeft,      sensorLightInactive)
#pragma config(Sensor, S2,     lightRight,     sensorLightInactive)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          motorLeft,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Version 2.1 141019 Lucien Gaitskell

task main()
{
	float version = 2.1;
	int lLeft;
	int lRight;
	int maxspeed = -20;
	float alpha;
	nxtDisplayCenteredTextLine(1, "Version: %4.1f", version );

	while (true)
	{
		lLeft=SensorValue[lightLeft];
		lRight=SensorValue[lightRight];
		nxtDisplayCenteredTextLine(2, "Left: %d", lLeft );
		nxtDisplayCenteredTextLine(3, "Right: %d", lRight);

		// (1-alpha) is the relative speed for the slower track
		// must declare first number a float to get fp math
		alpha = abs((float)lLeft-(float)lRight)/((float)lLeft+(float)lRight);


		if (lLeft > lRight)
		{
			nxtDisplayCenteredTextLine(6, "Left brighter" );
			motor[motorLeft]=round((1.0-alpha)*maxspeed); // We would like this to round to nearest integer
			motor[motorRight]=maxspeed;
		}
		else if (lLeft < lRight)
		{
		nxtDisplayCenteredTextLine(6, "Right brighter" );
			motor[motorRight]=round((1.0-alpha)*maxspeed);
			motor[motorLeft]=maxspeed;
		}
		else
		{
		nxtDisplayCenteredTextLine(6, "Equal" );
			motor[motorRight]=maxspeed;
			motor[motorLeft]=maxspeed;
		}


		nxtDisplayCenteredTextLine(7, "Alpha: %f", alpha);
		nxtDisplayCenteredTextLine(4, "Motor Left: %d", motor[motorLeft] );
		nxtDisplayCenteredTextLine(5, "Motor Right: %d", motor[motorRight]);

	}
}