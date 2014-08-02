#ifndef __MyoNative__MyoDeviceListener__
#define __MyoNative__MyoDeviceListener__

#include <iostream>

#ifdef MYONATIVE_OS_WINDOWS
#include "FlashRuntimeExtensions.h"
#else
#include <Adobe AIR/Adobe AIR.h>
#endif

#include <myo/myo.hpp>

using namespace myo;

namespace myonative {
    class MyoDeviceListener : public myo::DeviceListener {
    public:
        
        MyoDeviceListener(FREContext ctx);
        ~MyoDeviceListener();
        
        /// Called when a Myo has been paired.
        virtual void onPair(Myo* myo, uint64_t timestamp);
        
        /// Called when a paired Myo has been connected.
        virtual void onConnect(Myo* myo, uint64_t timestamp);
        
        /// Called when a paired Myo has been disconnected.
        virtual void onDisconnect(Myo* myo, uint64_t timestamp);
        
        /// Called when a paired Myo recognizes that it is on an arm.
        virtual void onArmRecognized(Myo* myo, uint64_t timestamp, Arm arm, XDirection xDirection);
        
        /// Called when a paired Myo is moved or removed from the arm.
        virtual void onArmLost(Myo* myo, uint64_t timestamp);
        
        /// Called when a paired Myo has provided a new pose.
        virtual void onPose(Myo* myo, uint64_t timestamp, Pose pose);
        
        /// Called when a paired Myo has provided new orientation data.
        virtual void onOrientationData(Myo* myo, uint64_t timestamp, const Quaternion<float>& rotation);
        
        /// Called when a paired Myo has provided new accelerometer data in units of g.
        virtual void onAccelerometerData(Myo* myo, uint64_t timestamp, const Vector3<float>& accel);
        
        /// Called when a paired Myo has provided new gyroscope data in units of deg/s.
        virtual void onGyroscopeData(Myo* myo, uint64_t timestamp, const Vector3<float>& gyro);
        
        /// Called when a paired Myo has provided a new RSSI value.
        /// @see Myo::requestRssi() to request an RSSI value from the Myo.
        virtual void onRssi(Myo* myo, uint64_t timestamp, int8_t rssi);
        
    private:
        
        FREContext m_ctx;
    };
}

#endif /* defined(__MyoNative__MyoDeviceListener__) */
