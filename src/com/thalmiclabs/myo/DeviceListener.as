package com.thalmiclabs.myo
{
	/**
	 * A DeviceListener receives events about a Myo.
	 *
	 * @author logotype
	 *
	 */
	public interface DeviceListener
	{
		/**
		 * Called when a Myo has been paired.
		 */
		function onPair( myo:Myo ):void;
		
		/**
		 * Called when a paired Myo has been connected.
		 */
		function onConnect( myo:Myo ):void;
		
		/**
		 * Called when a paired Myo has been disconnected.
		 */
		function onDisconnect( myo:Myo ):void;
		
		/**
		 * Called when a paired Myo has provided a new pose.
		 */
		function onPose( myo:Myo, pose:Pose ):void;
		
		/**
		 * Called when a paired Myo has provided new orientation data.
		 */
		function onOrientationData( myo:Myo, rotation:Quaternion ):void;
		
		/**
		 * Called when a paired Myo has provided new accelerometer data in units of g.
		 */
		function onAccelerometerData( myo:Myo, accel:Vector3 ):void;
		
		/**
		 * Called when a paired Myo has provided new gyroscope data in units of deg/s.
		 */
		function onGyroscopeData( myo:Myo, gyro:Vector3 ):void;
		
		/**
		 * Called when a paired Myo has provided a new RSSI value.
		 */
		function onRssi( myo:Myo, rssi:int ):void;
	}
}
