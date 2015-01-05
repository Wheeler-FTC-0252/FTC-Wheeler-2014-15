#if !defined(__PropertyTypes__H_)
#define __PropertyTypes__H_

typedef enum TPropertyTypes
{
	propertyUnused00                          =  0,

	propertySensor                      			=  1,
	propertySensorType                  			=  2,
	propertySensorBoolean               			=  3, //  boolean sensor value

	propertySensorBias                        =  4,
	propertySensorScale                       =  5,
	propertySensorFullCount                   =  6,
	propertySensorSmallBias                  	=  7,

#if defined(bHasSourceTypeSensorMode) || defined(_WINDOWS)
	propertySensorMode                  			=  8, // output to sensor <0..2>
#endif

#if defined(bHasSourceTypeSensorRawValue) || defined(_WINDOWS)
	propertySensorRaw                   			=  9, // raw sensor value <0..2>
#endif

	propertyMotorPower												= 10,	 //  New. Power levels -100 to +100 range

#if defined(bFirmwareStoresMotorType) || defined(_WINDOWS)
	propertyMotorType													= 11,  // 180 degree motor adjustment (rather than reversing wires)
#endif

#if defined(bMotorMirroring) || defined(_WINDOWS)
	propertyMotorReflectDirection       			= 12,  // 180 degree motor adjustment (rather than reversing wires)
#endif

#if (bSmartMotorsWithEncoders() != 0) || defined(VexIQ) || defined(NXT) || defined(EV3) || defined(_WINDOWS)
	propertyMotorEncoderTargetRelative				= 13,  // Target Encoder counts -- relative count from current position
#endif

#if (bSmartMotorsWithEncoders() != 0) || defined(VexIQ) || defined(_WINDOWS)
	propertyMotorEncoderTargetAbsolute				= 14,	 // Target Encoder counts -- absolute number. Not user accessible; used for uploading motor info to Debugging window in IDE.
#endif

#if defined(NXT) || defined(_WINDOWS)
	propertyMotorRunState               			= 15,  // Motor movement state (NXT)
#endif

#if (bSmartMotorsWithEncoders() != 0) || defined(_WINDOWS)
	propertyMotorRegulation             			= 16,  // Motor regulation state
#endif

#if defined(bMotorsWithCurrentLimiting)
	propertyMotorCurrentLimit    							= 17,
#endif

#if (defined(bMotorsWithEncoders) || defined(bAssociateMotorWithEncoderSensor)) || (bSmartMotorsWithEncoders() != 0) || defined(_WINDOWS)
	propertyMotorEncoder											= 18,  // Actual Encoder counts from smart motors (NXT)
	propertyMotorEncoderRaw										= 19,  // Actual Encoder counts from smart motors (NXT)
#endif

#if defined(NXT) || defined(_WINDOWS)
	propertyNxtMotorFloatDuringInactivePWM		= 20, //  0..2. Individual control over motors for float vs brake during inactive PWM.
#endif


#if ((bSmartMotorsWithEncoders() != 0) && !defined(NXT)) || defined(_WINDOWS)
	propertyPid_Period												= 21,
	propertyPid_kP														= 22,
	propertyPid_kI														= 23,
	propertyPid_kD														= 24,
	propertyPid_Deadband											= 25,
	propertyPid_ErrorP												= 26,
	propertyPid_ErrorI												= 27,
	propertyPid_ErrorD												= 28,
	propertyMotorPWM													= 29,  // Actual PWM power level applied
	propertyPid_StartEncoderCount							= 30,
#endif

#if defined(EV3) || defined(_WINDOWS)
	propertySensorFloat												= 31,
#endif

#if defined(bFirmwareStoresMotorDriveSide) || defined(_WINDOWS)
	propertyMotorDriveSide										= 32,	// driveNone, driveLeft, driveRight -- which side a motor drives robot on
#endif

	//Unused																	= 33,
	//Unused																	= 34,
	//Unused																	= 35,
	//Unused																	= 36,
	//Unused																	= 37,
	//Unused																	= 38,
	//Unused																	= 39,
	//Unused																	= 40,

	// DO NOT CHANGE
	propertySystem                      			= 41, //  Contains many 'subvariables' to customize ROBOTC firmware. DO NOT CHANGE VALUE OR WILL SCREW UP IDE VERSION CHECKING.
	// DO NOT CHANGE

	propertyRandom                      			= 42, //  random <return value is in 0 to argument, inclusive>

	property1MsecTimer                  			= 43, //  0-3. 1 millisecond timer.
	property10MsecTimer                 			= 44, //  0-3.
	property100MsecTimer                			= 45, //  timers <0..3>

	propertyConstant													= 46,

	propertyCallStackStartAddress							= 47,		// Indexed by task number
	propertyCallStackCurrSize									= 48,		// Indexed by task number
	propertyVariablesStackStartAddress				= 49,		// Indexed by task number


#if defined(bHasServoSpecificSourceTypes) || defined(_WINDOWS)
	propertyServoType                   			= 50, //  Standard or continuous rotation servo
	propertyServoMinPos												= 51, //
	propertyServoMaxPos												= 52, //
	propertyServoTarget                 			= 53, //  Access to TETRIX Servos - Target Setting
	propertyServoPosition               			= 54, //  Access to TETRIX Servos
	propertyServoRateOfChange           			= 55, //  Access to TETRIX Servos - Rate of Change per 10 Msec Setting
#endif


#if defined(NXT) || defined(EV3) || defined(_WINDOWS)
	propertyLegoI2CBytesReady                  = 56, //  Number of I2C Message Bytes Ready
	propertyLegoI2CMessagingStatus             = 57, //  I2C Messaging Status
#endif

#if defined(bHasEvents)  || defined(_WINDOWS)
	propertyEventType                         = 58, // 0-15. Type of event being detected
	propertyEvent                             = 59, // 0-15. Type of sensor for event
	propertyEventCounts                       = 60, // 0-15. Count of number of event occurrences
	propertyEventState                        = 61, // 0-15. Low, normal, or high
	propertyTaskEvents                        = 62, // 0-9.  Bit mask showing which events alerted the task
	propertyClickCounter                      = 63, // 0-15. Numb of clicks detected for event sensor
	propertyUpperThreshold                    = 64, // 0-15. Used for event generation
	propertyDuration                          = 65, // 0-15, Blink time. Measured in 10 msec units. Minimum value is 5
	propertyLowerThreshold                    = 66, // 0-15.
	propertyHysteresis                        = 67, // 0-15
#endif //#if defined(bHasEvents)  || defined(_WINDOWS)


#if defined(bUserMessagesAllowed) || defined(_WINDOWS)
	propertyMessage														= 68,
#endif

#if defined(VEX) || defined(VEX2) || defined(VexIQ) || defined(_WINDOWS)
	propertyIFIRadioControl             			= 69, //  Access to VEX RF Controller
#endif

#if defined(VEX) || defined(_WINDOWS)
	propertyIfiInterruptPort            			= 70,
#endif

#if defined(ARMCPU) || defined(_WINDOWS)
	propertyCamera                      			= 71, //
#endif

#if defined(NXT) || defined(_WINDOWS)
	propertyDigitalPinDirection               = 72,		// For NXT "sensorCustom". Direction of the two digital I/O pins.
	propertyDigitalPinValue										= 73,		// For NXT "sensorCustom". Value     of the two digital I/O pins.
#endif

	kNumbOfPropertyTypes,
	propertyBad																= kNumbOfPropertyTypes,
} TPropertyTypes;


#endif //#if !defined(__PropertyTypes__H_)
