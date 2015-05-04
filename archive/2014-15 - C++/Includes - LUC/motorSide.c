void motorSide(tMotor *motors, int speed){
	tMotor motorName;

	// Added this to stop a out of index range error - only currently works with 2 motors
	motorName=motors[0];
	motor[motorName]=speed;
	motorName=motors[1];
	motor[motorName]=speed;
	/*
	for (int ii=0; ii<(sizeof(motors)/ sizeof(tMotor)); ii++){
		motorName=motors[ii];
		motor[motorName]=speed;
	}
	*/
}
