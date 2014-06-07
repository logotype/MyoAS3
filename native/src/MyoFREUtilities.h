#ifndef MyoNative_MyoFREUtilities_h
#define MyoNative_MyoFREUtilities_h

#ifdef MYONATIVE_OS_WINDOWS
    #include "FlashRuntimeExtensions.h"
#else
    #include <Adobe AIR/Adobe AIR.h>
#endif

#include <stdio.h>

unsigned int createUnsignedIntFromFREObject(FREObject freObject)
{
	unsigned int value;
	FREGetObjectAsUint32(freObject, &value);
	return value;
}

double createDoubleFromFREObject(FREObject freObject)
{
	double value;
	FREGetObjectAsDouble(freObject, &value);
	return value;
}

bool createBoolFromFREObject(FREObject freObject)
{
	unsigned int value;
	FREGetObjectAsBool(freObject, &value);
    return (value != 0);
}

FREObject createFREObjectForUTF8(const char* str)
{
	FREObject fre;
	FRENewObjectFromUTF8(strlen(str), (const uint8_t*) str, &fre);
	return fre;
}

FREObject createFREObjectForUnsignedInt(unsigned int i)
{
	FREObject fre;
	FRENewObjectFromUint32(i, &fre);
	return fre;
}

FREObject createFREObjectForDouble(double d)
{
	FREObject fre;
	FRENewObjectFromDouble(d, &fre);
	return fre;
}

FREObject createFREObjectForBool(bool b)
{
	FREObject fre;
	FRENewObjectFromBool((b) ? 1 : 0, &fre);
	return fre;
}

FREResult FRENewObjectFromUTF8Simple(const uint8_t*  value, FREObject* object){
	uint32_t length = strlen((const char*)value) + 1;
    
	return FRENewObjectFromUTF8(length, value, object);
}

void FREDebug(FREResult result, const char* note) {
    switch (result) {
        case FRE_OK:
            std::cout << "[NATIVE " << note << "] OK" << std::endl;
            break;
        case FRE_NO_SUCH_NAME:
            std::cout << "[NATIVE " << note << "] NO SUCH NAME" << std::endl;
            break;
        case FRE_INVALID_OBJECT:
            std::cout << "[NATIVE " << note << "] INVALID OBJECT" << std::endl;
            break;
        case FRE_TYPE_MISMATCH:
            std::cout << "[NATIVE " << note << "] TYPE MISMATCH" << std::endl;
            break;
        case FRE_ACTIONSCRIPT_ERROR:
            std::cout << "[NATIVE " << note << "] ACTIONSCRIPT ERROR" << std::endl;
            break;
        case FRE_INVALID_ARGUMENT:
            std::cout << "[NATIVE " << note << "] INVALID ARGUMENT" << std::endl;
            break;
        case FRE_READ_ONLY:
            std::cout << "[NATIVE " << note << "] READ ONLY" << std::endl;
            break;
        case FRE_WRONG_THREAD:
            std::cout << "[NATIVE " << note << "] WRONG THREAD" << std::endl;
            break;
        case FRE_ILLEGAL_STATE:
            std::cout << "[NATIVE " << note << "] ILLEGAL STATE" << std::endl;
            break;
        case FRE_INSUFFICIENT_MEMORY:
            std::cout << "[NATIVE " << note << "] INSUFFICIENT MEMORY" << std::endl;
            break;
        default:
            std::cout << "[NATIVE " << note << "] OTHER RESULT" << std::endl;
            break;
    }
}

#endif /* defined(__MyoNative__MyoFREUtilities__) */