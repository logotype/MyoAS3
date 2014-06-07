#include "MyoDevice.h"
#include <map>

#ifdef WIN32
#ifndef NAN
static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
#define NAN (*(const float *) __nan)
#endif
#endif

namespace myonative {
    MyoDevice::MyoDevice(FREContext ctx) {
        std::cout << "[NATIVE CONSTRUCTOR MyoDevice::MyoDevice]" << std::endl;
        m_ctx = ctx;
        
        hub = new myo::Hub();
        listener = new MyoDeviceListener(m_ctx);
    }
    
    MyoDevice::~MyoDevice() {
        std::cout << "[NATIVE DESTRUCTOR MyoDevice::~MyoDevice]" << std::endl;
        hub->removeListener(static_cast<DeviceListener*>(listener));
        delete listener;
        listener = NULL;
        myo = NULL;
        delete hub;
        hub = NULL;
    }
    
    FREObject MyoDevice::createVector3(double x, double y, double z) {
        FREObject obj;
        FREObject freX, freY, freZ;
        FRENewObjectFromDouble(x, &freX);
        FRENewObjectFromDouble(y, &freY);
        FRENewObjectFromDouble(z, &freZ);
        FREObject params[] = {freX, freY, freZ};
        FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Vector3", 3, params, &obj, NULL);
        return obj;
    }
}