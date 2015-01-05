#pragma once 



typedef enum TX3BridgeFunctions
{
	x3BridgeVM_Startup,
	x3BridgeVM_StartUserProgram,
	x3BridgeVM_SetSuspendOnStartProgram,
	x3BridgeVM_Timeslice,
	x3BridgeVM_Background,
	x3BridgeVM_Message,
} TX3BridgeFunctions;

typedef enum TEV3SharedObjectIndex
{
	soNotLoaded					= -1,
	soForROBOTC					= 0,
	soForLabVIEW				= 1,
} TEV3SharedObjectIndex;
