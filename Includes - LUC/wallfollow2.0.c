#include "motorSide.c"
#include "hitechnic-sensormux.h"
#include "lego-ultrasound.h"
#include "mindsensors-motormux.h"

// Now has no motor limit -- 150120

void wallfollow(int walldis,int speed,int dropdis,int failsafedis, tMUXSensor fSonar, tMUXSensor rSonar, tMotor *left,tMotor *right, bool sounds=false, bool debug=false){
	float delta;
	int sonarF;
	int sonarR;
	tMotor motorName;

	for (int ii=0; ii<2; ii++){
		motorName=left[ii];
		nMotorEncoder[motorName]=0;
	}

	for (int ii=0; ii<2; ii++){
		motorName=right[ii];
		nMotorEncoder[motorName]=0;
	}

	motorSide(left, speed);
	motorSide(right, speed);

	tMotor firstLeftMotor=left[0];
	tMotor firstRightMotor=right[0];

	while (abs(nMotorEncoder[firstLeftMotor])<abs(failsafedis) || abs(nMotorEncoder[firstRightMotor])<abs(failsafedis)){
		sonarF = USreadDist(fSonar);
		sonarR = USreadDist(rSonar);

		/*
		if (abs(nMotorEncoder[firstLeftMotor])>4500 || abs(nMotorEncoder[firstRightMotor])>4500){//if off the ramp
			if (debug)writeDebugStreamLine("off the ramp");
			walldis=10;
		}
		*/

		if (debug){
			nxtDisplayCenteredTextLine(1,"left: %1.3f",/*(float)speed* */(1.+(float)delta));
			nxtDisplayCenteredTextLine(2,"Right: %1.3f",/*(float)speed* */(1.-(float)delta));
			nxtDisplayCenteredTextLine(3,"MotL: %3d",nMotorEncoder[firstLeftMotor]);
			nxtDisplayCenteredTextLine(4,"MotR: %3d",nMotorEncoder[firstRightMotor]);
			nxtDisplayCenteredTextLine(5,"SonF: %3d cm",sonarF);
			nxtDisplayCenteredTextLine(6,"SonR: %3d cm",sonarR);
		}

		if (SensorValue[sonarF]<dropDis+10){//ENCODER LEVELS ARE FAKE
			//to slow goal docking
			speed=speed/2;
		}

		if (sonarF<dropdis){
			if (debug)writeDebugStreamLine("saw something");
			motorSide(left, speed);
			motorSide(right, speed);
			wait1Msec(1000);
			writeDebugStreamLine("finished waiting shunt");
			break;
		}

		if ( sonarR>254 || abs(sonarR-walldis)<1 ){//deadband or if it cant see the wall
			motorSide(left, speed);
			motorSide(right, speed);
		}
		else {
			// motor[left]=speed;
			// Fractional miss
			delta = ((float)sonarR/(float)walldis-1);
			// Bounds check since we don't want robot to stop, or reverse a side
			if(abs(delta)>0.9) delta= sgn(delta)*0.9;

			if (debug){
				writeDebugStreamLine("Left ENC: %d, Right ENC: %d",nMotorEncoder[firstLeftMotor],nMotorEncoder[firstRightMotor]);
//				writeDebugStreamLine("sonarR/walldis-1=%f (delta)",(delta);
				nxtDisplayCenteredTextLine(7,"delta:%5.1f%%",100.*delta);
				//writeDebugStreamLine("delta:%f",delta);
			}

			motorSide(left, (speed*(1+sgn(speed)*delta)));
			motorSide(right, (speed*(1-sgn(speed)*delta)));
		}
	}

	motorSide(left, 0);
	motorSide(right, 0);

	if (sounds){ playSound(soundBeepBeep); while (bSoundActive){}; }
}
