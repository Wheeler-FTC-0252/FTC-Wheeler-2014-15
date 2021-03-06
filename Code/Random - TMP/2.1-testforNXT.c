#pragma config(Motor,  motorA,          arm,           tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          two,           tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define NMOTORS 2
#define NLEVELS sizeof(arm_levels)/4

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
	nMotorEncoder[arm]=0;
	int joy_1x1;
	int joy_1x2;
	int joy_1y1;
	int joy_1y2;
	int tophat;
	float joyslope = (100./128.)*.5;
	//int motorBoundsHi[NMOTORS]={1000,500};
	//int motorBoundsLo[NMOTORS]={10,5};
	int arm_levels[3]={0,15,59};
	int servo_levels[3]={0,15,59};
	int dband=15;
	int tophat_old=0;
	//int wasmanual=0;//1 is yes 0 is no
	int rounddown=0;//the two values to use when
	int roundup=0;
	int maxspeed=30;//speed for motors when tophat is used
	int armencoder=0;//141116 had a problem - tried to fix using this because it might change during code
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
		armencoder=nMotorEncoder[arm];

		//writeDebugStreamLine("one: %d, two: %d", nMotorEncoder[one], nMotorEncoder[two]);
		//writeDebugStreamLine("two: %d", nMotorEncoder[two]);
		/*
		if (joy_1y2!=0)
		{

			if (
				(armencoder < arm_levels[NLEVELS-1] && joy_1y2 > 0)
			||
			(armencoder > arm_levels[0] && joy_1y2 < 0)
			){
				nMotorEncoderTarget[arm]=0;
				motor[arm]=joy_1y2;
			}
			else
				motor[arm]=0;
		}
		*/
		if (tophat!=tophat_old)
		{
			if (armencoder<=0){//may act weirdly for values lower then 0
				roundup=1;
				rounddown=-1;
			}
			else if (0<armencoder && armencoder<arm_levels[NLEVELS-1]){
				for (int level=0;level<NLEVELS;level++){
					roundup=level+1;
					rounddown=level;

					if (arm_levels[rounddown] < armencoder && armencoder<arm_levels[roundup]){
						break;
					}
				}
			}
			else if (armencoder==arm_levels[NLEVELS-1]){
				roundup=-1;
				rounddown=NLEVELS-2;
			}
			else{//higher than highest
				roundup=-1;
				rounddown=NLEVELS-1;
			}



			/*
			for (int ii=0;ii<NLEVELS;ii++)
			{
				rounddown=ii;
				roundup=ii+1;
				if (roundup==NLEVELS-1){
					//rounddown=ii-1;
					//roundup=ii;
					break;
				}
				if (arm_levels[rounddown] < armencoder && armencoder < arm_levels[roundup])
				{
					break;
				}
			}
			*/
			writeDebugStreamLine("roundup: %d, rounddown: %d, encoder %d, array %d", roundup, rounddown, armencoder, arm_levels);
			switch (tophat){
				case 0:
					motor[arm]=maxspeed;
					if (roundup!=-1){
					nMotorEncoderTarget[arm]=arm_levels[roundup];}
					writeDebugStreamLine("U wrote up   %6d", armencoder);
					break;
				case 4:
					motor[arm]=-1*maxspeed;
					if (rounddown!=-1){
					nMotorEncoderTarget[arm]=arm_levels[rounddown];}

					writeDebugStreamLine("U wrote down %6d", armencoder);
					break;
				default:
					motor[arm]=0;
					writeDebugStreamLine("DEFAULT      %6d", armencoder);
					break;
			}
		}
		tophat_old=tophat;
	}
}
