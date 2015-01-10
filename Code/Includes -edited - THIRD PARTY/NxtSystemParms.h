////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																			NXT Specific System Parameters and System Functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(__NxtSystemParms__H_)
#define __NxtSystemParms__H_

#ifdef __cplusplus
	extern "C" {
#endif

#if defined(NXT) || defined(Simulator)

	extern ubyte getNxtNoPowerDownOnAC(void);
	extern bool getNxtRechargableState(void);
	extern ubyte getLowVoltageBatteryCountLimits(void);
	extern sword getBatteryLevelExternal(void);
	extern word getAverageBatteryVoltageExternal(void);
	extern word32 getExternalBatteryShutdown(void);


	extern ubyte getHS_Status(void);
	extern ubyte getHS_Mode(void);


#endif //#if defined(NXT) || defined(Simulation)

#ifdef __cplusplus
	};
#endif

#endif
