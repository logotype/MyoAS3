#ifndef __MyoNative__FREHelpers__
#define __MyoNative__FREHelpers__

#include <iostream>

#ifdef MYONATIVE_OS_WINDOWS
    #include "FlashRuntimeExtensions.h"
#else
    #include <Adobe AIR/Adobe AIR.h>
#endif

extern "C" {
    void reg(FRENamedFunction *store, int slot, const char *name, FREFunction fn);
    void setNumberProperty(FREObject obj, const char *name, double value);
    void setIntProperty(FREObject obj, const char *name, int value);
    void setIntElement(FREObject obj, int index, int value);
    FREObject getExchangeObject(FREContext ctx);
    void setProperty(FREObject obj, const char *name, FREObject val);
    FREObject getProperty(FREObject obj, const char *name);
    FREObject getElement(FREObject obj, int idx);
}

#endif /* defined(__MyoNative__FREHelpers__) */
