/*
* Copyright (C) 2014 Thalmic Labs Inc.
* Confidential and not for redistribution. See LICENSE.txt.
*/
package
{
	import com.thalmiclabs.myo.DeviceListener;
	import com.thalmiclabs.myo.Myo;
	import com.thalmiclabs.myo.Pose;
	import com.thalmiclabs.myo.Quaternion;
	import com.thalmiclabs.myo.Vector3;
	import com.thalmiclabs.myo.Hub;
	
	import flash.display.*;
	import flash.text.*;
	import flash.text.TextFormat;
	import flash.utils.Timer;
	import flash.events.TimerEvent;
	
	[SWF( width="800", height="600", backgroundColor="#333333", frameRate="60" )]
	public class MyoAS3Sample extends Sprite implements DeviceListener {
		
		public static const RUN_TIME:Number = 1000/20;
		
		private var mTextView:TextField;
		
		private var hub:Hub;
		private var myo:Myo;
		private var timer:Timer;
		
		public function MyoAS3Sample():void
		{
			//stage.displayState = StageDisplayState.FULL_SCREEN_INTERACTIVE;
			var tf:TextFormat = new TextFormat();
			tf.size = 124;
			tf.font = "Helvetica Neue";
			
			mTextView = new TextField();
			mTextView.autoSize = TextFieldAutoSize.CENTER;
			mTextView.x = 400;
			mTextView.y = 400;
			mTextView.defaultTextFormat = tf;
			mTextView.text = "Welcome to MyoAS3";
			this.addChild( mTextView );
			hub = new Hub();
			hub.addListener( this );

			myo = hub.waitForAnyMyo();

			if(!myo) {
				trace("Unable to find a Myo! (AS)");
				return;
			}
			trace("(AS) connected to: " + myo.macAddressAsString);

			timer = new Timer(RUN_TIME, 0);
			timer.addEventListener( TimerEvent.TIMER, onTimerHandler );
			timer.start();
		}

		private function onTimerHandler(event:TimerEvent) :void
		{
			hub.run(RUN_TIME);
		}
		
		// Classes that inherit from AbstractDeviceListener can be used to receive events from Myo devices.
		// If you do not override an event, the default behavior is to do nothing.
		static private function toDegrees(radians:Number):Number
		{
			return radians*180/Math.PI;
		}

		public function onPair( myo:Myo ):void {
			trace( ">>> SAMPLE > onPaironPaironPaironPaironPaironPaironPaironPair");
		}
		
		// onConnect() is called whenever a Myo has been connected.
		public function onConnect( myo:Myo ):void {
			trace( "onConnect" );
			// Set the text color of the text view to cyan when a Myo connects.
			mTextView.textColor = 0x00ffff;
		}
		
		// onDisconnect() is called whenever a Myo has been disconnected.
		public function onDisconnect( myo:Myo ):void {
			trace( "onDisconnect" );
			if(timer) {
				timer.stop();
			}
			// Set the text color of the text view to red when a Myo disconnects.
			mTextView.textColor = 0xff0000;
		}
		
		// onOrientationData() is called whenever a Myo provides its current orientation,
		// represented as a quaternion.
		public function onOrientationData( myo:Myo, rotation:Quaternion ):void {
			trace( "onOrientationData" );
			// Calculate Euler angles (roll, pitch, and yaw) from the quaternion.
			var rotationZ:Number = toDegrees(Quaternion.roll(rotation));
			var rotationX:Number = toDegrees(Quaternion.pitch(rotation));
			var rotationY:Number = toDegrees(Quaternion.yaw(rotation));
			// Next, we apply a rotation to the text view using the roll, pitch, and yaw.
			mTextView.rotation = -rotationZ;
			mTextView.rotationX -rotationX;
			mTextView.rotationY = rotationY;
		}
		
		// onPose() is called whenever a Myo provides a new pose.
		public function onPose( myo:Myo, pose:Pose ):void {
			trace( "onPose" );
			// Handle the cases of the Pose.Type enumeration, and change the text of the text view
			// based on the pose we receive.
			switch (pose.type) {
				case Pose.POSE_NONE:
					mTextView.text = "No Pose";
					break;
				case Pose.POSE_FIST:
					mTextView.text = "Fist pose";
					break;
				case Pose.POSE_WAVE_IN:
					mTextView.text = "Wave In Pose";
					break;
				case Pose.POSE_WAVE_OUT:
					mTextView.text = "Wave Out Pose";
					break;
				case Pose.POSE_FINGERS_SPREAD:
					mTextView.text = "Fingers Spread Pose";
					break;
				case Pose.POSE_TWIST_IN:
					mTextView.text = "Twist In Pose";
					break;
			}
		}
		
		public function onAccelerometerData( myo:Myo, accel:Vector3 ):void
		{
			trace( "onAccelerometerData" );
		}
		
		public function onGyroscopeData( myo:Myo, gyro:Vector3 ):void
		{
			trace( "onGyroscopeData" );
		}
		
		public function onRssi( myo:Myo, rssi:int ):void
		{
			trace( "onRssi" );
		}
	}
}