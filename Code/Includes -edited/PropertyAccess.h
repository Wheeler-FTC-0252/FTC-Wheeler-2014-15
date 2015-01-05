#if !defined(__PropertyAccess__H_)
#define __PropertyAccess__H_

#include "PropertyTypes.h"

extern TLargeValue getProperty(TUSmallValue nPropertyType, TULargeValue nPropertyIndex);
extern void setProperty(TUSmallValue nPropertyType, TUSmallValue nPropertyIndex, TLargeValue nNewValue);
extern void invalidSetPropertyValue(TUSmallValue nPropertyIndex);

#endif //#if !defined(__PropertyTypes__H_)
