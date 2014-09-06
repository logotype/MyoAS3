#include "MyoDeviceListener.h"
#include "MyoFREUtilities.h"
#include "FREHelpers.h"

namespace myonative {
    
    MyoDeviceListener::MyoDeviceListener(FREContext ctx) {
        m_ctx = ctx;
    }
    
    MyoDeviceListener::~MyoDeviceListener() {
        m_ctx = NULL;
    }
    
    void MyoDeviceListener::onPair(myo::Myo* myo, uint64_t timestamp) {
        
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onPair] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject data[] = {freMyo};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onPair", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onPair");
    }
    
    void MyoDeviceListener::onUnpair(myo::Myo* myo, uint64_t timestamp) {
        
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onUnpair] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject data[] = {freMyo};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onUnpair", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onUnpair");
    }
    
    void MyoDeviceListener::onConnect(myo::Myo* myo, uint64_t timestamp) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onConnect] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject data[] = {freMyo};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onConnect", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onConnect");
    }
    
    void MyoDeviceListener::onDisconnect(myo::Myo* myo, uint64_t timestamp) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onDisconnect] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject data[] = {freMyo};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onDisconnect", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onDisconnect");
    }
    
    void MyoDeviceListener::onArmRecognized(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onArmRecognized] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject freArm;
        FRENewObjectFromInt32(arm, &freArm);
        
        FREObject freDirection;
        FRENewObjectFromInt32(xDirection, &freDirection);
        
        FREObject data[] = {freMyo, freArm, freDirection};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onArmRecognized", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onArmRecognized");
    }
    
    void MyoDeviceListener::onArmLost(myo::Myo* myo, uint64_t timestamp) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onArmLost] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject data[] = {freMyo};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onArmLost", 1, data, &resultValue, NULL);
        
        FREDebug(result, "onArmLost");
    }
    
    void MyoDeviceListener::onPose(myo::Myo* myo, uint64_t timestamp, Pose pose) {
        
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onPose] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject frePose;
        FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Pose", 0, NULL, &frePose, NULL);
        
        FREObject frePoseType;
        FRENewObjectFromInt32(pose.type(), &frePoseType);
        FRESetObjectProperty(frePose, (const uint8_t*) "type", frePoseType, NULL);
        
        FREObject data[] = {freMyo, frePose};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onPose", 2, data, &resultValue, NULL);
        
        FREDebug(result, "onPose");
    }
    
    void MyoDeviceListener::onOrientationData(myo::Myo* myo, uint64_t timestamp, const Quaternion<float>& rotation) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onOrientationData] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject freQuaternion;
        FREObject freQX;
        FREObject freQY;
        FREObject freQZ;
        FREObject freQW;
        FRENewObjectFromDouble(rotation.x(), &freQX);
        FRENewObjectFromDouble(rotation.y(), &freQY);
        FRENewObjectFromDouble(rotation.z(), &freQZ);
        FRENewObjectFromDouble(rotation.w(), &freQW);
        FREObject params[] = {freQX, freQY, freQZ, freQW};
        result = FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Quaternion", 4, params, &freQuaternion, NULL);
        
        FREObject data[] = {freMyo, freQuaternion};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onOrientationData", 2, data, &resultValue, NULL);
        
        FREDebug(result, "onOrientationData");
    }
    
    void MyoDeviceListener::onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const Vector3<float>& accel) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onAccelerometerData] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject freVector3;
        FREObject freX, freY, freZ;
        FRENewObjectFromDouble(accel.x(), &freX);
        FRENewObjectFromDouble(accel.y(), &freY);
        FRENewObjectFromDouble(accel.z(), &freZ);
        FREObject params[] = {freX, freY, freZ};
        FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Vector3", 3, params, &freVector3, NULL);
        
        FREObject data[] = {freMyo, freVector3};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onAccelerometerData", 2, data, &resultValue, NULL);
        
        FREDebug(result, "onAccelerometerData");
    }
    
    void MyoDeviceListener::onGyroscopeData(myo::Myo* myo, uint64_t timestamp, const Vector3<float>& gyro) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onGyroscopeData] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject freVector3;
        FREObject freX, freY, freZ;
        FRENewObjectFromDouble(gyro.x(), &freX);
        FRENewObjectFromDouble(gyro.y(), &freY);
        FRENewObjectFromDouble(gyro.z(), &freZ);
        FREObject params[] = {freX, freY, freZ};
        FRENewObject( (const uint8_t*) "com.thalmiclabs.myo.Vector3", 3, params, &freVector3, NULL);
        
        FREObject data[] = {freMyo, freVector3};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onGyroscopeData", 2, data, &resultValue, NULL);
        
        FREDebug(result, "onGyroscopeData");
    }
    
    void MyoDeviceListener::onRssi(myo::Myo* myo, uint64_t timestamp, int8_t rssi) {
        FREObjectType type;
        FREObject actionScriptDataObject;
        if (!(FREGetContextActionScriptData(m_ctx, &actionScriptDataObject) == FRE_OK && FREGetObjectType(actionScriptDataObject, &type) == FRE_OK && type == FRE_TYPE_OBJECT)) {
            std::cout << "[NATIVE MyoDeviceListener::onRssi] Could not find the ActionScriptData object" << std::endl;
        }
        
        FREResult result;
        FREObject resultValue;
        
        FREObject freHub = getProperty(getExchangeObject(m_ctx), "hub");
        FREObject freMyos = getProperty(freHub, "_myos");
        FREObject freMyo = getElement(freMyos, 0);
        
        FREObject freListeners = getProperty(freHub, "_listeners");
        FREObject freListener = getElement(freListeners, 0);
        
        FREObject freRSSI;
        FRENewObjectFromInt32(rssi, &freRSSI);
        
        FREObject data[] = {freMyo, freRSSI};
        result = FRECallObjectMethod(freListener, (const uint8_t*)"onRssi", 2, data, &resultValue, NULL);
        
        FREDebug(result, "onRssi");
    }
}