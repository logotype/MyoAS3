package com.thalmiclabs.myo.events
{
	import com.thalmiclabs.myo.Myo;
	import com.thalmiclabs.myo.Vector3;
	
	import flash.events.Event;

	/**
	 Represents the current accelerometer values reported by a Myo's accelerometer. Units are in Gs.
	 */
	public class AccelerometerEvent extends Event
	{
		/**
		 * Posted when a new accelerometer event is available from a Myo. Notifications are posted at a rate of 50 Hz.
		 */
		static public const ACCELEROMETER_EVENT:String = "MyoDidReceiveAccelerometerEventNotification";
		
		/**
		 The Myo associated with the acceleration event.
		 */
		public var myo:Myo;
		
		/**
		 A vector representing the Myo's acceleration (in Gs).
		 */
		public var vector:Vector3;
		
		public function AccelerometerEvent(type:String, accel:Vector3)
		{
			this.vector = accel;
			super(type, true, false);
		}
	}
}