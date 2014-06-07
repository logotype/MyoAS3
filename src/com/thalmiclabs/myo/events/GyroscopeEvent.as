package com.thalmiclabs.myo.events
{
	import com.thalmiclabs.myo.Myo;
	import com.thalmiclabs.myo.Vector3;
	
	import flash.events.Event;

	/**
	 Represents the current gyroscope values reported by a Myo's gyroscope. Units are in rad/s.
	 */
	public class GyroscopeEvent extends Event
	{
		/**
		 * Posted when a new gyroscope event is available from a Myo. Notifications are posted at a rate of 50 Hz.
		 */
		static public const GYROSCOPE_EVENT:String = "MyoDidReceiveGyroscopeEventNotification";
		
		/**
		 The Myo associated with the gyroscope event.
		 */
		public var myo:Myo;
		
		/**
		 A vector representing the Myo's gyroscope values (in rad/s).
		 */
		public var vector:Vector3;
		
		public function GyroscopeEvent(type:String, gyro:Vector3)
		{
			this.vector = gyro;
			super(type, true, false);
		}
	}
}