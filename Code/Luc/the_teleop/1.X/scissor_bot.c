#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightInactive)
#pragma config(Motor,  motorB,          wrist,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     fRight,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     fLeft,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rRight,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rLeft,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rLift,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     lLift,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
	float joyslope=(float)100/128;
	int dband=30; //deadband
	int joy_1y1;
	int joy_1y2;
	int joy_1x1;
	int joy_1x2;
	int joy_2y1;
	int joy_2y2;
	int joy_2x1;
	int joy_2x2;

	while (true)
	{
		getJoystickSettings(joystick);
		/*
		joy_1y1=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); //left (front,back)
		joy_1y2=transfer_J_To_M(joystick.joy1_y2, joyslope, dband); //right (front,back)
		joy_1x1=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); //strafe (side-to-side)
		joy_1x2=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); // Not in use
		joy_2y1=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); //left (front,back)
		joy_2y2=transfer_J_To_M(joystick.joy2_y2, joyslope, dband); //right (front,back)
		joy_2x1=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); //strafe (side-to-side)
		joy_2x2=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); // Not in used
		*/
		joy_1y1=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); //left (front,back)
		joy_1y2=transfer_J_To_M(joystick.joy1_y2, joyslope, dband); //right (front,back)
		joy_1x1=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); //strafe (side-to-side)
		joy_1x2=transfer_J_To_M(joystick.joy1_y1, joyslope, dband); // Not in use
		joy_2y1=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); //left (front,back)
		joy_2y2=transfer_J_To_M(joystick.joy2_y2, joyslope, dband); //right (front,back)
		joy_2x1=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); //strafe (side-to-side)
		joy_2x2=transfer_J_To_M(joystick.joy2_y1, joyslope, dband); // Not in used

	}
}
