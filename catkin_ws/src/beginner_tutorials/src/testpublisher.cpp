#include "ros/ros.h"
#include <sstream>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc,argv,"talker");
    ros::NodeHandle n;
    ros::Publisher pub=n.advertise<std_msgs::String>("test",100);
    int c=0;
    ros::Duration(0);
     while (ros::ok){
         std::stringstream ss;
         ss << "hhj" << c;
         std_msgs::String msg;
         msg.data=ss.str();
         ros::Duration(0.5).sleep();
         ROS_INFO("%s", msg.data.c_str());
         pub.publish(msg);
         c++;
     }
     return 0;
}