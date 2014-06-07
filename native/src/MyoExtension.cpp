#include "MyoExtension.h"
#include "MyoDevice.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
extern "C" {
    
    FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE isSupported]" << std::endl;
		FREObject isSupported;
		FRENewObjectFromBool(1, &isSupported);
		return isSupported;
	}

    FREObject initialize(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE initialize]" << std::endl;
        FRESetContextActionScriptData(ctx, argv[0]);
        
        myonative::MyoDevice* device = new myonative::MyoDevice(ctx);
        FRESetContextNativeData(ctx, (void*) device);
                
        return NULL;
    }
    
    // Hub class start
    FREObject hubAddListener(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE hubAddListener]" << std::endl;
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        
        device->hub->addListener(device->listener);

        return NULL;
    }
    
    FREObject hubWaitForAnyMyo(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE hubWaitForAnyMyo]" << std::endl;
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        device->myo = device->hub->waitForAnyMyo(10000);
        
        // If waitForAnyMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
        if (!device->myo) {
            std::cout << "[NATIVE hubWaitForAnyMyo] Unable to find a Myo!" << std::endl;
            return NULL;
        }
                
        FREObject freMyo;
        FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Myo", 0, NULL, &freMyo, NULL);
        
        FREObject freMyoIsTrained;
        FRENewObjectFromBool(device->myo->isTrained(), &freMyoIsTrained);
        FRESetObjectProperty(freMyo, (const uint8_t*) "isTrained", freMyoIsTrained, NULL);
        
        FREObject freMyoMacAddress;
        FRENewObjectFromDouble(device->myo->macAddress(), &freMyoMacAddress);
        FRESetObjectProperty(freMyo, (const uint8_t*) "macAddress", freMyoMacAddress, NULL);
        
        FREObject freMyoMacAddressAsString;
        const uint8_t* macAddressString = reinterpret_cast<const uint8_t*>(&device->myo->macAddressAsString()[0]);
        uint32_t macAddressStringLength = strlen((const char*)macAddressString) + 1;
        FRENewObjectFromUTF8(macAddressStringLength, macAddressString, &freMyoMacAddressAsString);
        FRESetObjectProperty(freMyo, (const uint8_t*) "macAddressAsString", freMyoMacAddressAsString, NULL);
        
        // We've found a Myo, let's output its MAC address.
        std::cout << std::endl << "[NATIVE hubWaitForAnyMyo]: Connected to " << device->myo->macAddressAsString() << "." << std::endl;
        
        return freMyo;
    }
    
    FREObject hubRun(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE hubRun]" << std::endl;
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        
        int durationMilliseconds;
        FREGetObjectAsInt32(argv[0], &durationMilliseconds);
        
        // Adding native listener
        device->hub->run(durationMilliseconds);
        
        return NULL;
    }
    // Hub class end

    // Myo class start
    FREObject myoRequestRSSI(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE myoRequestRSSI]" << std::endl;
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        
        device->myo->requestRssi();
        
        return NULL;
    }

    FREObject myoVibrate(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
        std::cout << "[NATIVE myoVibrate]" << std::endl;
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        
        int vibrationType;
        FREGetObjectAsInt32(argv[0], &vibrationType);
        myo::Myo::VibrationType vibrationEnum = static_cast<myo::Myo::VibrationType>(vibrationType);
        
        device->myo->vibrate(vibrationEnum);
        
        return NULL;
    }
    // Myo class end

    FRENamedFunction _Shared_methods[] = {
        { (const uint8_t*) "isSupported", 0, isSupported }
	};
    
	FRENamedFunction _Instance_methods[] = {
  		{ (const uint8_t*) "initialize", 0, initialize },
  		{ (const uint8_t*) "waitForAnyMyo", 0, hubWaitForAnyMyo },
  		{ (const uint8_t*) "addListener", 0, hubAddListener },
  		{ (const uint8_t*) "run", 0, hubRun },
  		{ (const uint8_t*) "requestRSSI", 0, myoRequestRSSI },
  		{ (const uint8_t*) "vibrate", 0, myoVibrate }
	};
    
    void initializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {

        if ( 0 == strcmp( (const char*) ctxType, "shared" ) )
		{
			*numFunctions = sizeof( _Shared_methods ) / sizeof( FRENamedFunction );
			*functions = _Shared_methods;
		}
		else
        {
            *numFunctions = sizeof( _Instance_methods ) / sizeof( FRENamedFunction );
            *functions = _Instance_methods;
        }
	}
    
	void finalizer(FREContext ctx) {
        myonative::MyoDevice* device;
        FREGetContextNativeData(ctx, (void **) &device);
        if(device != NULL) {
            delete device;
        }
		return;
	}
    
	void MyoNativeInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
		*ctxInitializer = &initializer;
		*ctxFinalizer = &finalizer;
	}
    
	void MyoNativeFinalizer(void* extData) {
		return;
	}
}