void motorSide(tMotor *motors, int speed){
	tMotor motorName;
	for (int ii=0; ii<(sizeof(motors)/ sizeof(tMotor)); ii++){
		motorName=motors[ii];
		motor[motorName]=speed;
	}
}
