#include "ros/ros.h"
#include <sstream>
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main (int argc, char **argv){
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub=n.subscribe("test",5,callback);
    ros::Duration(0);
    while(ros::ok){
    ros::spinOnce();
    ros::Duration(8).sleep();
    }
    return 0;
}