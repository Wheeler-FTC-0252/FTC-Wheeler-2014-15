#ifndef CompilerTypedefs__H_
#define CompilerTypedefs__H_

#if !defined(MainIncludes__H_) && !defined(_WINDOWS) && !defined(WIN32)
	#error "'CompilerTypedefs.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#if defined(WIN32)
	#include "stddef.h"
#endif

#ifdef __cplusplus
	extern "C" {
#endif


#if !defined(bytesDeclared)
	#define bytesDeclared
	#define byteDeclareRequired
	typedef unsigned char ubyte;
	typedef signed char sbyte;
#endif


#ifndef __cplusplus
	#if defined(VEX)|| defined(Simulator) || defined(_WINDOWS)
		typedef unsigned char bool;
		#define false 0
		#define true 1
	#elif defined(ARMCPU) || defined(CHIPKITMAX) || defined(AVRCPU) || defined(STM8CPU) || defined(Generic)
		#include "stdbool.h"
	#endif

	#if defined(byteDeclareRequired)
		//typedef signed char sbyte;
	#endif
#endif

#if !defined(NULL)
#define NULL 0
#endif

typedef signed short word;
typedef signed short sword;
typedef unsigned short uword;

typedef long word32;
#if defined(EV3)
	// Work around a quirk of GCC defines
	#define __USE_MISC
	#include "sys/types.h"
	#if !defined(__USE_MISC)
		typedef unsigned long int ulong;
	#endif
#else
	typedef unsigned long ulong;
#endif
typedef unsigned long uword32;

#undef ubyte
#undef sbyte

// NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!
//
// Following declarations have been closely hand-optimized by looking at generated compiler code to get best real-time performance.
// DO NOT CHANGE THEM!!!!
//
// Subtle differences in some of the comparisons can create major differences in generated code and efficient implementation of these
// macros is important for the ROBOTC VM.
//
// For example, loading two bytes into a 16-bit integer can be as short as two 8-bit loads. But some declarations will result in loading
// two 32-bit integers (i.e. 8-bit load followed by zeroing upper 24-bits, then another 8-bit to 32-bit load, then a "<< 8" on 32 bit value
// and then finally OR-int the two 32-bit values. This takes many many instructions!
//
// NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!    NOTE!!!

#if defined(Simulator) || defined(_WINDOWS)

	#define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

	#define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

	typedef signed   long TSSmallValue;		// 32-bits
	typedef unsigned long TUSmallValue;		// 32-bits
	typedef signed   long TLargeValue;		// 32-bits
	typedef unsigned long TULargeValue;		// 32-bits
	typedef unsigned long TTaskStackItem;	// 32-bits

#elif defined(EV3) || defined(NXT)

	#define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))
	#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))

	#define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

	typedef signed   int TSSmallValue;		// 32-bits
	typedef unsigned int TUSmallValue;		// 32-bits
	typedef signed   int TLargeValue;			// 32-bits
	typedef unsigned int TULargeValue;		// 32-bits
	typedef unsigned int TTaskStackItem;	// 32-bits

#elif  defined(PIC32)

	#define bytesToSWord(lowerByte, upperByte) ((word) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8))))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	#define bytesToUWord(lowerByte, upperByte) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8)))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	typedef signed   long TSSmallValue;		// 32-bits
	typedef unsigned long TUSmallValue;		// 32-bits
	typedef signed   long TLargeValue;		// 32-bits
	typedef unsigned long TULargeValue;		// 32-bits
	typedef unsigned long TTaskStackItem;	// 32-bits

#elif defined(VEX2) || defined(ArduinoCortex) || defined(VexIQ)

	#define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))

	//#define bytesToSWord(lowerByte, upperByte)  (((((TLargeValue) ( ((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))
	#define getLowHighParmSWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

	#define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) (*(uword *) &pCurrOp->parmLow)

	typedef signed   long TSSmallValue;		// 32-bits
	typedef unsigned long TUSmallValue;		// 32-bits
	typedef signed   long TLargeValue;		// 32-bits
	typedef unsigned long TULargeValue;		// 32-bits
	typedef unsigned long TTaskStackItem;	// 32-bits

#elif defined(AVRCPU) || defined(Generic)

	#define bytesToUWordXXX(lowerByte, upperByte) \
	(__extension__({                \
			uint8_t __lowerByte = (uint8_t)(lowerByte); \
			uint8_t __upperByte = (uint8_t)(upperByte); \
			uint16_t __result;           \
			__asm__                     \
			(                           \
				"mov %A0, %1"   "\n\t"    \
				"mov %B0, %2"   "\n\t"    \
					: "=r" (__result)       \
					: "r" (__lowerByte),    \
						"r" (__upperByte)     \
			);                          \
			__result;                   \
	}))

	#define bytesToSWordXXX(lowerByte, upperByte) \
	(__extension__({                \
			uint8_t __lowerByte = (uint8_t)(lowerByte); \
			uint8_t __upperByte = (uint8_t)(upperByte); \
			int16_t __result;           \
			__asm__                     \
			(                           \
				"mov %A0, %1"   "\n\t"    \
				"mov %B0, %2"   "\n\t"    \
					: "=r" (__result)       \
					: "r" (__lowerByte),    \
						"r" (__upperByte)     \
			);                          \
			__result;                   \
	}))

	#define bytesToSWord(lowerByte, upperByte)  ((word) ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte)))

	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	//#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

	#define bytesToUWord(lowerByte, upperByte)  ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))

	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	//#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) (*(uword *) &pCurrOp->parmLow)

	typedef sbyte TSSmallValue;       //   8-bits
	typedef ubyte TUSmallValue;       //   8-bits

	#if (defined(__AVR_ATmega328P__) || defined(__AVR_ATmega32U4__))
		typedef word  TLargeValue;						//  16-bits
		typedef uword TULargeValue;						//  16-bits
	#elif defined(__AVR_ATmega128__) || (defined(__AVR_ATmega1281__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__))
		typedef signed   long  TLargeValue;		//  32-bits
		typedef unsigned long TULargeValue;   //  32-bits
	#endif

	typedef uword TTaskStackItem;			//  16-bits

#elif defined(VEX)

	//
	// Need to ensure that C18 PIC compiler doesn't do 'bytesToWord' in all 'sbyte' arithmetic. To do this, at least one of the
	// parameters must be cast as 'uword' because compiler only looks at size of expression factors and not size of result in
	// determining the precision of expression evaluation.
	//
	#define bytesToSWord(lowerByte, upperByte) ((word) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8))))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

	#define bytesToUWord(lowerByte, upperByte) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8)))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) (*(uword *) &pCurrOp->parmLow)

	typedef sbyte TSSmallValue;       //   8-bits
	typedef ubyte TUSmallValue;       //   8-bits
	typedef word  TLargeValue;        //  16-bits
	typedef uword TULargeValue;       //  16-bits
	typedef uword TTaskStackItem;			//  16-bits

#elif defined(STM8CPU)

	//
	// Need to ensure that C18 PIC compiler doesn't do 'bytesToWord' in all 'sbyte' arithmetic. To do this, at least one of the
	// parameters must be cast as 'uword' because compiler only looks at size of expression factors and not size of result in
	// determining the precision of expression evaluation.
	//
	#define bytesToSWord(lowerByte, upperByte) ((word) ((uword) (/*(ubyte)*/ (lowerByte & (ubyte) 0xFF) | ((/*(uword)*/ upperByte) << 8))))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord(/*(volatile ubyte)*/ pCurrOp->parmLow, /*(volatile ubyte)*/ pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

	#define bytesToUWord(lowerByte, upperByte) (/*(uword)*/ (/*(ubyte)*/ (lowerByte & /*(ubyte)*/ 0xFF) | ((/*(uword)*/ upperByte) << 8)))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord(/*(volatile ubyte)*/ pCurrOp->parmLow, /*(volatile ubyte)*/ pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) (*(uword *) &pCurrOp->parmLow)

	typedef sbyte TSSmallValue;       //   8-bits
	typedef ubyte TUSmallValue;       //   8-bits
	typedef word  TLargeValue;        //  16-bits
	typedef uword TULargeValue;       //  16-bits
	typedef uword TTaskStackItem;			//  16-bits

#elif  defined(PIC24)

	//
	// Need to ensure that C30 PIC compiler doesn't do 'bytesToWord' in all 'sbyte' arithmetic. To do this, at least one of the
	// parameters must be cast as 'uword' because compiler only looks at size of expression factors and not size of result in
	// determining the precision of expression evaluation.
	//
	#define bytesToSWord(lowerByte, upperByte) ((word) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8))))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	#define bytesToUWord(lowerByte, upperByte) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8)))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	typedef sbyte TSSmallValue;       //   8-bits
	typedef ubyte TUSmallValue;       //   8-bits
	typedef word  TLargeValue;        //  16-bits
	typedef uword TULargeValue;       //  16-bits
	typedef uword TTaskStackItem;			//  16-bits

#else

	#error "Illegal Platform Type"

	// Possibly use "word" instead of use "uword"????
	#define bytesToSWord(lowerByte, upperByte)  ((word) ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte)))
	#define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	#define bytesToUWord(lowerByte, upperByte)  ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
	#define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
	#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

	typedef sbyte TSSmallValue;       //   8-bits
	typedef ubyte TUSmallValue;       //   8-bits
	typedef word  TLargeValue;        //  16-bits
	typedef uword TULargeValue;       //  16-bits
	typedef uword TTaskStackItem;			//  16-bits

#endif


//typedef TULargeValue TULargeValue;
typedef ubyte *pUbyte;
typedef uword *pUword;


enum TTypeOfSensorValueUpload
{
	sensorUploadSizeShort,
	sensorUploadSizeLong,
	sensorUploadSizeFloat
};


#ifdef __cplusplus
	}
#endif

#endif

