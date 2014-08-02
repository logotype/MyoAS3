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
		public function waitForMyo( timeoutMilliseconds:int = 0 ):Myo
		{
			var myo:Myo = Myo( context.call( "waitForMyo", timeoutMilliseconds ) );
			if( myo )
			{
				myo.context = context;
				_myos.push( myo as Myo );
				return myo;
			}
			
			return null;
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