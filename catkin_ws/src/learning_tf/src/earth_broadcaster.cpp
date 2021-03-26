#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>
#include  <sstream>
#include "std_msgs/String.h"
int main(int argc,char** argv)
{
	ros::init(argc,argv,"tf_broadcaster");
	static tf::TransformBroadcaster br;
	double count=0;
	tf::Transform t;
	ros::Time time = ros::Time::now();
	geometry_msgs::PointStamped ps;
	ros::Duration(0);
	while (ros::ok()){
		t.setOrigin(tf::Vector3(count, 0.0, 0.0));
		t.setRotation(tf::createQuaternionFromRPY(0.0, 0.0, 0.0));
		br.sendTransform(tf::StampedTransform(t, time, "baselink", "map")); 
		ROS_INFO("%.2f", ps.point.x);
		ros::Duration(0.1).sleep();
		count=count+0.1;
	}
	return 0;
}
