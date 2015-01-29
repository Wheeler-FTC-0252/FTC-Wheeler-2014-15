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
int powerone = 75
int powertwo = 50
int powerthree = 25
int waittimeone = 1000
int waittimetwo = 2000
int waittimethree = 3000

motor[leftspliced] = -powerone;
motor[left] = -powerone;
motor[rightspliced] = -powerone; ///gets into position to begin turning
motor[right] = -powerone;
wait1Msec(waittimeone); //this will need to be tested

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);

motor[leftspliced] = -powertwo;
motor[left] = -powertwo;
motor[rightspliced] = powertwo; // turn left
motor[right] = powertwo;
wait1Msec(waittimetwo); //this will need to be tested;

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);

motor[leftspliced] = -powerthree;
motor[left] = -powerthree;
motor[rightspliced] = -powerthree; // go straight
motor[right] = -powerthree;
wait1Msec(waittimethree);

motor[leftspliced] = -powertwo;
motor[left] = -powertwo;
motor[rightspliced] = powertwo; // turn left around 90 degrees
motor[right] = powertwo;
wait1Msec(waittimetwo); //this will need to be tested; degree = 90

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);

motor[leftspliced] = -powerthree;
motor[left] = -powerthree;
motor[rightspliced] = -powerthree; // go straight
motor[right] = -powerthree;
wait1Msec(waittimethree);

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);

motor[leftspliced] = -powertwo;
motor[left] = -powertwo;
motor[rightspliced] = powertwo; // turn left around 90 degrees
motor[right] = powertwo;
wait1Msec(waittimetwo); //this will need to be tested; degree = 90

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);

motor[leftspliced] = -powerthree;
motor[left] = -powerthree;
motor[rightspliced] = -powerthree; // go straight
motor[right] = -powerthree;
wait1Msec(waittimethree);

motor[leftspliced] = 0;
motor[left] = 0;
motor[rightspliced] = 0; //stop
motor[right] = 0;
wait1Msec(500);
}
