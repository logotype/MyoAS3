package com.thalmiclabs.myo.native
{
	import com.thalmiclabs.myo.Hub;
	
	import flash.desktop.NativeApplication;
	import flash.events.Event;
	import flash.events.StatusEvent;
	import flash.external.ExtensionContext;

	public class MyoNative
	{
		/**
		 * Boolean toggle to check if the class has been initialized
		 */
		private static var initialized:Boolean;

		/**
		 * Reference to the shared extension context
		 */
		private static var sharedContext:ExtensionContext;

		/**
		 * The native extension context for the device
		 */
		private var context:ExtensionContext;
		
		/**
		 * TODO: make vectors of these 
		 */		
		public var hub:Hub;

		public function MyoNative( _hub:Hub )
		{
			hub = _hub;
						
			if( MyoNative.isSupported() )
			{
				context = ExtensionContext.createExtensionContext( "com.thalmiclabs.myo.air.native.MyoNative", null );

				context.call( "initialize", this );
				hub.context = context;
				context.addEventListener( StatusEvent.STATUS, contextStatusModeEventHandler, false, 0, true );
				NativeApplication.nativeApplication.addEventListener( "exiting", onNativeApplicatonExitHandler );
			}
		}
		
		/**
		 * Triggered when application closes.
		 * @param event
		 *
		 */
		private function onNativeApplicatonExitHandler( event:Event ) :void
		{
			try
			{
				context.dispose();
			}
			catch( error:Error )
			{
				
			}
		}

		/**
		 * Inline method. Triggered when extension context changes status.
		 * @param event
		 *
		 */
		[Inline]
		final private function contextStatusModeEventHandler( event:StatusEvent ):void
		{
			trace( "[MyoNative] contextStatusModeEventHandler: ", event.code, event.level );
		}

		/**
		 * Reports whether the native library is supported.
		 *
		 * @return True if supported; false otherwise.
		 */
		public static function isSupported():Boolean
		{
			if( !initialized )
			{
				initialized = true;
				sharedContext = ExtensionContext.createExtensionContext( "com.thalmiclabs.myo.air.native.MyoNative", "shared" );
				if( sharedContext )
				{
					try
					{
						var supported:Boolean = sharedContext.call( "isSupported" );
						return supported;
					}
					catch( error:Error )
					{
						trace( "[MyoNative] Myo Native Extension is not supported." );
						return false;
					}
					return true;
				}
			}
			return false;
		}
	}
}
