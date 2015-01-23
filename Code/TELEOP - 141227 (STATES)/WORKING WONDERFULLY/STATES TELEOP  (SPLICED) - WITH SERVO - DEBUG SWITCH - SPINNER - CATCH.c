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
#pragma config(Servo,  srvo_S1_C4_2,    spin1,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    spin2,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_4,    catchServo,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//141227 - TELEOP WITH SERVO (DEBUG PRINT CAN BE ENABLED BY THE VARIBLE "debug")
//Remember taht the spinner buttons don't work

//NOTES FOR NEXT TIME: MAKE A DEAD BAND FOR BOTTOM VALUE

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
	bool debug=true;

	if (debug)writeDebugStreamLine("\n\n\n=====START=======");

	/*Motor map:

	Motor Controller 1 = arm motors(not called in)
	Motor Controller 2 = left motor 1 & 2, spliced
	left motor 3
	Motor Controller 3 = right motor 1 & 2, spliced
	right motor 3*/

	int armspeed=30;
	int dband = 10; // Deadband for joystick
	int joylevels[6]={30,350,2350,4230,4445,5860};//FIRST VALUE IS 5 TO QUICKLY ADDRESS THE DEADBANDING ISSUE

	bool luccomputer=true;

	//for driver joystick
	int catchEngage=2;
	int catchDisengage=4;

	//for gunner joystick
	bool spinneron=false;
	int doorbutton=1;
	int spinnerIn=2;
	int spinnerOut=4;
	int autoSpinnerButton=16;
	bool autoSpinner=false;
	int spinnerSpeedOut=255;//0-126 BACKWARDS (0 IS FULL BACK), 127 STILL, 128-255 FORWARD (255 IS FULL FORWARD)
	int spinnerSpeedIn=0;

	if (luccomputer){//if it is on lucs comp (set to X on controller)
		//driver
		catchEngage=1;
		catchDisengage=2;
		//gunner
		doorbutton=4;
		spinnerIn=1;
		spinnerOut=2;
	}

	int roundup;
	int rounddown;
	int joy_1y1;
	int joy_1y2;
	int joy_2y1;
	int joy_2y2;
	int tophat;
	int buttons_joy2;
	int buttons_joy1;
	bool dooropen=true;
	int dooropenpos=120;
	int doorclosedpos=10;
	int tophat_old=-1; // Last tophat value, initialize in Neutral position -1
	int tophat_last=-2; // Used only to decide on chnage event for debug printing
	int manualused=0;
	int loopNum = 0;
	int button_old1=-1;
	int button_old2=-1;
	int movement=0;//0 is stop, 1 is down, 2 is up//

	// Debug initial joystick
	//	for(int ii=0; ii<10;ii++)
	//	{		getJoystickSettings(joystick);		tophat=joystick.joy2_TopHat;		writeDebugStreamLine("tophat = %d",tophat); }

	init();

	while (true)
	{
		loopNum++;
		getJoystickSettings(joystick);
		joy_1y1=transfer_J_To_M(joystick.joy1_y1,100./320.,dband);
		joy_1y2=transfer_J_To_M(joystick.joy1_y2,100./320.,dband);
		joy_2y1=transfer_J_To_M(joystick.joy2_y1,100./640.,dband);
		joy_2y2=transfer_J_To_M(joystick.joy2_y2,100./640.,dband);
		tophat=joystick.joy2_TopHat;
		buttons_joy1=joystick.joy1_Buttons;
		buttons_joy2=joystick.joy2_Buttons;

		motor[FLeft]=joy_1y1;
		motor[BLeft]=joy_1y1;
		motor[FRight]=joy_1y2;
		motor[BRight]=joy_1y2;


		if (debug){//DEBUG
			//writeDebugStreamLine("%d",ServoValue[door]);//STATUS PRINTS
			//nxtDisplayCenteredBigTextLine(3,"%d",motor[FRight]);
			//nxtDisplayCenteredBigTextLine(6,"%d",joystick.joy1_y1);
			//writeDebugStreamLine("Mid: %d, Back:%d",nMotorEncoder[FRight],nMotorEncoder[BRight]);

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
		}//END DEBUG

		//SERVO DOOR//

		if (buttons_joy1!=button_old1){
			if (buttons_joy1==catchEngage){
				servo[catchServo]=50;
			}
			else if (buttons_joy1==catchDisengage){
				servo[catchServo]=90;
			}
		}
		button_old1=buttons_joy1;

		if (buttons_joy2!=button_old2){
			if (buttons_joy2==doorbutton && dooropen==false){//open door
				dooropen=true;
				servo[door]=dooropenpos;
			}
			else if (buttons_joy2==doorbutton && dooropen==true){
				dooropen=false;
				servo[door]=doorclosedpos;
			}

			if (!autoSpinner){
				if (buttons_joy2==spinnerIn && spinneron==false){
					spinneron=true;//forward
					servo[spin1]=spinnerSpeedIn;
					servo[spin2]=spinnerSpeedOut;
				}
				else if (buttons_joy2==spinnerIn && spinneron==true){
					spinneron=false;//stop
					servo[spin1]=127;
					servo[spin2]=127;
				}
				else if (buttons_joy2==spinnerOut && spinneron== false){
					spinneron=true;//back
					servo[spin1]=spinnerSpeedOut;
					servo[spin2]=spinnerSpeedIn;
				}
				else if (buttons_joy2==spinnerOut && spinneron== true){
					spinneron=false;//stop
					servo[spin1]=127;
					servo[spin2]=127;
				}
			}

			if (buttons_joy2==autoSpinnerButton){
				autoSpinner=!autoSpinner;
			}
		}
		button_old2=buttons_joy2;

		if (nMotorRunState[arm]==runStateIdle){
			movement=0;
		}

		//Spinner Arm Level Check
		if (autoSpinner){
			if (nMotorEncoder[arm]>joylevels[1]+50 && (movement==2 || movement==0)){
				servo[spin1]=spinnerSpeedOut;
				servo[spin2]=spinnerSpeedIn;
			}
			else if (nMotorEncoder[arm]<joylevels[1]+50 && (movement==1 || movement==0)){
				servo[spin1]=spinnerSpeedIn;
				servo[spin2]=spinnerSpeedOut;
			}
		}

		//Arm Stop Checking ON LOW LEVEL// -- TO STOP POSITION HOLD WHEN ON LOWEST LEVEL
		if (nMotorRunState[arm]==runStateIdle && (nMotorEncoder[arm]<joylevels[0]+20)){
			motor[arm]=0;
		}

		if (joy_2y1!=0){
			if (joy_2y1>0){
				movement=2;
			}
			else{//must be down
				movement=1;
			}

			manualused=1;
			nMotorEncoderTarget[arm]=0;
			motor[arm]=joy_2y1;
		}
		else if ((tophat==0 || tophat==4)&&tophat!=tophat_old){//Tophat
			if (debug)writeDebugStreamLine("ENTERING TOPHAT");

			if (tophat==0){
				movement=2;
			}
			else{//tophat down
				movement=1;
			}

			for (int ii=0; ii<sizeof(joylevels)/sizeof(joylevels[0]);ii++){
				if (nMotorEncoder[arm]<=joylevels[0]){

					if (debug){
						writeDebugStreamLine("below bottom");
						writeDebugStreamLine("%d",nMotorEncoder[arm]);}

					rounddown=-1;
					roundup=1;
					break;
				}
				else if(nMotorEncoder[arm]>=joylevels[(sizeof(joylevels)/4)-1]){

					if (debug){
						writeDebugStreamLine("above top");
						writeDebugStreamLine("%d",nMotorEncoder[arm]);}

					rounddown=(sizeof(joylevels)/4)-2;
					//-2 cuz its -1 from the length,cuz it starts at 0. and  another -1 cuz
					// its the second two last one

					roundup=-1;
					break;
				}

				if (joylevels[ii]+5>nMotorEncoder[arm] && joylevels[ii]-5<nMotorEncoder[arm]){

					if (debug)writeDebugStreamLine("%d",nMotorEncoder[arm]);

					rounddown=ii-1;//already know it isnt on bottom or top, cuz the first two if's
					roundup=ii+1;
					break;
				}

				if (nMotorEncoder[arm]>joylevels[ii]&&nMotorEncoder[arm]<joylevels[ii+1]){

					if (debug){
						writeDebugStreamLine("goldilocks: d: %d, U: %d",rounddown,roundup);
						writeDebugStreamLine("%d",nMotorEncoder[arm]);
					}

					rounddown=ii;
					roundup=ii+1;
					break;
				}

			}

			if (debug)writeDebugStreamLine("\nrounddown (idx=%d) , roundup (idx=%d)",rounddown,roundup);
			for (int ii=0; ii<sizeof(joylevels)/sizeof(joylevels[0]);ii++)writeDebugStream("[%d]=%d ,",ii,joylevels[ii]);
			if (debug)writeDebugStreamLine("\n");
			if (debug)writeDebugStreamLine("SET MOTOR SPEED to %d from %d in advance of setting target", 0 , motor[arm] );
			motor[arm]=0;

			if (tophat==0 && roundup != -1){//up
				if (debug)writeDebugStreamLine("DRIVING UP to %d from %d",joylevels[roundup] , nMotorEncoder[arm]);
				nMotorEncoderTarget[arm] = joylevels[roundup] - nMotorEncoder[arm];
				if (debug){writeDebugStreamLine("doing %d = %d - %d", nMotorEncoderTarget[arm], joylevels[roundup], nMotorEncoder[arm]);
					writeDebugStreamLine("SET MOTOR SPEED to %d from %d", armspeed , motor[arm] );}
				motor[arm]=armspeed;
			}
			else if (tophat==4 && rounddown != -1){//down
				if (debug)writeDebugStreamLine("DRIVING DOWN to %d from %d",joylevels[rounddown], nMotorEncoder[arm]);
				nMotorEncoderTarget[arm] = (joylevels[rounddown] - nMotorEncoder[arm]);
				if (debug){writeDebugStreamLine("doing %d = %d - %d", nMotorEncoderTarget[arm], joylevels[rounddown], nMotorEncoder[arm]);
					writeDebugStreamLine("SET MOTOR SPEED to %d from %d", -armspeed , motor[arm] );}
				motor[arm]= -armspeed;
			}
			else{
				if (debug)writeDebugStreamLine("SET MOTOR SPEED to %d from %d", 0 , motor[arm] );
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
