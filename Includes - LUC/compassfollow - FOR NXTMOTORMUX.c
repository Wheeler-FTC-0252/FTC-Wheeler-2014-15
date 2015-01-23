#include "motorSide.c"

// Now has no motor limit -- 150120

void compassfollow(int speed, int rotateSpeed, int rotateTarget, int timeSensorEnable, bool sonarStop, int stopDis, tSensors compass, tSensors bSonar, tSensors rSonar, tMotor *left, tMotor *right, bool sounds=false, bool debug=false){
	int delta;
	clearTimer(T1);
	while(true)
	{
		delta = ( (float)SensorValue[compass] - (float)rotateTarget );
		// Make it so that +angle is heading to right of target (so steer left)
		//  and -ve angle is heading to left of target (so steer right)
		delta = (delta+180 % 360)-180; // Stops problems when close to north
		// always get and answer between -180 and +180 degrees for correction

		delta = delta/100.; // so 100 degrees would be 100% correction

		// Bounds check since we don't want robot to go too fast when trying to correct major errors
		if(abs(delta)>0.9) delta= sgn(delta)*0.9;

		if (debug){
			nxtDisplayCenteredTextLine(6,"delta:%5.1f%%",100.*delta);
			// writeDebugStreamLine("Rotate delta:%f",delta);

			writeDebugStreamLine("Angle sensor:%5d , target %5d ,  delta %5.1f"
			,SensorValue[compass]
			, rotateTarget
			, delta);
		}

		if (rotateSpeed!=0){//rotate
			motorSide(left, (abs(rotateSpeed)*(-delta)));
			motorSide(right, (abs(rotateSpeed)*(delta)));
			if(abs(delta)<0.05) break;
		}
		else{//drive and keep bearing
			motorSide(left, (speed*(1+delta)));
			motorSide(right, (speed*(1-delta)));

			if (stopDis>-1 || time10[T1]>timeSensorEnable){
				if (bSonar<stopDis || rSonar<stopDis){
					break;
				}
			}
		}
	}

	motorSide(left, 0);
	motorSide(right, 0);

	if (sounds){ playSound(soundBeepBeep); while (bSoundActive){}; }
}
