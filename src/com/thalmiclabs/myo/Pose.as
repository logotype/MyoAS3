package com.thalmiclabs.myo
{
	public class Pose
	{
		/**
		 * Default pose type when no pose is being made (PoseTypeNone)
		 */
		static public const POSE_NONE:int = 0;
		
		/**
		 * Clenching fingers together to make a fist (PoseTypeFist)
		 */
		static public const POSE_FIST:int = 1;
		
		/**
		 * Turning your palm towards yourself (PoseTypeWaveIn)
		 */
		static public const POSE_WAVE_IN:int = 2;
		
		/**
		 * Turning your palm away from yourself (PoseTypeWaveOut)
		 */
		static public const POSE_WAVE_OUT:int = 3;
		
		/**
		 * Spreading your fingers and extending your palm (PoseTypeFingersSpread)
		 */
		static public const POSE_FINGERS_SPREAD:int = 4;
		
		/**
		 * Twist your wrist in towards yourself (PoseTypeTwistIn)
		 */
		static public const POSE_TWIST_IN:int = 5;
		
		/**
		 * The Myo posting the pose. 
		 */
		public var myo:Myo;
		
		/**
		 * The pose being recognized. 
		 */
		public var type:int;
		
		public function Pose()
		{
		}
		
		final public function isEqualTo( other:Pose ):Boolean
		{
			if( type != other.type )
				return false;
			
			return true;
		}

		/**
		 * Return a human-readable string representation of the pose.
		 * @return
		 *
		 */
		final public function toString():String
		{
			switch( type )
			{
				case POSE_NONE:
					return "[Pose type:" + type.toString() + " POSE_NONE]";
					break;
				case POSE_FIST:
					return "[Pose type:" + type.toString() + " POSE_FIST]";
					break;
				case POSE_WAVE_IN:
					return "[Pose type:" + type.toString() + " POSE_WAVE_IN]";
					break;
				case POSE_WAVE_OUT:
					return "[Pose type:" + type.toString() + " POSE_WAVE_OUT]";
					break;
				case POSE_FINGERS_SPREAD:
					return "[Pose type:" + type.toString() + " POSE_FINGERS_SPREAD]";
					break;
				case POSE_TWIST_IN:
					return "[Pose type:" + type.toString() + " POSE_TWIST_IN]";
					break;
				default:
					break;
			}
			return "[Pose type:" + type.toString() + "]";
		}
	}
}