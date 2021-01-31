#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

int mycount = 0;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  mycount=stoi(msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");


  ros::NodeHandle n;


  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);


  ros::Rate loop_rate(0.5);
  while (ros::ok())
  {

    std_msgs::String msg;

    std::stringstream ss;

    ss<<mycount;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    ros::spinOnce();

    loop_rate.sleep();
    mycount = (mycount++)%100;
  }
  return 0;
}