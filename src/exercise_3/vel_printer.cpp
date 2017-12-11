// This program subscribes geometry/Twist messages and prints them on the console

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist
#include <iomanip> // for std::setprecision and std::fixed

// A call back function . Executed each time a new turtle1/cmd_vel_filtered message arrives.
void twistMessageReceived(const geometry_msgs::Twist& msg) 
{
	ROS_INFO_STREAM("linear = " << msg.linear.x << " , "<< "angular = " << msg.angular.z);
}

int main (int argc, char **argv) 
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"subscribe_velocity");
	ros::NodeHandle nh;

	// Create a subscriber object.
	ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel_filtered", 1000, &twistMessageReceived);

	// Let ROS take over .
	ros::spin();

	return 0;
}