#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h> 
#include "std_msgs/String.h"

int main(int argc,char** argv)
{
	//初始化ROS节点
	ros::init(argc,argv,"tf_listener");
	//创建节点句柄
	ros::NodeHandle node;
	//创建tf的监听器
	tf::TransformListener listener;
	ros::Rate rate(10.0);
	while (node.ok())
	{
		tf::StampedTransform transform;
		try
		{
			listener.waitForTransform("baselink","map",ros::Time(0),ros::Duration(3.0));//等待（3s超时报错）
			listener.lookupTransform("baselink","map",ros::Time(0),transform);//查询（结果保存在transform里）
		}
		catch(tf::TransformException &ex)
		{
			ROS_ERROR("%s",ex.what());
			ros::Duration(1.0).sleep();
			continue;
		}

		geometry_msgs::Vector3 msg;
		ROS_INFO("I heard: [%f]", msg.x);
		rate.sleep();

	}
	return 0;
}