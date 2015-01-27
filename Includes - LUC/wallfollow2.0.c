#include "motorSide.c"
#include "hitechnic-sensormux.h"
#include "lego-ultrasound.h"
#include "mindsensors-motormux.h"

// Now has no motor limit -- 150120

void wallfollow(int walldis,int speed,int dropdis,int failsafedis, tMUXSensor fSonar, tMUXSensor rSonar, tMotor *left,tMotor *right, bool sounds=false, bool debug=false){
	int delta;
	int sonarF;
	int sonarR;

	motorSide(left, speed);
	motorSide(right, speed);

	tMotor firstLeftMotor=left[0];
	tMotor firstRightMotor=right[0];

	while (nMotorEncoder[firstLeftMotor]<failsafedis || nMotorEncoder[firstRightMotor]<failsafedis){

		firstLeftMotor=left[0];
		firstRightMotor=right[0];
		sonarF = USreadDist(fSonar);
		sonarR = USreadDist(rSonar);

		if (debug){
			nxtDisplayCenteredTextLine(2,"MotL: %3d",motor[left]);
			nxtDisplayCenteredTextLine(3,"MotR: %3d",motor[right]);
			nxtDisplayCenteredTextLine(4,"SonF: %3d cm",sonarF);
			nxtDisplayCenteredTextLine(5,"SonR: %3d cm",sonarR);
		}

		if (sonarF<dropdis){
			break;
		}

		if ( sonarR>254 || abs(sonarR-walldis)<1 ){//deadband or if it cant see the wall
			motorSide(left, speed);
			motorSide(right, speed);
		}
		else {
			// motor[left]=speed;
			// Fractional miss
			delta = (float)sonarR/(float)walldis-1;
			// Bounds check since we don't want robot to stop, or reverse a side
			if(abs(delta)>0.9) delta= sgn(delta)*0.9;

			if (debug){
				nxtDisplayCenteredTextLine(6,"delta:%5.1f%%",100.*delta);
				writeDebugStreamLine("delta:%f",delta);
			}

			motorSide(left, (speed*(1+delta)));
			motorSide(left, (speed*(1-delta)));
		}
	}
	motorSide(left, 0);
	motorSide(right, 0);

	if (sounds){ playSound(soundBeepBeep); while (bSoundActive){}; }
}
