// This program publish filtered geometry/Twist messages 

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist

ros::Publisher pub;

// A call back function . Executed each time a new turtle1/cmd_vel message arrives.
void twistMessageFiltered(const geometry_msgs::Twist& msg) 
{
	if(msg.angular.z >= 0)
	{
		// Publish the message.
		pub.publish(msg);
	}
}

int main (int argc, char **argv) 
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"filter_velocity");
	ros::NodeHandle nh;

	// Create a publisher object.
	pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel_filtered",1000);

	// Create a subscriber object.
	ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel", 1000, &twistMessageFiltered);

	// Let ROS take over .
	ros::spin();

	return 0;
}