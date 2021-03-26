#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

std::string turtle_name;
void poseCallback(const turtlesim::PoseConstPtr& msg)
{
//创建tf的广播器（重点）
	static tf::TransformBroadcaster br;
	//初始化tf数据
	tf::Transform transform;//两坐标系间位置关系
	transform.setOrigin(tf::Vector3(msg->x,msg->y,0.0));//平移关系
	tf::Quaternion q; //四元数
	q.setRPY(0,0,msg->theta);//设置两坐标系间姿态变化设置
	transform.setRotation(q);//旋转关系
	//广播world与海龟坐标系之间的tf数据
	br.sendTransform(tf::StampedTransform(transform,ros::Time::now(),"world",turtle_name));
}
int main(int argc,char** argv)
{
//初始化ROS节点
	ros::init(argc,argv,"my_tf_broadcaster");
	//输入参数作为海龟的名字
	if (argc!=2)
	{
		ROS_ERROR("ERROR");
		return -1;
	}
	turtle_name = argv[1];
	//订阅海龟的位姿话题
	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe(turtle_name+"/pose",10,&poseCallback);
	//循环等待回调函数
	ros::spin();
	return 0;
}

