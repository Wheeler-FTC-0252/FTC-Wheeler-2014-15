#if !defined(MainIncludes__H_) && !defined(_WINDOWS)
	#error "'vmtypedefs.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#ifndef VMTypedefs__H_
#define VMTypedefs__H_

#ifdef __cplusplus
	extern "C" {
#endif

#undef COMPILER_SHORT_ALIGNED
#undef COMPILER_CHAR_ALIGNED
#if defined(ARMCPU)
	#if defined(__GNUC__) || defined(__CC_ARM)
		//#define COMPILER_SHORT_ALIGNED    __attribute__((__aligned__(2)))
		#define COMPILER_CHAR_ALIGNED       __attribute__((__aligned__(1)))
	#elif defined(__ICCARM__)
		#define COMPILER_PRAGMA(arg)        _Pragma(#arg)
		//#define COMPILER_SHORT_ALIGNED    COMPILER_PRAGMA(data_alignment = 2)
		#define COMPILER_CHAR_ALIGNED       __packed
	#else
		#error "Invalid conditional compile logic."
	#endif
#else
	//#define COMPILER_SHORT_ALIGNED
	#define COMPILER_CHAR_ALIGNED
#endif

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                       Intrinsic RCX Instruction Definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////

#if defined(ARMCPU)

	typedef COMPILER_CHAR_ALIGNED struct TShortMessageBuffer
	{
		ubyte				opCode;
		ubyte				msgBytes[15];
	} TShortMessageBuffer;

#else   // VEX. Byte packing!

	typedef COMPILER_CHAR_ALIGNED struct TShortMessageBuffer
	{
#if defined(_WIN32) || defined(EV3) || defined(PIC32) || defined(_WINDOWS) || defined(Simulator)
		ubyte 				opCode;
#else
		TVMOpcode			opCode;
#endif
		ubyte					msgBytes[16];
	} TShortMessageBuffer;

#endif

typedef enum TTimerIndex
{
	timer1              = 0,
	timer2              = 1,
	timer3              = 2,
	timer4              = 3
} TTimerIndex;

typedef enum TMotorIndex
{
#if defined(NXT) || defined(_WINDOWS)

	motorA							= 0,						// NXT integrated motor ports
	motorB							= 1,
	motorC							= 2,

	//
	// HiTechnic Motor Controllers.
	//    - Each controller supports two motors
	//    = Up to four controllers per sensor port.
	//
	motorD							=  3,
	motorE,
	motorF,
	motorG,

#endif

#if defined(VEX) || defined(VEX2) || defined(_WINDOWS)

	port1         = 0,
	port2         = 1,
	port3         = 2,
	port4         = 3,
	port5         = 4,
	port6         = 5,
	port7         = 6,
	port8         = 7,


#if defined(VEX2) || defined(_WINDOWS)
	port9         = 8,
	port10        = 9,
#endif

#if defined(VexIQ) || defined(_WINDOWS)
	port11        = 10,
	port12        = 11,
#endif

#endif

#if defined(NXT) || defined(_WINDOWS)
#elif defined(VEX) || defined(VEX2) || defined(_WINDOWS)
#else

	xxyyzz				= 0,	// So that there is at least one entry
#endif

} TMotorIndex;


#if defined(NXT) || defined(_WINDOWS)

typedef enum TSensorPortHub
{
	muxNone											= 0,

	muxHiTMotor									= 1,
	muxHiTServo									= 2,

	muxMatrixRoboticsController	= 3,

	muxHiTTouch									= 4,

	muxLEGO485Nxt								= 5,  // Special -- not implemented yet.
	kNumbOfMuxTypes,
} TSensorPortHub;

//typedef enum TServoIndex
//{
//	//
//	// HiTechnic and Mindsensor Servo Controllers.
//	//    - Each controller supports six (Hitechnic) or eight (Mindsensors)
//	//    = Up to four controllers per sensor port.
//	//
//	srvo_S1_C1_1        =  0,
//	srvo_S1_C1_2,
//	srvo_S1_C1_3,
//	srvo_S1_C1_4,
//	srvo_S1_C1_5,
//	srvo_S1_C1_6,
//
//	servo1							=  6,
//	servo2,
//	servo3,
//	servo4,
//	servo5,
//	servo6,
//
//	srvo_S1_C2_1				=  6,
//	srvo_S1_C2_2,
//	srvo_S1_C2_3,
//	srvo_S1_C2_4,
//	srvo_S1_C2_5,
//	srvo_S1_C2_6,
//
//	srvo_S1_C3_1,
//	srvo_S1_C3_2,
//	srvo_S1_C3_3,
//	srvo_S1_C3_4,
//	srvo_S1_C3_5,
//	srvo_S1_C3_6,
//
//	srvo_S1_C4_1,
//	srvo_S1_C4_2,
//	srvo_S1_C4_3,
//	srvo_S1_C4_4,
//	srvo_S1_C4_5,
//	srvo_S1_C4_6,
//
//	srvo_S2_C1_1,
//	srvo_S2_C1_2,
//	srvo_S2_C1_3,
//	srvo_S2_C1_4,
//	srvo_S2_C1_5,
//	srvo_S2_C1_6,
//
//	srvo_S2_C2_1,
//	srvo_S2_C2_2,
//	srvo_S2_C2_3,
//	srvo_S2_C2_4,
//	srvo_S2_C2_5,
//	srvo_S2_C2_6,
//
//	srvo_S2_C3_1,
//	srvo_S2_C3_2,
//	srvo_S2_C3_3,
//	srvo_S2_C3_4,
//	srvo_S2_C3_5,
//	srvo_S2_C3_6,
//
//	srvo_S2_C4_1,
//	srvo_S2_C4_2,
//	srvo_S2_C4_3,
//	srvo_S2_C4_4,
//	srvo_S2_C4_5,
//	srvo_S2_C4_6,
//
//	srvo_S3_C1_1,
//	srvo_S3_C1_2,
//	srvo_S3_C1_3,
//	srvo_S3_C1_4,
//	srvo_S3_C1_5,
//	srvo_S3_C1_6,
//
//	srvo_S3_C2_1,
//	srvo_S3_C2_2,
//	srvo_S3_C2_3,
//	srvo_S3_C2_4,
//	srvo_S3_C2_5,
//	srvo_S3_C2_6,
//
//	srvo_S3_C3_1,
//	srvo_S3_C3_2,
//	srvo_S3_C3_3,
//	srvo_S3_C3_4,
//	srvo_S3_C3_5,
//	srvo_S3_C3_6,
//
//	srvo_S3_C4_1,
//	srvo_S3_C4_2,
//	srvo_S3_C4_3,
//	srvo_S3_C4_4,
//	srvo_S3_C4_5,
//	srvo_S3_C4_6,
//
//	srvo_S4_C1_1,
//	srvo_S4_C1_2,
//	srvo_S4_C1_3,
//	srvo_S4_C1_4,
//	srvo_S4_C1_5,
//	srvo_S4_C1_6,
//
//	srvo_S4_C2_1,
//	srvo_S4_C2_2,
//	srvo_S4_C2_3,
//	srvo_S4_C2_4,
//	srvo_S4_C2_5,
//	srvo_S4_C2_6,
//
//	srvo_S4_C3_1,
//	srvo_S4_C3_2,
//	srvo_S4_C3_3,
//	srvo_S4_C3_4,
//	srvo_S4_C3_5,
//	srvo_S4_C3_6,
//
//	srvo_S4_C4_1,
//	srvo_S4_C4_2,
//	srvo_S4_C4_3,
//	srvo_S4_C4_4,
//	srvo_S4_C4_5,
//	srvo_S4_C4_6,
//
//	//
//	// Matrix Servo Controllers.
//	//    - Each controller supports four servos
//	//    = One controllers per sensor port.
//	//
//	srvo_Matrix_S1_1        =  srvo_S1_C1_1,	// Servos on Matrix Controllers on Sensor Port S1
//	srvo_Matrix_S1_2,
//	srvo_Matrix_S1_3,
//	srvo_Matrix_S1_4,
//
//	srvo_Matrix_S2_1				=  srvo_S2_C1_1,		// Servos on Matrix Controllers on Sensor Port S2
//	srvo_Matrix_S2_2,
//	srvo_Matrix_S2_3,
//	srvo_Matrix_S2_4,
//
//	srvo_Matrix_S3_1				=  srvo_S3_C1_1,		// Servos on Matrix Controllers on Sensor Port S3
//	srvo_Matrix_S3_2,
//	srvo_Matrix_S3_3,
//	srvo_Matrix_S3_4,
//
//	srvo_Matrix_S4_1				=  srvo_S4_C1_1,		// Servos on Matrix Controllers on Sensor Port S4
//	srvo_Matrix_S4_2,
//	srvo_Matrix_S4_3,
//	srvo_Matrix_S4_4,
//
//} TServoIndex;

typedef struct
{
  uword            nUpdateResets;
  uword            nUpdateCycles;
  uword            nMsgSends;
	TSensorPortHub   nHubType;
} TSensorPortMuxStatistics;

#endif

typedef enum tSensors
{
#if defined(NXT) || defined(_WINDOWS)
	S1							= 0,
	S2							= 1,
	S3							= 2,
	S4							= 3,
#endif

#if defined(VEX) || defined(VEX2) || defined(VexIQ) || defined(AVRCPU) || defined(Generic) || defined(_WINDOWS)
	in1							=  0,
	in2							=  1,
	in3							=  2,
	in4							=  3,
	in5							=  4,
	in6							=  5,
	in7							=  6,
	in8							=  7,
#endif

#if defined(VEX) || defined(STM3210E) || defined(AVRCPU) || defined(Generic) || defined(_WINDOWS)
	in9							=  8,
	in10 						=  9,
	in11 						= 10,
	in12 						= 11,
	in13 						= 12,
	in14 						= 13,
	in15 						= 14,
	in16 						= 15,
#endif

#if defined(VEX2)  || defined(Generic) || defined(_WINDOWS)
	dgtl1	 					=  8,
	dgtl2	 					=  9,
	dgtl3	 					= 10,
	dgtl4	 					= 11,
	dgtl5	 					= 12,
	dgtl6	 					= 13,
	dgtl7	 					= 14,
	dgtl8	 					= 15,
	dgtl9						= 16,
	dgtl10					= 17,
	dgtl11					= 18,
	dgtl12					= 19,
#endif

#if defined(VexIQ)|| defined(_WINDOWS)
	portX1	 					=  0,
	portX2	 					=  1,
	portX3	 					=  2,
	portX4	 					=  3,
	portX5	 					=  4,
	portX6	 					=  5,
	portX7	 					=  6,
	portX8	 					=  7,
	portX9						=  8,
	portX10					=  9,
	portX11					= 10,
	portX12					= 11,
#endif

#if defined(VEX2) || defined(_WINDOWS)
	I2C_1	 					= 20,
	I2C_2	 					= 21,
	I2C_3	 					= 22,
	I2C_4	 					= 23,
	I2C_5	 					= 24,
	I2C_6	 					= 25,
	I2C_7	 					= 26,
	I2C_8	 					= 27,
#endif

	lastSensor

} tSensors;



typedef enum TSensorIndexForEvents
{
	sensor1   = (ubyte) 0,
	sensor2   = (ubyte) 1,
	sensor3   = (ubyte) 2
} TSensorIndexForEvents;


typedef struct TUByteArray
{
	ubyte ubytes[40];
} TUByteArray;

typedef struct TByteArray16
{
	ubyte ubytes[16];
} TByteArray16;

typedef struct TWordArray
{
	short words[40];
} TWordArray;

typedef struct TLongWord
{
	short upperWord;
	short lowerWord;
} TLongWord;



#ifdef __cplusplus
	}
#endif

#endif //#ifndef VMTypedefs__H_
