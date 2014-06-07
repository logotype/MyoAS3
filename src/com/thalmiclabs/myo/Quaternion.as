package com.thalmiclabs.myo
{
	public class Quaternion
	{
		public var x:Number;
		public var y:Number;
		public var z:Number;
		public var w:Number;
		
		public function Quaternion(_x:Number, _y:Number, _z:Number, _w:Number)
		{
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
				
		public function normalized():Quaternion
		{
			var magnitude:Number = Math.sqrt(x*x + y*y + z*z + w*w);
			return new Quaternion(x/magnitude, y/magnitude, z/magnitude, w/magnitude);
		}
		
		public function conjugate():Quaternion
		{
			return new Quaternion(-x, -y, -z, w);
		}
		
		public static function roll(rotation:Quaternion):Number
		{
			return Math.atan2(2*rotation.y*rotation.w - 2*rotation.x*rotation.z, 1 - 2*rotation.y*rotation.y - 2*rotation.z*rotation.z);;
		}
		
		public static function pitch(rotation:Quaternion):Number
		{
			return Math.atan2(2*rotation.x*rotation.w - 2*rotation.y*rotation.z, 1 - 2*rotation.x*rotation.x - 2*rotation.z*rotation.z);
		}
		
		public static function yaw(rotation:Quaternion):Number
		{
			return Math.asin(2*rotation.x*rotation.y + 2*rotation.z*rotation.w);
		}
		
		/**
		 * Returns a string containing this quaternion in a human readable format: (x, y, z, w).
		 * @return
		 *
		 */
		public function toString():String
		{
			return "[Quaternion x:" + x + " y:" + y + " z:" + z + " w:" + w + "]";
		}
	}
}