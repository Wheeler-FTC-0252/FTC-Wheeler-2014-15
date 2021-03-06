#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CHiTechnicCompass)
#pragma config(Motor,  motorA,          unused1,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          unused2,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          unused3,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     unused4,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     arm,           tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     FLeft,         tmotorTetrix, openLoop, driveLeft)
#pragma config(Motor,  mtr_S1_C2_2,     BLeft,         tmotorTetrix, openLoop, driveLeft)
#pragma config(Motor,  mtr_S1_C3_1,     FRight,        tmotorTetrix, openLoop, reversed, driveRight)
#pragma config(Motor,  mtr_S1_C3_2,     BRight,        tmotorTetrix, openLoop, reversed, driveRight)
#pragma config(Servo,  srvo_S1_C4_1,    door,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "Transfer.c"
//#include "nMotorEncoderTargetAbs.c"


int nMotorEncoder_last[11];	// make this available for all motors - to start state when last checked


void init(){
	//ENCODERS//
	nMotorEncoder[arm]=0;

	//SERVOS//
	servoChangeRate[door] = 2;

	for (int ii=0; ii<sizeof(nMotorEncoder_last)/sizeof(nMotorEncoder_last[0]);ii++){
		nMotorEncoder_last[ii]=32767;
	}
}

task main()
{
	writeDebugStreamLine("\n\n\n=====START=======");

	/*Motor map:

	Motor Controller 1 = arm motors(not called in)
	Motor Controller 2 = left motor 1 & 2, spliced
	left motor 3
	Motor Controller 3 = right motor 1 & 2, spliced
	right motor 3*/

	int armspeed=20;
	int dband = 10; // Deadband for joystick
	int joylevels[6]={0,350,2350,4230,5000,5800};

	int roundup;
	int rounddown;
	int joy_1y1;
	int joy_1y2;
	int joy_2y1;
	int joy_2y2;
	int tophat;
	int tophat_old=-1; // Last tophat value, initialize in Neutral position -1
	int tophat_last=-2; // Used only to decide on chnage event for debug printing
	int manualused=0;
	int loopNum = 0;
	int button_old=-1;
	// Debug initial joystick
//	for(int ii=0; ii<10;ii++)
//	{		getJoystickSettings(joystick);		tophat=joystick.joy2_TopHat;		writeDebugStreamLine("tophat = %d",tophat); }

	init();
	if(0){
		motor[arm]=0;
		nMotorEncoderTarget[arm]=500;
		motor[arm]=50;
	}
	//servo[door]=50;
	while (true)
	{
		loopNum++;
		getJoystickSettings(joystick);
		joy_1y1=transfer_J_To_M(joystick.joy1_y1,100./320.,dband);
		joy_1y2=transfer_J_To_M(joystick.joy1_y2,100./320.,dband);
		joy_2y1=transfer_J_To_M(joystick.joy2_y1,100./640.,dband);
		joy_2y2=transfer_J_To_M(joystick.joy2_y2,100./640.,dband);
		tophat=joystick.joy2_TopHat;

		//writeDebugStreamLine("%d",ServoValue[door]);


		//nxtDisplayCenteredBigTextLine(3,"%d",motor[FRight]);

		//nxtDisplayCenteredBigTextLine(6,"%d",joystick.joy1_y1);
		//writeDebugStreamLine("Mid: %d, Back:%d",nMotorEncoder[FRight],nMotorEncoder[BRight]);
		motor[FLeft]=joy_1y1;
		motor[BLeft]=joy_1y1;
		motor[FRight]=joy_1y2;
		motor[BRight]=joy_1y2;


		//Arm Stop Checking//
		//if (nMotorRunState[arm]==runStateIdle){
		//	motor[arm]=0;
		//}


		//STATUS EVERY LOOP
		if(0) writeDebugStreamLine("STATUS: (arm) Enc,Target,Speed = %d,%d,%d"
			,nMotorEncoder[arm],nMotorEncoderTarget[arm],motor[arm]);


		//Arm Position
		int me = nMotorEncoder[arm];
		//if( me != nMotorEncoder_last[arm] ) // Report any change
		if( abs(me - nMotorEncoder_last[arm])>=20 ) // Report when position changes by >= 20
		{
			writeDebugStreamLine("(%4d)UPDATED VALUE: (arm) Encoder[%d] = %d",loopNum,arm,me);
			nMotorEncoder_last[arm] = me;
		}

		//Arm Motor//
		if(tophat != tophat_last){
			writeDebugStreamLine("(%4d)UPDATED VALUE:  Tophat = %d",loopNum,tophat);
			tophat_last = tophat;
		}

		//SERVO DOOR//
		if (joystick.joy2_Buttons!=button_old){
			if (joystick.joy2_Buttons==03){
				servo[door]=servo[door]+5;
			}
			else if (joystick.joy2_Buttons==01){
				servo[door]=servo[door]-5;
			}
		}
		button_old=joystick.joy2_Buttons;


		if (joy_2y1!=0){
			manualused=1;
			nMotorEncoderTarget[arm]=0;
			motor[arm]=joy_2y1;
		}
		else if ((tophat==0 || tophat==4)&&tophat!=tophat_old){//Tophat

			writeDebugStreamLine("ENTERING TOPHAT");

			for (int ii=0; ii<sizeof(joylevels)/sizeof(joylevels[0]);ii++){
				if (nMotorEncoder[arm]<=joylevels[0]){
					writeDebugStreamLine("below bottom");
					writeDebugStreamLine("%d",nMotorEncoder[arm]);
					rounddown=-1;
					roundup=1;
					break;
				}
				else if(nMotorEncoder[arm]>=joylevels[(sizeof(joylevels)/4)-1]){
					writeDebugStreamLine("above top");
					writeDebugStreamLine("%d",nMotorEncoder[arm]);
					rounddown=(sizeof(joylevels)/4)-2;
					//-2 cuz its -1 from the length,cuz it starts at 0. and  another -1 cuz
					// its the second two last one

					roundup=-1;
					break;
				}

				if (joylevels[ii]+5>nMotorEncoder[arm] && joylevels[ii]-5<nMotorEncoder[arm]){
					writeDebugStreamLine("%d",nMotorEncoder[arm]);
					rounddown=ii-1;//already know it isnt on bottom or top, cuz the first two if's
					roundup=ii+1;
					break;
				}

				if (nMotorEncoder[arm]>joylevels[ii]&&nMotorEncoder[arm]<joylevels[ii+1]){
					writeDebugStreamLine("goldilocks: d: %d, U: %d",rounddown,roundup);
					writeDebugStreamLine("%d",nMotorEncoder[arm]);
					rounddown=ii;
					roundup=ii+1;
					break;
				}

			}

			writeDebugStreamLine("\nrounddown (idx=%d) , roundup (idx=%d)",rounddown,roundup);
			for (int ii=0; ii<sizeof(joylevels)/sizeof(joylevels[0]);ii++)writeDebugStream("[%d]=%d ,",ii,joylevels[ii]);
			writeDebugStreamLine("\n");

			writeDebugStreamLine("SET MOTOR SPEED to %d from %d in advance of setting target", 0 , motor[arm] );
			motor[arm]=0;

			if (tophat==0 && roundup != -1){//up
				writeDebugStreamLine("DRIVING UP to %d from %d",joylevels[roundup] , nMotorEncoder[arm]);
				nMotorEncoderTarget[arm] = joylevels[roundup] - nMotorEncoder[arm];
				writeDebugStreamLine("doing %d = %d - %d", nMotorEncoderTarget[arm], joylevels[roundup], nMotorEncoder[arm]);
				writeDebugStreamLine("SET MOTOR SPEED to %d from %d", armspeed , motor[arm] );
				motor[arm]=armspeed;
			}
			else if (tophat==4 && rounddown != -1){//down
				writeDebugStreamLine("DRIVING DOWN to %d from %d",joylevels[rounddown], nMotorEncoder[arm]);
				nMotorEncoderTarget[arm] = (joylevels[rounddown] - nMotorEncoder[arm]);
				writeDebugStreamLine("doing %d = %d - %d", nMotorEncoderTarget[arm], joylevels[rounddown], nMotorEncoder[arm]);
				writeDebugStreamLine("SET MOTOR SPEED to %d from %d", -armspeed , motor[arm] );
				motor[arm]= -armspeed;
			}
			else{
				writeDebugStreamLine("SET MOTOR SPEED to %d from %d", 0 , motor[arm] );
				motor[arm]=0;
			}
		}
		else if (joy_2y1==0 && manualused==1){//manualused
			manualused=0;
			motor[arm]=0;
		}

		tophat_old=tophat;
	}
}


// End
