package com.thalmiclabs.myo.events
{
	import com.thalmiclabs.myo.Myo;
	import com.thalmiclabs.myo.Quaternion;
	
	import flash.events.Event;

	/**
	 Represents the orientation of a Myo. The orientation is represented via a quaternion.
	 */
	public class OrientationEvent extends Event
	{
		/**
		 * Posted when a new orientation event is available from a Myo. Notifications are posted at a rate of 50 Hz.
		 */
		static public const ORIENTATION_EVENT:String = "MyoDidReceiveOrientationEventNotification";
		
		/**
		 The Myo whose orientation changed.
		 */
		public var myo:Myo;
		
		/**
		 Orientation representation as a normalized quaternion.
		 */
		public var quaternion:Quaternion;
		
		public function OrientationEvent(type:String, rotation:Quaternion)
		{
			this.quaternion = rotation;
			super(type, true, false);
		}
	}
}