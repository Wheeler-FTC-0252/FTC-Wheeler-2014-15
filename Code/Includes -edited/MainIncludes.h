#ifndef MainIncludes__H_
#define MainIncludes__H_

#ifdef __cplusplus
	//#include "ForceWindowsLibraryOrder.h"
	extern "C" {
#endif

#include "LoadBuildOptions.h"
#include "CompilerTypedefs.h"
#include "OpcodeDefinitions.h"
#include "vmtypedefs.h"

#if defined(NXT)
	#include <Includes/NXTFileIODefs.h>
#endif

#if defined(hasStringSupport)

	#include "GraphicLCD.h"
	#include "stringOpcodes.h"

#elif defined(bHasLCDGraphicsDisplay) || defined(hasDebugStreamSupport)

	#include <Includes/GraphicLCD.h>

#endif

#ifdef __cplusplus
	};
#endif

#endif //#ifndef MainIncludes__H_
