#include "motorSide.c"
#include "hitechnic-sensormux.h"
#include "lego-ultrasound.h"
#include "mindsensors-motormux.h"

// Now has no motor limit -- 150120

void wallfollow(
		int walldis
		,int speed
		,int dropdis
		,int failsafedis
		, tMUXSensor fSonar, tMUXSensor rSonar
		, tMotor *left,tMotor *right
		, bool sounds=false
		, bool debug=false){

	// USER SELECTABLE PARAMETERS
	int speedReductionFactor = 3; // What factor to reduce speed by when slowing, for dock
	int speedMinimum = 10; // Minium speed for slow speed

	// OTHER VARIABLES
	float delta;
	int sonarF; // Distance from front
	int sonarR; // Distance from right
	bool speedSlowed=false; // Flag for slow speed
	int speedsgn; // Used to tempoarily store sign of speed
	tMotor motorName;

	// RESET ALL MOTORS
	for (int ii=0; ii<2; ii++){
		motorName=left[ii];
		nMotorEncoder[motorName]=0;
	}

	for (int ii=0; ii<2; ii++){
		motorName=right[ii];
		nMotorEncoder[motorName]=0;
	}

	// START MOTORS MOVING
	motorSide(left, speed);
	motorSide(right, speed);

	tMotor firstLeftMotor=left[0];
	tMotor firstRightMotor=right[0];

	// LOOP UNTIL WE FIND THE GOAL
	// FAILSAFE IF WE TRAVEL TOO FAR
	while (
			abs(nMotorEncoder[firstLeftMotor])<abs(failsafedis) || abs(nMotorEncoder[firstRightMotor])<abs(failsafedis)
		){

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

		// APPROACHING GOAL
		if ( sonarF < dropdis+5 && !speedSlowed){//ENCODER LEVELS ARE FAKE
			//to slow goal docking
			if (debug) writeDebugStreamLine("SLOW DOWN BY FACTOR %d SINCE NEAR GOAL, Front distance = %d cm" , speedReductionFactor , sonarF );
		  speedsgn = sgn( speed );
			speed = speed / speedReductionFactor;
			// Check to make sure speed reduction isn't too low - must keep robot moving
			if( abs(speed) < abs(speedMinimum) ) speed = speedsgn * speedMinimum;
			speedSlowed=true;
		}

		if (sonarF<dropdis){
			if (debug) writeDebugStreamLine("VERY NEAR GOAL, Front distance = %d cm" , sonarF );
			if (debug) writeDebugStreamLine("MOVE FORWARD FOR A LITTLE LONGER" );
			motorSide(left, speed);
			motorSide(right, speed);
			wait1Msec(1000);
			if (debug) writeDebugStreamLine("STOP MOVING, Front distance = %d cm" , sonarF );
			break;
		}

		if ( sonarR>254 || abs(sonarR-walldis)<1 ){//deadband or if it cant see the wall
			motorSide(left, speed);
			motorSide(right, speed);
		}
		else {
			// motor[left]=speed;
			// Fractional miss
			delta = ( (float)sonarR/(float)walldis - 1 );
			if(debug)	writeDebugStreamLine("Wall following delta = %4.1f",delta);
			// Bounds check since we don't want robot to stop, or reverse a side
			if(abs(delta)>0.9){
				writeDebugStreamLine("WARNING: delta excessive = %4.1f, limiting it",delta);
				delta= sgn(delta)*0.9;
			}

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
