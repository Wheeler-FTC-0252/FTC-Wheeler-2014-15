#if !defined(_FlashFileSystemOffsets__H_)
#define _FlashFileSystemOffsets__H_

#include "MainIncludes.h"
#include "TMotorTypes.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Byte Offsets for Persistent Variables Stored  at Start of File System Flash Memory
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#if !(kVTOCItemSize > 0) && !defined(_WINDOWS) && !(defined(NXT) || defined(EV3))
	#error "Include file screwup. 'LoadBuildOptions.h' must be included before 'FlashFileSystemOffsets.h'"
#endif

#if (kVTOCItemSize > 0) || defined(_WINDOWS)

#include "stddef.h"

typedef struct
{
	unsigned long nCPUSpeed;
	unsigned short nMicroSecPerInterruptTimes10;
	unsigned char nStartupProgram;
	unsigned char nIdleProgram;
	unsigned char nCortexCommType;									// For VEX Cortex "Master Communications type"
#if (kStoreRobotNameInPersistentData != 0) || defined(_WINDOWS)
	#define kSizeOfRobotName 8
	unsigned char cRobotName[kSizeOfRobotName];			// Robot Name or Team Number (VEX Cortex)
#endif
#if bStoreStartupUARTTypesInPersistentData() || defined(_WINDOWS)
	unsigned char nStartupUARTType[kNumbOfSerialPortsForArrays];
#endif
#if (kSizeOfDefaultPidSettingsTable > 0) || defined(_WINDOWS)
	TPidDataPersistentDefaultSetting nDefaultPidSettings[kSizeOfDefaultPidSettingsTable];
#endif
	unsigned long  nVTOCStart;											// Start of the VTOC array. Each entry contains information on one file.
} TFlashFilePersistentVariables;

typedef enum
{
	kOffsetCPUSpeed											= offsetof(TFlashFilePersistentVariables, nCPUSpeed),
	kOffsetMicroSecPerInterruptTimes10	= offsetof(TFlashFilePersistentVariables, nMicroSecPerInterruptTimes10),
	kOffsetStartupProgram								= offsetof(TFlashFilePersistentVariables, nStartupProgram),
	kOffsetIdleProgram									= offsetof(TFlashFilePersistentVariables, nIdleProgram),
	kOffsetProgramCommType							= offsetof(TFlashFilePersistentVariables, nCortexCommType),
#if (kStoreRobotNameInPersistentData != 0) || defined(_WINDOWS)
	kOffsetRobotName										= offsetof(TFlashFilePersistentVariables, cRobotName),
#endif
#if bStoreStartupUARTTypesInPersistentData() || defined(_WINDOWS)
	kOffsetStartupUARTTypes							= offsetof(TFlashFilePersistentVariables, nStartupUARTType),
#endif
#if (bSmartMotorsWithEncoders() != 0) || defined(_WINDOWS)
	kOffsetDefaultPidSettingsXX					= offsetof(TFlashFilePersistentVariables, nDefaultPidSettings),
#endif

	// NOTE: Must be aligned on a 32-bit boundary!!!
	kOffsetVTOCStartXX									= ((offsetof(TFlashFilePersistentVariables, nVTOCStart) + 3) / 4) * 4			// Must by 4-byte aligned. Start of the VTOC array. Each entry contains information on one file.
} TFlashFilePersistentOffsets;

#endif //#if (kVTOCItemSize > 0) || defined(_WINDOWS)

#endif //if !defined(_FlashFileSystemOffsets__H_)
