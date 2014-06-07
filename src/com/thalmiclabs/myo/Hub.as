package com.thalmiclabs.myo
{
	import com.thalmiclabs.myo.native.MyoNative;
	import flash.external.ExtensionContext;

	/**
	 * The Hub singleton manages Myos. 
	 */
	public class Hub
	{
		/**
		 * A snapshot of the list of Myos currently connected to Hub. 
		 */
		public var _myos:Vector.<Myo> = new Vector.<Myo>();
		
		/**
		 * A snapshot of the list of listeners to the Hub. 
		 */
		public var _listeners:Vector.<DeviceListener> = new Vector.<DeviceListener>();
		
		/**
		 * @private
		 * Native connection object.
		 *
		 */
		public var connection:MyoNative;
		
		/**
		 * @private
		 * Native Extension context object.
		 *
		 */
		public var context:ExtensionContext;

		/**
		 * Construct a hub.
		 * 
		 * <p>It is not safe to concurrently construct two Hub instances on two different threads.
		 * Throws an exception if another Hub instance exists.</p>
		 */		
		public function Hub()
		{
			connection = new MyoNative( this );
		}

		/**
		 * Find a nearby Myo and pair with it, or time out after timeoutMilliseconds milliseconds if provided.
		 * 
		 * <p>If timeout_ms is zero, this function blocks until a Myo is found. This function must
		 * not be run concurrently with run() or runOnce().</p> 
		 */		
		public function waitForAnyMyo( timeoutMilliseconds:int = 0 ):Myo
		{
			var myo:Myo = Myo( context.call( "waitForAnyMyo", timeoutMilliseconds ) );
			if( myo )
			{
				myo.context = context;
				_myos.push( myo as Myo );
				return myo;
			}
			
			return null;
		}

		/**
		 * Wait until a Myo is physically very near to the Bluetooth radio and pair with it,
		 * or time out after timeoutMilliseconds milliseconds if provided.
		 * 
		 * <p>If timeout_ms is zero, this function blocks until a Myo is found. This function
		 * must not be run concurrently with run() or runOnce().</p> 
		 */		
		public function waitForAdjacentMyo( timeoutMilliseconds:int = 0 ):Myo
		{
			var myo:Object = context.call( "waitForAdjacentMyo", timeoutMilliseconds ) as Myo;
			if( myo )
			{
				_myos.push( myo );
				return myo as Myo;
			}
			
			return null;
		}
		
		/**
		 * Initiate pairing with any nearby Myo. Once pairing is initiated, run() must be called
		 * until a pairing event is received (via DeviceListener::onPair). 
		 */		
		public function pairWithAnyMyo():void
		{
			if( context )
			{
				context.call( "pairWithAnyMyo" );
			}
		}
		
		/**
		 * Initiate pairing with the provided number of nearby Myos. Once pairing is initiated,
		 * run() must be called until a pairing event is received (via DeviceListener::onPair). 
		 */		
		public function pairWithAnyMyos( count:int ):void
		{
			if( context )
			{
				context.call( "pairWithAnyMyos", count );
			}
		}
		
		/**
		 * Initiate pairing with a Myo that is physically very near to the Bluetooth radio.
		 * 
		 * <p>Once pairing is initiated, run() must be called until a pairing event is received
		 * (via DeviceListener::onPair).</p> 
		 */		
		public function pairWithAdjacentMyo():void
		{
			if( context )
			{
				context.call( "pairWithAdjacentMyo" );
			}
		}
		
		/**
		 * Initiate pairing with one or more Myos that are physically very near to the
		 * Bluetooth radio.
		 * 
		 * <p>Each Myo can be brought close to the Bluetooth radio one at a time.
		 * Once pairing is initiated, run() must be called until a pairing event is
		 * received (via DeviceListener::onPair).</p> 
		 */		
		public function pairWithAdjacentMyos( count:int ):void
		{
			if( context )
			{
				context.call( "pairWithAdjacentMyos", count );
			}
		}
		
		/**
		 * Initiate pairing with a Myo that has the given MAC address.
		 * 
		 * <p>This is primarily useful for testing in an environment with
		 * multiple Myos, where you wish to connect to a specific Myo.</p> 
		 */		
		public function pairByMacAddress( macAddress:int ):void
		{
			if( context )
			{
				context.call( "pairByMacAddress", macAddress );
			}
		}
		
		/**
		 * Register a listener to be called when device events occur. 
		 */		
		public function addListener( listener:DeviceListener ):void
		{
			_listeners.push( listener );
			if( context )
			{
				context.call( "addListener", listener );
			}
		}
		
		/**
		 * Remove a previously registered listener. 
		 */		
		public function removeListener( listener:DeviceListener ):void
		{
			var i:int = 0;
			for( i; i < _listeners.length; i++ )
			{
				if( _listeners[ i ] == listener )
				{
					_listeners.splice( i, 1 );
					break;
				}
			}
		}
		
		/**
		 * Run the event loop for the specified duration (in milliseconds). 
		 */		
		public function run( durationMilliseconds:int ):void
		{
			if( context )
			{
				context.call( "run", durationMilliseconds );
			}
		}
		
		/**
		 * Run the event loop until a single event occurs, or the specified
		 * duration (in milliseconds) has elapsed. 
		 */		
		public function runOnce( durationMilliseconds:int ):void
		{
			
		}
	}
}