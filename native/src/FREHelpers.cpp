#include "FREHelpers.h"

extern "C" {
    
    void reg(FRENamedFunction *store, int slot, const char *name, FREFunction fn) {
        store[slot].name = (const uint8_t*)name;
        store[slot].functionData = 0;
        store[slot].function = fn;
    }
    
    void setNumberProperty(FREObject obj, const char *name, double value) {
        FREObject temp, exception;
        FRENewObjectFromDouble(value,  &temp);
        FRESetObjectProperty(obj, (const uint8_t *)name, temp, &exception);
    }
    
    void setIntProperty(FREObject obj, const char *name, int value) {
        FREObject temp, exception;
        FRENewObjectFromInt32(value, &temp);
        FRESetObjectProperty(obj, (const uint8_t *)name, temp, &exception);
    }
    
    void setIntElement(FREObject obj, int index, int value) {
        FREObject temp;
        FRENewObjectFromInt32(value, &temp);
        FRESetArrayElementAt(obj,index, temp);
    }
    
    FREObject getExchangeObject(FREContext ctx) {
        FREObject buffer;
        FREGetContextActionScriptData(ctx, &buffer);
        return buffer;
    }
    
    void setProperty(FREObject obj, const char *name, FREObject val) {
        FREObject ignored;
        FRESetObjectProperty(obj,(const uint8_t *)name, val, &ignored);
    }
    
    FREObject getProperty(FREObject obj, const char *name) {
        FREObject rval, exception;
        FREGetObjectProperty(obj, (const uint8_t *)name, &rval, &exception);
        return rval;
    }
    
    FREObject getElement(FREObject obj, int idx) {
        FREObject rval;
        FREGetArrayElementAt(obj,idx, &rval);
        return rval;
    }
}