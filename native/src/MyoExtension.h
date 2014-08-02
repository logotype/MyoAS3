#ifndef __MyoNative__MyoExtension__
#define __MyoNative__MyoExtension__

#ifdef MYONATIVE_OS_WINDOWS
#ifdef MYONATIVE_EXPORTS
#define MYONATIVE_API __declspec(dllexport)
#else
#define MYONATIVE_API __declspec(dllimport)
#endif
#include "FlashRuntimeExtensions.h"
#else
#define MYONATIVE_API __attribute__((visibility("default")))
#include <Adobe AIR/Adobe AIR.h>
#endif

extern "C" {
    // shared methods
    FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    
    // instance methods
    FREObject initialize(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    FREObject hubWaitForMyo(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    FREObject hubAddListener(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    FREObject hubRun(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    FREObject myoRequestRSSI(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    FREObject myoVibrate(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
    
    // initializer / finalizer
    void initializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions);
    void finalizer(FREContext ctx);
    
    MYONATIVE_API void MyoNativeInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
    MYONATIVE_API void MyoNativeFinalizer(void* extData);
}

#endif /* defined(__MyoNative__MyoExtension__) */
