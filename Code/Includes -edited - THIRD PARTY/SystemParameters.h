#ifndef SystemParameters__H_
#define SystemParameters__H_

#include "CompilerTypedefs.h"

#ifdef __cplusplus
	extern "C" {
#endif

extern   uword				nMaxOpcodesPerTimeSlice;

#if  defined(bHasFloatDuringInactivePWM)
	extern bool bFloatDuringInactiveMotorPWM;
#endif

#if defined(NXT) || defined(EV3)

	#if defined(NXT)

//efine NO_ERR                     0
//efine STAT_COMM_PENDING         32
//efine ERR_COMM_CHAN_NOT_READY  -32  // Already defined but valid here. Specified channel/connection not configured or busy.
//efine ERR_COMM_BUS_ERR         -35
//efine ERR_COMM_CHAN_INVALID		 -33

		typedef NXT_STATUS TI2CStatus;

		#define i2cStatusNoError           NO_ERR
		#define i2cStatusPending					 STAT_COMM_PENDING
		#define i2cStatusFailed						 ERR_COMM_BUS_ERR
		#define i2cStatusBadConfig				 ERR_COMM_CHAN_INVALID

		extern TI2CStatus cmdLSCheckStatus(const TULargeValue nSensorPort, TULargeValue *pNumbReadBytesAvail);

	#elif defined(EV3)

		typedef enum
		{
			i2cStatusNoError         =  0,
			i2cStatusPending,
			i2cStatusFailed,
			i2cStatusBadConfig,
			i2cStatusStartTransfer = 8,
		} TI2CStatus;

		int getLegoI2CBytesReady(const TULargeValue nSensorPort);
		extern TI2CStatus getLegoI2CStatus(const TULargeValue nSensorPort);

	#endif

	extern void clearLego2CBytesReady(const TULargeValue nSensorIndex);
#endif

#if defined(NXT) || defined(Simulator)

	extern ubyte               nVirtualMotorChanges;
	extern ubyte               nVirtualSensorTypeChanges;
	extern ubyte               nVirtualSensorModeChanges;
	extern sbyte               nNxtButtonTask;
	extern ubyte               nNxtExitClicks;

#endif //#if defined(NXT)

#if defined(VEX) || defined(VEX2) || defined(Simulator)
	extern volatile uword nIFISPIMsgCounts;
#endif

#if  defined(useFloats)
	extern bool bExceptionOnFloatConversionErrors;
#endif

#if !defined(bGetClearVariablesOnPgmStart)
	extern bool bGetClearVariablesOnPgmStart(void);
	extern void SetClearVariablesOnPgmStart(TUSmallValue newValue);
#endif

#define kShutdownVoltageDefault 6300

extern TLargeValue getSystemParmValue(TUSmallValue index);
extern void setSystemParmValue(enum TSystemParmTypes parmIndex, TULargeValue newValue);

#if defined(ARMCPU)
	extern TULargeValue getSystemExternAddress(TULargeValue index);
#elif defined(Simulator) // || defined(VEX)
	extern TULargeValue getSystemExternAddress(TULargeValue index);
#endif


#ifdef __cplusplus
	}
#endif

#endif //#ifndef SystemParameters__H_
