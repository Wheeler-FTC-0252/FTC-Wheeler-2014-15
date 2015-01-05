void nMotorEncoderTargetAbs(tMotor motorin,int targetAbsolute){
	nMotorEncoderTarget[motorin] = targetAbsolute - nMotorEncoder[motorin];
}
