#pragma config(Motor,  motorA,          one,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          two,           tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#define NMOTORS 2
#define NLEVELS 3

#include "JoystickDriver.c"

int transfer_J_To_M(int joy,float slope,int dead) // joy = joy input, dead = dead band, slope = max motor output/max joy input - in this case 100/128
{
	int y;
	if (abs(joy)<dead)
		y=0;
	else
		y=slope*((float)joy-(float)dead*sgn(joy));

	return y;
}


task main()
{
	clearDebugStream();
	int joy_1x1;
	int joy_1x2;
	int joy_1y1;
	int joy_1y2;
	int tophat;
	float joyslope = (100./128.)*.5;
	int motorBoundsHi[NMOTORS]={1000,500};
	int motorBoundsLo[NMOTORS]={10,5};
	int levels[3]={0,15,59};
	int dband=15;
	int tophat_old=0;

	nMotorEncoder[one]=0;//must be on the ground
	nMotorEncoder[two]=0;//must be on ground
	writeDebugStreamLine("MAKE SURE ROBOT IS ON GROUND");
	wait10Msec(200);

	while (true)
	{
		//wait10Msec(100);
		getJoystickSettings(joystick);
		joy_1y1=transfer_J_To_M(joystick.joy1_y1, joyslope, dband);
		joy_1y2=transfer_J_To_M(joystick.joy1_y2, joyslope, dband);
		joy_1x1=transfer_J_To_M(joystick.joy1_x1, joyslope, dband);
		joy_1x2=transfer_J_To_M(joystick.joy1_x2, joyslope, dband);
		tophat=joystick.joy1_TopHat;

		writeDebugStreamLine("one: %d, two: %d", nMotorEncoder[one], nMotorEncoder[two]);
		//writeDebugStreamLine("two: %d", nMotorEncoder[two]);

		if (tophat!=tophat_old)
		{

		}

		if (
			(nMotorEncoder[one] < motorBoundsHi[0] && joy_1y1 > 0)  // OK to move up if we are below top
			||
			(nMotorEncoder[one] > motorBoundsLo[0] && joy_1y1 < 0)
			)
		{
			motor[one]=joy_1y1;//joystick.joy1_y1;
		}
		else{
			motor[one]=0;
			//writeDebugStreamLine("one hit top/bottom");
		}

		if (
			(nMotorEncoder[two] < motorBoundsHi[1] && joy_1y2 > 0)
			||
			(nMotorEncoder[two] > motorBoundsLo[1] && joy_1y2 < 0)
			)
			{
			motor[two]=joy_1y2;//joystick.joy1_y2;
			}
		else{
			motor[two]=0;
			//writeDebugStreamLine("two hit top/bottom");
		}
		//writeDebugStreamLine("%d", nMotorEncoder[one])
	}
}
