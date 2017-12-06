// This program subscribes geometry/Twist messages and prints them on the console

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist
#include <iomanip> // for std::setprecision and std::fixed

// A call back function . Executed each time a new geometry/Twist message arrives.
void twistMessageReceived(const geometry_msgs::Twist& msg) 
{
	ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "linear = " << msg.linear.x << " , "<< "angular = " << msg.angular.z);
}

int main (int argc, char **argv) 
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"subscribe_geometry_Twist");
	ros::NodeHandle nh;

	// Create a subscriber object.
	ros::Subscriber sub = nh.subscribe("geometry/Twist", 1000, &twistMessageReceived);

	// Let ROS take over .
	ros::spin();

	return 0;
}