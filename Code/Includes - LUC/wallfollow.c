void wallfollow(int walldis,int speed,int dropdis,int failsafedis,tSensors fSonar,tSensors rSonar, tMotor left,tMotor right){
	int debug=true;
	int delta;
	int sonarF;
	int sonarR;
	motor[left]=speed;
	motor[right]=speed;


	while (nMotorEncoder[left]<failsafedis || nMotorEncoder[right]<failsafedis){

		sonarF = SensorValue[fSonar];
		sonarR = SensorValue[rSonar];

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
			motor[left]=speed;
			motor[right]=speed;
		}
		else {
			// motor[left]=speed;
			// Fractional miss
			delta = (float)SensorValue[rSonar]/(float)walldis-1;
			// Bounds check since we don't want robot to stop, or reverse a side
			if(abs(delta)>0.9) delta= sgn(delta)*0.9;
			nxtDisplayCenteredTextLine(6,"delta:%5.1f%%",100.*delta);
			writeDebugStreamLine("delta:%f",delta);
			motor[left]=speed*(1+delta);
			motor[right]=speed*1/(1+delta);
		}
	}
	motor[left]=0;
	motor[right]=0;

	playSound(soundBeepBeep); while (bSoundActive){}
}
