#if !defined(__PPgmgByte__H_)
#define __PPgmgByte__H_

#include "CompilerTypedefs.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																	Flash Memory Typedef Declarations for Harvard Architecture
//
// This header file contains the CPU / platform specific declarations for suppoirting variables located in flash memory.
// Separate platform specific declarations are required because standard C language does not provide native support for Harvard
// architectures that use separate address/data buses for accessing RAM and Flash memory. There are toolchain specific language
// extensions for extending C language to provide this support.
//
// ROBOTC firmware uses multiple tool chains to build the VM firmware that is loaded into the different robot controllers. Each
// different "class" of robot controller uses a different tool chain. Tool chains currently in use include:
//
//		Tool Chain:												CPU Types Supported:										Robot Controllers:
//    ===========												====================										==================
//    IAR Embedded Workshop							ARM, Cortex, STM8, STM32 (Cortex)				VEX Cortex, LEGO NXT, .Netduino
//    Microchip MPLAB/C18								PIC18xxxx CPUs from Microchip						VEX PIC
//    GCC																Atmel AVR / AtMegaXXX CPUs							Arduino, ...
//    Renesas														Renesas H8															LEGO RCX (obsolete)
//
// Each of these tool chains has a different way of declaraing variables that reside in flash memory. Especially for the CPUs
// that support a Harvard architecture with separate address/data buses for RAM and Flash Variables (i.e. Microchip PIC18 and
// Atmel AVR CPUs). The standard C language does not support differentiating variables that are in RAM address space vs those
// that are in Flash address space. Standard C language only supports single declaration type ("const") for non-changing variables
// and assumes they all reside in the same address space!
//
// NOTE: Some CPU architectures internally support a Harvard architecture but present a single common address space at the
// instruction "address" level so that the internal structure of separate address/data buses is hidden from user code. CPUs in
// this class include:
//       ARM / Cortex CPUs
//       STM8 CPU
//       Microchip PIC24 CPUs (partial)
//       ....
//
// The implications of Harvard architecture support extend beyond the simple declarations of this header file. The C language
// only has a single type of 'pointer' variable. When a pointer variable is passed as a function parameter the function has
// no knowledge of whether this is an address in RAM address space or Flash address space. The support for this type of operation
// among the different tool chains ranges from:
//     1. None. You should only use RAM pointers.
//     2. Tool chain always locates all variables in RAM regardless of the fact that it is 'const' variable. The C initialization
//        routines will copy initialization values from Flash to RAM. This is wasteful of RAM and not practical in the small
//        8-bit controllers where there is only limited RAM (e.g. 2K bytes or less) as a lot of it can be eaten up with 'const'
//        variables. This is the "default" solution for all tool chains.
//     3. Compiler will at least generate an error or warning message if you mix pointer types in a function call (i.e. passing
//        a Flash pointer variable to a function that expects a RAM pointer).
//     4. Tool chain may have two different variants of some library functions that use memory pointers as function parameters.
//        For example, (1) "memcpy" from a RAM pointer and (2) "memcpyFromFlash" from a Flash pointer. Only a few functions are
//        typically declared this way; something like "sprintf" is not where the list of variable arguments to 'sprintf' are
//        always expected to be from RAM.
//
// The ROBOTC VM deals with this problem as follows:
//     1. All variables in the ROBOTC VM are located in RAM.
//     2. ROBOTC compiler allows variables to be 'const' declared. These variables are located in a "constant pool" that is part of
//        the ROBOTC object file format. When a user program is first started, part of the VM initialization sequence is to
//        copy data from the constant pool to ROBOTC VM RAM variables.
//     3. ROBOTC does not support 'constant pool' in object file for smaller 8-bit platforms with limited RAM. In this case, the
//        constant values are stored as constants within ROBOTC VM opcodes. THe object file constant pool is only necessary for platforms
//        that support string variables and string (char array) constants.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(Simulator) || defined(_WINDOWS)

	typedef romtype signed char TRomByte;
	typedef romtype unsigned char TRomUByte;

#elif defined(PIC24)

	typedef const signed char TRomByte;
	typedef const unsigned char TRomUByte;

#elif defined(AVRCPU)

	//__attribute__((progmem)) typedef const signed char TRomByte;
	//__attribute__((progmem)) typedef const unsigned char TRomUByte;

	#include <avr/pgmspace.h>
	#define TRomByte prog_char
	#define TRomUByte prog_uchar

	//#define pTRomByte TRomByte *
	//#define pTRomUByte TRomUByte *

#else

	typedef const romtype signed char TRomByte;
	typedef const romtype unsigned char TRomUByte;

#endif

typedef TRomByte * pTRomByte;
typedef TRomUByte * pTRomUByte;

#if !defined(ROBOTC)
	#if defined(VEX)
		typedef TRomByte near * pPrgmByte;
		typedef TRomUByte near * pUPrgmByte;
	#else
		typedef TRomByte *pPrgmByte;
		typedef TRomUByte *pUPrgmByte;
	#endif
#endif

//
// Depending on maximum amount of flash in a hardware platform, either a 16-bit or 32-bit variable is needed to represent
// a flash memory address. Following conditional compile declarations handle this appropriately.

#if defined(ARMCPU) || defined(PIC32) || defined(_WINDOWS)

	typedef unsigned long TIntFlashPtr;
	typedef unsigned long TIntRamPtr;
	#define convertPtrToTIntFlashPtr(pPtr) ((TIntFlashPtr) pPtr)

#elif defined(AVRCPU) || defined(Generic)

	#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega32U4__)
		typedef uword TIntFlashPtr;
	#else
		typedef uword32 TIntFlashPtr;
	#endif
		typedef uword		TIntRamPtr;
	#define convertPtrToTIntFlashPtr(pPtr) ((TIntFlashPtr) (uword) (void *) pPtr)
	// NOTE: At first glance above will not work if flash size is >64K bytes because of the 'uword' qualifier. But
	//       the function is only used for references in the main VM firmware which currently is <64K. The address
	//       space above 64K is used by the flash file system and access to these bytes does not use 'convertPtrToTIntFlashPtr'!
	//#define convertPtrToTIntFlashPtr(pPtr) ((TIntFlashPtr) (void *) pPtr)

#elif defined(VEX) || defined(STM8CPU)

	typedef uword		TIntFlashPtr;
	typedef uword		TIntRamPtr;
	#define convertPtrToTIntFlashPtr(pPtr) ((TIntFlashPtr) pPtr)

#else
	#error "Invalid platform type for accessing flash memory"
#endif


#endif

