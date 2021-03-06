#pragma config(Motor,  motorC,          ticTac,        tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#define printEncoder
task main()
{
	int encoderValueOld=0;
	int encoderValue;
	int speed=10;
	int firstRotateAmount=185;
	int rotateAmount=60;

	nMotorEncoder[ticTac]=0;
	motor[ticTac]=0;
	nMotorEncoderTarget[ticTac]=firstRotateAmount;
	motor[ticTac]=speed;
	nxtDisplayCenteredBigTextLine(3,"Hold");
	while (nMotorRunState[ticTac]==runStateIdle){}
	nxtDisplayCenteredBigTextLine(3,"");

	while (true){
#ifdef printEncoder
		encoderValue=nMotorEncoder[ticTac];
		if (encoderValueOld!=encoderValue){
			nxtDisplayCenteredBigTextLine(3,"%d",encoderValue);
		}
		encoderValueOld=encoderValue;
#else
		motor[ticTac]=0;
		nMotorEncoderTarget[ticTac]=rotateAmount;
		motor[ticTac]=speed;
		wait1Msec(1000);
#endif
	}
}
