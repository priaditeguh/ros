// This program publishes randomly-generated velocity
// messages for turtlesim
#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX

int main (int argc, char **argv) 
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"publish_velocity");
	ros::NodeHandle nh;

	// Create a publisher object.
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

	// Seed the random number generator
	srand(time(0));

	// Loop at 2Hz until the node is shut down.
	ros::Rate rate(2);

	int total_msg = 0;
	while(ros::ok())
	{
		// Create and fill in the message. The other four
		// fields, which are ignored by turtlesim , default to 0.
		geometry_msgs::Twist msg;
		msg.linear.x = double(rand()) / double(RAND_MAX);
		msg.angular.z = 2 * double(rand()) / double(RAND_MAX) - 1;

		// Publish the message.
		pub.publish(msg);

		total_msg++;

		ROS_INFO_STREAM_THROTTLE(5.0,"Total published messages pubvel: " << total_msg);	

		// Wait until it's time for another iteration.
		rate.sleep();
	}

	return 0;
}