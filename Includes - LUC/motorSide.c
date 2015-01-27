void motorSide(tMotor *motors, int speed){
	tMotor motorName;

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
