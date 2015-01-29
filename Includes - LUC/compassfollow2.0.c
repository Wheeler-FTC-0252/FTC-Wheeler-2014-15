#include "motorSide.c"
#include "hitechnic-sensormux.h"
#include "lego-ultrasound.h"
#include "mindsensors-motormux.h"

// Now has no motor limit -- 150120

void compassfollow(
		int speed
		, int rotateRelative
		, tSensors compass
		, tMUXSensor bSonar , tMUXSensor lSonar
		, tMotor *left, tMotor *right
		, bool rotateOnly=true
		, int stopDis=-1
		, int timeSensorEnable=-1
		, bool sounds=false, bool debug=false){

	float delta;
	int sonarB;
	int sonarR;

	int rotateTarget=((SensorValue[compass] + rotateRelative)%360);

	tMotor motorName;

	for (int ii=0; ii<2; ii++){
		motorName=left[ii];
		nMotorEncoder[motorName]=0;
	}

	for (int ii=0; ii<2; ii++){
		motorName=right[ii];
		nMotorEncoder[motorName]=0;
	}

	clearTimer(T1);
	while(true)
	{
		sonarB = USreadDist(msensor_S4_4);//bSonar);
		sonarR = USreadDist(lSonar);
		delta = ( (float)SensorValue[compass] - (float)rotateTarget );
		// Make it so that +angle is heading to right of target (so steer left)
		//  and -ve angle is heading to left of target (so steer right)
		delta = (delta+180 % 360)-180; // Stops problems when close to north
		// always get and answer between -180 and +180 degrees for correction

		delta = delta/100.; // 100 degrees would be 100% correction - this affects how quickly angle error is corrected

		// Bounds check since we don't want robot to go too fast when trying to correct major errors
		if(abs(delta)>0.9) delta = sgn(delta)*0.9;

		if (debug){
			nxtDisplayCenteredTextLine(6,"delta:%5.1f%%",100.*delta);
			// writeDebugStreamLine("Rotate delta:%f",delta);
			writeDebugStreamLine("Angle sensor:%5d , Target %5d ,  delta %5.1f"
			, SensorValue[compass]
			, rotateTarget
			, delta);
		}

		if (rotateOnly){//rotate only
			if(debug)writeDebugStreamLine("rotate only");
			motorSide(left, (abs(speed)*(-delta)*2));
			motorSide(right, (abs(speed)*(delta)*2));

			if(abs(delta)<0.05) break;
		}
		else{//drive and keep bearing
			if(debug)writeDebugStreamLine("drive & keep bearing");
			motorSide(right, (speed*(1+sgn(speed)*delta)));
			motorSide(left, (speed*(1-sgn(speed)*delta)));

			if (stopDis>-1 && (time1[T1]>timeSensorEnable || timeSensorEnable<0)){

				if (sonarB < stopDis){
					// BACK SENSOR SHOWS WE ARE CLOSE TO PARKING WALL
				  // *** MIGHT ALSO WANT TO LOOK AT WHAT SIDE SENSOR IS SEEING
					if(debug) writeDebugStreamLine("saw wall (sensor: %d)",sonarB);
					break;
				}
			}
		}
	}

	motorSide(left, 0);
	motorSide(right, 0);

	if (sounds){ playSound(soundBeepBeep); while (bSoundActive){}; }
}
