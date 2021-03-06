#pragma config(Sensor, S1,     HTSMUX,         sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-pir-SMUX-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * hitechnic-pir.h provides an API for the HiTechnic PIR Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 26 August 2009
 * version 0.1
 */

#include "drivers/hitechnic-sensormux.h"
#include "drivers/hitechnic-pir.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTPIR = msensor_S1_1;

// Draw a little stick figure
void drawStickFigure(int offset)
{
  nxtEraseRect(0, 0, 99, 50);
  nxtDrawCircle(offset + 43, 40, 15);
  nxtDrawLine(offset + 50,25,offset + 50,10);
  nxtDrawLine(offset + 43, 22, offset + 58, 22);
  nxtDrawLine(offset + 43, 0, offset + 50, 10);
  nxtDrawLine(offset + 50, 10, offset + 58, 0);
}

task main () {
  int reading = 0;
  int x = 0;

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "PIR");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and sensor to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");
  wait1Msec(2000);

  eraseDisplay();

  while(true) {
    // Get the IR levels from the PIR sensor
    // Please note that you cannot change the deadband value when the
    // sensor is connected to the SMUX.
    reading = HTPIRreadSensor(HTPIR);
    nxtDisplayTextLine(0, "HT PIR: %d", reading);

    x = (40 * reading) / 100;
    drawStickFigure(x);
    wait1Msec(50);
  }
}

/*
 * $Id: hitechnic-pir-SMUX-test1.c 133 2013-03-10 15:15:38Z xander $
 */
