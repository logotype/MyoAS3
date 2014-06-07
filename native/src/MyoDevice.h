#ifndef __MyoNative__MyoDevice__
#define __MyoNative__MyoDevice__

#include <iostream>

#ifdef MYONATIVE_OS_WINDOWS
#include "FlashRuntimeExtensions.h"
#else
#include <Adobe AIR/Adobe AIR.h>
#endif

#include <myo/myo.hpp>
#include "MyoDeviceListener.h"

using namespace myo;

namespace myonative {
    class MyoDevice {
    public:
        MyoDevice(FREContext ctx);
        ~MyoDevice();
        
        Hub*     hub;
        Myo*     myo;
        MyoDeviceListener* listener;
        
    private:
        FREContext m_ctx;
        FREObject createVector3(double x, double y, double z);
    };
}

#endif /* defined(__MyoNative__MyoDevice__) */
