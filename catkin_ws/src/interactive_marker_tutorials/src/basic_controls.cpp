#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <visualization_msgs/Marker.h>
#include <math.h>

using namespace visualization_msgs;

void frameCallback(const ros::TimerEvent&)
{
  static uint32_t counter = 0;
  static tf::TransformBroadcaster br;

  tf::Transform t;
	
  ros::Time time = ros::Time::now();
  t.setOrigin(tf::Vector3(sin(float(counter)/140.0) * 2.0, cos(float(counter)/140.0) * 2.0, 0.0));
  t.setRotation(tf::createQuaternionFromRPY(3.0, 3.0, 0.0));
  br.sendTransform(tf::StampedTransform(t, time, "sun", "earth")); 
  t.setOrigin(tf::Vector3(sin(float(counter)/140.0) * 2.0, cos(float(counter)/140.0) * 2.0, 0.0));
  t.setRotation(tf::createQuaternionFromRPY(0.0, 0.0, 0.0));
  br.sendTransform(tf::StampedTransform(t, time, "sun", "r_sun"));  
  t.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
  t.setRotation(tf::createQuaternionFromRPY(0.0, 0.0, float(counter)/40.0));
  br.sendTransform(tf::StampedTransform(t, time, "earth", "r_earth")); 
  t.setOrigin(tf::Vector3(sin(float(counter/2)/20), cos(float(counter/2)/20) , 0.0));
  t.setRotation(tf::createQuaternionFromRPY(0.0, 0.0, 0.0));
  br.sendTransform(tf::StampedTransform(t, time, "r_sun", "moon"));
  counter++;
}

////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  ros::init(argc, argv, "basic_controls");
  ros::NodeHandle n;

  ros::Timer frame_timer = n.createTimer(ros::Duration(0.01), frameCallback);

  ros::Duration(0.1).sleep();

  ros::spin();
  }
