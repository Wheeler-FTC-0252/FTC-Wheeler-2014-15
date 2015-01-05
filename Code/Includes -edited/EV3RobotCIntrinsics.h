#pragma once
//////////////////////////////////////////////////////////////////////////////////////////////////
//
//													EV3 Low Level ROBOTC Commands
//
//////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TEV3LEDPatterns
{
	ledOff							= 0,
	ledGreen						= 1,
	ledRed							= 2,
	ledOrange						= 3,
	ledGreenFlash				= 4,
	ledRedFlash					= 5,
	ledOrangeFlash			= 6,
	ledGreenPulse				= 7,
	ledRedPulse					= 8,
	ledOrangePulse			= 9,
} TEV3LEDPatterns;

typedef enum TLegoColors
{
  colorNone    = 0,
  colorBlack   = 1,
  colorBlue    = 2,
  colorGreen   = 3,
  colorYellow  = 4,
  colorRed     = 5,
  colorWhite   = 6,
  colorBrown   = 7
} TLegoColors;

typedef enum TEV3Buttons
{
	buttonNone 		= 0,
	buttonUp 			= 1,
	buttonEnter 	= 2,
	buttonDown 		= 3,
	buttonRight 	= 4,
	buttonLeft 		= 5,
	buttonBack 		= 6,
	buttonAny			= 7
} TEV3Buttons;

typedef enum TIRRemoteButtons
{
  IR_NONE									= 0,
  IR_RED_UP								= 1,
  IR_RED_DOWN							= 2,
  IR_BLUE_UP							= 3,
  IR_BLUE_DOWN						= 4,
  IR_RED_UP_BLUE_UP				= 5,
  IR_RED_UP_BLUE_DOWN			= 6,
  IR_RED_DOWN_BLUE_UP			= 7,
  IR_RED_DOWN_BLUE_DOWN		= 8,
  IR_BEACON_MODE_ON				= 9,
  IR_RED_UP_RED_DOWN			= 10,
  IR_BLUE_UP_BLUE_DOWN		= 11
} TIRRemoteButtons;

typedef enum TSmallICONS
{
  SICON_CHARGING                = 0,
  SICON_BATT_4                  = 1,
  SICON_BATT_3                  = 2,
  SICON_BATT_2                  = 3,
  SICON_BATT_1                  = 4,
  SICON_BATT_0                  = 5,
  SICON_WAIT1                   = 6,
  SICON_WAIT2                   = 7,
  SICON_BT_ON                   = 8,
  SICON_BT_VISIBLE              = 9,
  SICON_BT_CONNECTED            = 10,
  SICON_BT_CONNVISIB            = 11,
  SICON_WIFI_3                  = 12,
  SICON_WIFI_2                  = 13,
  SICON_WIFI_1                  = 14,
  SICON_WIFI_CONNECTED          = 15,

  SICON_USB                     = 21,

  S_ICON_NOS
} TSmallICONS;


typedef enum TNormalICONS
{
  ICON_NONE                     = -1,
  ICON_RUN                      = 0,
  ICON_FOLDER                   = 1,
  ICON_FOLDER2                  = 2,
  ICON_USB                      = 3,
  ICON_SD                       = 4,
  ICON_SOUND                    = 5,
  ICON_IMAGE                    = 6,
  ICON_SETTINGS                 = 7,
  ICON_ONOFF                    = 8,
  ICON_SEARCH                   = 9,
  ICON_WIFI                     = 10,
  ICON_CONNECTIONS              = 11,
  ICON_ADD_HIDDEN               = 12,
  ICON_TRASHBIN                 = 13,
  ICON_VISIBILITY               = 14,
  ICON_KEY                      = 15,
  ICON_CONNECT                  = 16,
  ICON_DISCONNECT               = 17,
  ICON_UP                       = 18,
  ICON_DOWN                     = 19,
  ICON_WAIT1                    = 20,
  ICON_WAIT2                    = 21,
  ICON_BLUETOOTH                = 22,
  ICON_INFO                     = 23,
  ICON_TEXT                     = 24,


  ICON_QUESTIONMARK             = 27,
  ICON_INFO_FILE                = 28,
  ICON_DISC                     = 29,
  ICON_CONNECTED                = 30,
  ICON_OBP                      = 31,
  ICON_OBD                      = 32,
  ICON_OPENFOLDER               = 33,
  ICON_BRICK1                   = 34,
  N_ICON_NOS
} TNormalICONS;


typedef enum TLargeICONS
{
  YES_NOTSEL                    = 0,
  YES_SEL                       = 1,
  NO_NOTSEL                     = 2,
  NO_SEL                        = 3,
  OFF                           = 4,
  WAIT_VERT                     = 5,
  WAIT_HORZ                     = 6,
  TO_MANUAL                     = 7,
  WARNSIGN                      = 8,
  WARN_BATT                     = 9,
  WARN_POWER                    = 10,
  WARN_TEMP                     = 11,
  NO_USBSTICK                   = 12,
  TO_EXECUTE                    = 13,
  TO_BRICK                      = 14,
  TO_SDCARD                     = 15,
  TO_USBSTICK                   = 16,
  TO_BLUETOOTH                  = 17,
  TO_WIFI                       = 18,
  TO_TRASH                      = 19,
  TO_COPY                       = 20,
  TO_FILE                       = 21,
  CHAR_ERROR                    = 22,
  COPY_ERROR                    = 23,
  PROGRAM_ERROR                 = 24,


  WARN_MEMORY                   = 27,
  L_ICON_NOS
} TLargeICONS;


const int kFGColor = 1;			// NOTE: FOr most of the X3 opcodees the "Color" is hardcoded as '1'.

// Draw icon
intrinsic void drawIcon(const short X, const short Y, const ICONTYPE iconType, const char iconNumber)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(ICON), constantValue(kFGColor), variable(X), variable(Y), variable(iconType), variable(iconNumber));

// Select font
intrinsic void selectFont(const FONTTYPE fontType)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(SELECT_FONT), variable(fontType));

// Draw QUESTION
intrinsic void drawQuestion(const short X, const short Y, const TLargeICONS icon1, const TLargeICONS icon2, char *pQuestionChars, char &state, char &result)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(QUESTION), constantValue(kFGColor), variable(X), variable(Y),
												 variable(icon1), variable(icon2), variable(pQuestionChars), variableRefRAM(state), variableRefRAM(result));


// Draw ICON question
intrinsic void drawIconQuestion(const short X, const short Y, char &state, const long icons)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(ICON_QUESTION), constantValue(kFGColor), variable(X), variable(Y), variableRefRAM(state), variable(icons));


// Scroll
intrinsic void UIScrollDisplay(const short rowsToScroll)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(SCROLL), variable(rowsToScroll));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Get UI 'back' button blocked flag
intrinsic bool getBlockBackButton()
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(GET_BACK_BLOCK), functionReturn);

// Set UI 'back' button blocked flag
intrinsic void setBlockBackButton(const bool bBlocked)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(SET_BACK_BLOCK), variable(bBlocked));

// Get current state of a button
intrinsic bool getButtonPress(const char button)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(PRESSED), variable(button), functionReturn);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Set LED pattern
intrinsic void setLEDColor(const TEV3LEDPatterns LEDpatterns)
          asm(byte(opcdEV3_LEGO), byte(opUI_WRITE), byte(LED), variable(LEDpatterns));

// Set the connection type for a specific port. Auto-id must be disabled.
typedef enum TConnectionTypes
{
  CONN_UNKNOWN                  = 111,  //!< Connection is fake (test)

  CONN_DAISYCHAIN               = 117,  //!< Connection is daisy chained
  CONN_NXT_COLOR                = 118,  //!< Connection type is NXT color sensor
  CONN_NXT_DUMB                 = 119,  //!< Connection type is NXT analog sensor
  CONN_NXT_IIC                  = 120,  //!< Connection type is NXT IIC sensor

  CONN_INPUT_DUMB               = 121,  //!< Connection type is LMS2012 input device with ID resistor
  CONN_INPUT_UART               = 122,  //!< Connection type is LMS2012 UART sensor

  CONN_OUTPUT_DUMB              = 123,  //!< Connection type is LMS2012 output device with ID resistor
  CONN_OUTPUT_INTELLIGENT       = 124,  //!< Connection type is LMS2012 output device with communication
  CONN_OUTPUT_TACHO             = 125,  //!< Connection type is LMS2012 tacho motor with series ID resistance

  CONN_NONE                     = 126,  //!< Port empty or not available
  CONN_ERROR                    = 127,  //!< Port not empty and type is invalid
} TConnectionTypes;

intrinsic void manuallySetConnectionType(tSensors sensorPort, TConnectionTypes connectionType)
                asm(byte(opcdEV3_LEGO), byte(opINPUT_SET_CONN), variable(sensorPort), variable(connectionType));

// Enable or disable auto-id for a specific sensor port


intrinsic void resetAllSensorAutoID()
          asm(opcdEV3_ROBOTC, byte(ev3ResetAllSensorAutoID));

intrinsic void setSensorAutoID(tSensors sensorPort, bool bEnable)
          asm(opcdEV3_ROBOTC, byte(ev3SetSensorAutoID), variable(sensorPort), variable(bEnable));

//intrinsic void setSensorDevCon(tSensors sensorPort, TSensorTypes sensorDevConType)
//          asm(opcdEV3_ROBOTC, byte(ev3SetSensorDevCon), variable(sensorPort), variable(sensorDevConType));

intrinsic void getSensorDataset(tSensors sensorPort, float *pData, long &size)
					asm(opcdEV3_ROBOTC, byte(ev3GetSensorDataset), variable(sensorPort), variableRefRAM(pData), variableRefLong(size));

intrinsic long getSensorDatasetSize(tSensors sensorPort)
					asm(opcdEV3_ROBOTC, byte(ev3GetSensorDatasetSize), variable(sensorPort), functionReturn);

intrinsic long getMicroTimer()
					asm(opcdEV3_ROBOTC, byte(ev3Microseconds), functionReturn);

intrinsic void shellSort(long *array, int size)
					asm(opcdEV3_ROBOTC, byte(ev3ShellSort), variableRefRAM(array), variable(size));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Mailbox Functions
//

const int kNumbOfMailboxes = 20;

// Open a mailbox. No action is taken if mailbox is already open

intrinsic void openMailbox(short mailboxIndex, char *pMailboxName)
					asm(opcdEV3_ROBOTC, byte(ev3OpenMailbox), variable(mailboxIndex), variable(pMailboxName));

// Close a mailbox.

intrinsic void closeMailbox(short mailboxIndex)
					asm(opcdEV3_ROBOTC, byte(ev3CloseMailbox), variable(mailboxIndex));

// Get the name assigned to a mailbox.

intrinsic void getMailboxName(long mailboxIndex, char *pMailboxName, long nMaxNameLength)
					asm(opcdEV3_ROBOTC, byte(ev3GetMailboxName), variable(mailboxIndex), variableRefRAM(pMailboxName), variable(nMaxNameLength));

// Get size of next message for mailbox
// Negative size inidicates a failure in the transport layer
// A zero size indicate transport link is working and there's simply no message available.

intrinsic int getMailboxMessageSize(long mailboxIndex)
					asm(opcdEV3_ROBOTC, byte(ev3GetMailboxReady), variable(mailboxIndex), functionReturn);

// Read a mailbox message.
// Should first confirm, via call to "getMailboxMessageSize" that a message is available.
// There is no error message to indicate that no message was read.

intrinsic void readMailbox(long mailboxIndex, char *pData, long nReadLength)
					asm(opcdEV3_ROBOTC, byte(ev3ReadMailbox), variable(mailboxIndex), variable(pData), variable(nReadLength));

// Tests if new message has been read
intrinsic bool getMailboxMessageAvailable(const char mailboxIndex)
          asm(byte(opcdEV3_LEGO), byte(opMAILBOX_TEST), variable(mailboxIndex), functionReturn);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void sensorReset(tSensors sensorPort)
					asm(opcdEV3_ROBOTC, byte(ev3SensorReset), variable(sensorPort));

//
// EV3 Touch Sensor Intrinsics
//

// returns true if the touch sensor is pressed, false if it is not
intrinsic bool getTouchValue(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_TouchSensorGetState), variable(nDeviceIndex), functionReturn);

// Returns the number of times the touch sensor has been pressed
intrinsic long getBumpedValue(tSensors sensorPort)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_TouchSensorGetBumped), variable(sensorPort), functionReturn);

// Reset the number of times the touch sensor has been pressed
intrinsic void resetBumpedValue(tSensors sensorPort)
					asm(opcdEV3_ROBOTC, byte(ev3SensorReset), variable(sensorPort));

//
// EV3 Colour Sensor Intrinsics
//

// Get the RGB values (0-255), as detected by the colour sensor.
intrinsic void getColorRGB(tSensors nDeviceIndex, long &pRedChannel, long &pGreenChannel, long &pBlueChannel)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetRGBChannels), variable(nDeviceIndex), variableRefLong(pRedChannel), variableRefLong(pGreenChannel), variableRefLong(pBlueChannel));

// Return the colour "name" (0-7), as detected by the sensor.  Refer to the TLegoColors enum for more details
intrinsic TLegoColors getColorName(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetName), variable(nDeviceIndex), functionReturn);

// Return the amount (0-100) of ambient light detected by the sensor.  This is equivalent to an NXT light sensor
// in inactive mode.
intrinsic unsigned short getColorAmbient(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetAmbient), variable(nDeviceIndex), functionReturn);

// Return the amount (0-100) of reflected light detected by the sensor.  This is equivalent to an NXT light sensor
// in active mode.
intrinsic unsigned short getColorReflected(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetReflected), variable(nDeviceIndex), functionReturn);

// Return the saturation value (01-100) of the detected colour
intrinsic long getColorSaturation(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetSaturation), variable(nDeviceIndex), functionReturn);

// Return the hue value (01-100) of the detected colour
intrinsic long getColorHue(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_ColorSensorGetHue), variable(nDeviceIndex), functionReturn);


//
// EV3 Gyro Sensor Intrinsics
//

// Reset the gyro's position.
intrinsic void resetGyro(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_GyroReset), variable(nDeviceIndex));

// Return the value of degrees the robot has turned
intrinsic long getGyroDegrees(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_GyroGetDegrees), variable(nDeviceIndex), functionReturn);

// Returns the heading of the robot, -179 to +180 degrees
intrinsic long getGyroHeading(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_GyroGetHeading),variable(nDeviceIndex), functionReturn);

// Returns in degrees per second from -440 to +440
intrinsic long getGyroRate(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_GyroGetRate), variable(nDeviceIndex), functionReturn);


//
// EV3 Ultrasound Sensor Intrinsics
//

// Get the distance measured by the US sensor in cm
intrinsic float getUSDistance(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_USGetDistance), variable(nDeviceIndex), functionReturn);


//
// EV3 Infrared Sensor Intrinsics
//

// Returns a distance value 0-100, this is not in a particular unit
intrinsic long getIRDistance(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetDistance), variable(nDeviceIndex), functionReturn);

// Returns a direction indication value, ranging from -25 (far left) to +25 (far right)
// This function uses channel 1
intrinsic long getIRBeaconDirection(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetBeaconDirection), variable(nDeviceIndex), functionReturn);

// Returns a direction indication value, ranging from -25 (far left) to +25 (far right)
// This function uses the specified channel (0-3)
intrinsic long getIRGetBeaconChannelDirection(tSensors nDeviceIndex, long nChannel)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetBeaconChannelDirection), variable(nDeviceIndex), variable(nChannel), functionReturn);

// Returns a stregth value of the beacon signal, ranges from 0 to 100, 0 also means no signal detected
// This function uses channel 1
intrinsic long getIRBeaconStrength(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetBeaconStrength), variable(nDeviceIndex), functionReturn);

// Returns a stregth value of the beacon signal, ranges from 0 to 100, 0 also means no signal detected
// This function uses the specified channel (0-3)
intrinsic long getIRGetBeaconChannelStrength(tSensors nDeviceIndex, long nChannel)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetBeaconChannelStrength), variable(nDeviceIndex), variable(nChannel), functionReturn);

// Returns all the direction and strength values of all the channels (0-3)
intrinsic void getIRBeaconAllChannels(tSensors nDeviceIndex, long *pDirections, long *pStrengths)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRGetBeaconChannelStrength), variable(nDeviceIndex), variableRefRAM(pDirections), variableRefRAM(pStrengths));

// Returns the value indicating which buttons are pressed. Refer to TIRRemoteButtons enum for more details
// This function uses channel 1
intrinsic TIRRemoteButtons getIRRemoteButtons(tSensors nDeviceIndex)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRRemoteGetButtons), variable(nDeviceIndex), functionReturn);

// Returns the value indicating which buttons are pressed. Refer to TIRRemoteButtons enum for more details
// This function uses the specified channel (0-3)
intrinsic TIRRemoteButtons getIRRemoteChannelButtons(tSensors nDeviceIndex, long nChannel)
					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRRemoteGetChannelButtons), variable(nDeviceIndex), variable(nChannel), functionReturn);

//intrinsic void ev3IRRemoteGetAllChannelsButtons(tSensors nDeviceIndex, TIRRemoteButtons *pButtonData)
//					asm(opcdEV3_ROBOTC, byte(ev3Fcn_IRRemoteGetAllChannelsButtons), variable(nDeviceIndex), variableRefRAM(pButtonData));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Set the connection type for a specific port. Auto-id must be disabled.
intrinsic void setSensorConnectionType(tSensors sensorPort, const char connectionType)
                asm(byte(opcdEV3_LEGO), byte(opINPUT_SET_CONN), variable(sensorPort), variable(connectionType));

/////////////////////////////// COPIES OF LEGO FUNCTIONS - Modified for ROBOTC /////////////////////////////////////

// Get minutes to automatically power off [0..120min]
intrinsic char getPowerDownTimer()
                asm(byte(opcdEV3_LEGO), byte(opINFO), byte(GET_MINUTES), functionReturn);

// Set minutes to automatically power off [0..120min]
intrinsic void setPowerDownTimer(const char minutesUntilSleep)
                asm(byte(opcdEV3_LEGO), byte(opINFO), byte(SET_MINUTES), variable(minutesUntilSleep));

// Get battery voltage
intrinsic float getBatteryVoltage()
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_VBATT), functionReturn);

// Get battery current
intrinsic float getBatteryCurrent()
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_IBATT), functionReturn);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Get sound volume level (0..100)
intrinsic char getSoundVolume()
                asm(byte(opcdEV3_LEGO), byte(opINFO), byte(GET_VOLUME), functionReturn);

// Set sound volume level (0..100)
intrinsic void setSoundVolume(const char volumeLevel)
                asm(byte(opcdEV3_LEGO), byte(opINFO), byte(SET_VOLUME), variable(volumeLevel));

// Stop sound
intrinsic void ev3StopSound()
                asm(byte(opcdEV3_LEGO), byte(opSOUND), byte(BREAK));

// Play file repetitively
//intrinsic void playSoundFileRepetitively(char * *pFileName)
//                asm(byte(opcdEV3_LEGO), byte(opSOUND), byte(REPEAT), variable(pFileName));

// Test if sound busy
intrinsic bool ev3GetSoundActive()
                asm(byte(opcdEV3_LEGO), byte(opSOUND_TEST), functionReturn);

// Throw an exception - for the Driver Suite
intrinsic void throwBadSensorPortException()						asm(byte(opcdSetException), constantValue(exceptionSensorPortBadConfiguration));


// Test if file exists
intrinsic bool bEv3FileExists(char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(EXIST), variable(pFileName), functionReturn);

// Draw bmp file
intrinsic void drawBmpfile(const short X, const short Y, char *pFileName)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDraw_EV3DrawPicture),
                variable(X), variable(Y), variableRefFNExists(pFileName));
