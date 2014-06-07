package com.thalmiclabs.myo.events
{
	import com.thalmiclabs.myo.Pose;
	
	import flash.events.Event;

	public class DeviceEvent extends Event
	{
		/**
		 * Posted whenever a Myo has been paired.
		 */
		static public const PAIR_DEVICE:String = "HubDidPairDeviceNotification";
		
		/**
		 * Posted whenever a Myo connects.
		 */
		static public const CONNECT_DEVICE:String = "HubDidConnectDeviceNotification";
		
		/**
		 * Posted whenever a Myo disconnects.
		 */
		static public const DISCONNECT_DEVICE:String = "HubDidDisconnectDeviceNotification";
		
		/**
		 * Posted when a new pose is available from a Myo.
		 */
		static public const POSE_EVENT:String = "MyoDidReceivePoseChangedNotification";
		
		/**
		 * Called when a paired Myo has provided a new RSSI value. 
		 */
		static public const RSSI_EVENT:String = "MyoRSSINotification";
		
		/**
		 * When a paired Myo has provided a new RSSI value. 
		 */
		public var rssi:int;

		public function DeviceEvent(type:String, rssi:int = 0, pose:Pose = null)
		{
			this.rssi = rssi;
			super(type, true, false);
		}
	}
}