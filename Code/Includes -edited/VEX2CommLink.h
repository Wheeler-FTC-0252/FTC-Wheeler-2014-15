#ifndef VEX2CommLink__H_
#define VEX2CommLink__H_

#include "ProgramType.h"

#ifdef __cplusplus
extern "C" {
#endif

extern       TProgramType 							nCurrCortexProgramType;

#define getCurrCortexProgramType() 			nCurrCortexProgramType

extern void SetNextCortexProgramType(TProgramType nNewType);
extern TProgramType getNextCortexProgramType(void);


#ifdef __cplusplus
};
#endif

#endif