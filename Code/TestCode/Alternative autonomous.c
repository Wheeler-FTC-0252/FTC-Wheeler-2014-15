#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     compass,        sensorI2CHiTechnicCompass)
#pragma config(Sensor, S3,     touch,          sensorTouch)
#pragma config(Sensor, S4,     SMUX,           sensorI2CCustomFastSkipStates)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     arm,           tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     leftSpliced,   tmotorTetrix, PIDControl, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     left,          tmotorTetrix, PIDControl, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     rightSpliced,  tmotorTetrix, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     right,         tmotorTetrix, PIDControl, reversed, driveRight, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    door,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    spin1,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    spin2,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_4,    catchServo,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Drives backward
task main {
int powerone = -75
int waittime = 2500

motor[leftspliced] = powerone;
motor[left] = powerone;
motor[rightspliced] = powerone;
motor[right] = powerone;
wait1Msec(waittime);

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0;
motor[right] = 0;
wait1Msec(waittime);
}
