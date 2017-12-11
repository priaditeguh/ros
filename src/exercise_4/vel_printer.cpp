// This program subscribes geometry/Twist messages and prints them on the console

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist

// A call back function . Executed each time a new turtle1/cmd_vel_filtered message arrives.
void twistMessageReceived(const geometry_msgs::Twist& msg) 
{
	static int total_msg_print = 0;

	total_msg_print++;
	ROS_INFO_STREAM_THROTTLE(5.0,"Total received messages vel_printer: " << total_msg_print);
}

int main (int argc, char **argv) 
{
	// total_msg_print = 0;

	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"subscribe_velocity");
	ros::NodeHandle nh;

	// Create a subscriber object.
	ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel_filtered", 1000, &twistMessageReceived);

	// Let ROS take over .
	ros::spin();

	return 0;
}