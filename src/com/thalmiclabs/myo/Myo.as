package com.thalmiclabs.myo
{
	import com.thalmiclabs.myo.namespaces.thalmiclabs;
	
	import flash.events.EventDispatcher;
	import flash.external.ExtensionContext;

	/**
	 * Represents a Myo.
	 * 
	 * Do not subclass. Do not maintain strong references to instances of this class,
	 * as this can cause unexpected behaviour. Hub will keep track of Myos.
	 */
	public class Myo extends EventDispatcher
	{
		/**
		 * An enum representing the different types of vibrations a Myo can make. 
		 */		

		/**
		 * A vibration lasting a small amount of time (VibrationLengthShort)
		 */
		static public const VIBRATION_SHORT:int = 0;
		
		/**
		 * A vibration lasting a moderate amount of time (VibrationLengthMedium)
		 */
		static public const VIBRATION_MEDIUM:int = 1;
		
		/**
		 * A vibration lasting a long amount of time (VibrationLengthLong)
		 */
		static public const VIBRATION_LONG:int = 2;

		/**
		 * @private
		 * The Listener subclass instance.
		 */
		thalmiclabs var listener:DeviceListener;
		
		/**
		 * The name of the Myo. 
		 */
		public var name:String;
		
		/**
		 * The MAC address associated with this device. 
		 */		
		public var macAddress:int;
		
		/**
		 * The MAC address associated with this device as a formatted hex string. 
		 */		
		public var macAddressAsString:String;
		
		/**
		 * Returns true if and only if this Myo is trained and will generate pose events. 
		 */		
		public var isTrained:Boolean;
		
		/**
		 * @private
		 * Native Extension context object.
		 *
		 */
		public var context:ExtensionContext;
		
		public function Myo()
		{
		}
		
		/**
		 * Request the RSSI of the Myo.
		 * 
		 * <p>An onRssi event will likely be generated with the value of the RSSI.</p>
		 * 
		 */
		public function requestRssi():void
		{
			//call context	
		}
		
		/**
		 * Engage the Myo's built in vibration motor. 
		 * @param length
		 * 
		 */
		public function vibrate( length:int ):void
		{
			switch( length )
			{
				case VIBRATION_SHORT:
					//call context
					break;
				case VIBRATION_MEDIUM:
					//call context
					break;
				case VIBRATION_LONG:
					//call context
					break;
				default:
					throw new Error( "Valid values are: Myo.VIBRATION_SHORT, Myo.VIBRATION_MEDIUM, Myo.VIBRATION_LONG" );
					break;
			}
		}
	}
}