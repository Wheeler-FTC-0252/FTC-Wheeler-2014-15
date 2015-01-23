#include "mindsensors-motormux.h"

void motorSideMUX(tMUXmotor *motors, int speed){
	tMUXmotor motorName;
	for (int ii=0; ii<(sizeof(motors)/ sizeof(tMUXmotor)); ii++){
		motorName=motors[ii];
		MSMMotor(motorName,speed);
	}
}
