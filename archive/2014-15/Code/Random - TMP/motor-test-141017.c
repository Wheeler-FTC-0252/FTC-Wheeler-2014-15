#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	/*
	nxtDisplayCenteredTextLine(3,"%d", nNxtButtonPressed);
	wait10Msec(1000);
	*/
	while (true)
	{
	nxtDisplayCenteredTextLine(2,"%d", nNxtButtonPressed);

		if (nNxtButtonPressed==1)
		{
			motor[motorA]=50;
		}

		if(nNxtButtonPressed==2)
		{
			motor[motorB]=50;
		}

		if(nNxtButtonPressed==-1)
		{
			motor[motorA]=0;
			motor[motorB]=0;
		}

	}
}