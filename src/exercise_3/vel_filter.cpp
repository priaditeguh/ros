// This program publish filtered geometry/Twist messages 

#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist

// angular velocity
double angular_vel = 0;
double linear_vel = 0;

// A call back function . Executed each time a new turtle1/cmd_vel message arrives.
void twistMessageReceived(const geometry_msgs::Twist& msg) 
{
	angular_vel = msg.angular.z;
	linear_vel = msg.linear.x;
}

int main (int argc, char **argv) 
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv,"filter_twist");
	ros::NodeHandle nh;

	// Create a subscriber object.
	ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel", 1000, &twistMessageReceived);

	// Create a publisher object.
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("geometry/Twist",1000);

	// Loop at 2Hz until the node is shut down.
	ros::Rate rate(2);

	while(ros::ok()) {

		// Let ROS take over
		ros::spinOnce();

		// only publish when angular velocity is positive 
		if (angular_vel >= 0) 
		{
			// message for republish
			geometry_msgs::Twist msg;

			msg.linear.x = linear_vel;
			msg.angular.z = angular_vel;

			// Publish the message.
			pub.publish(msg);
		}

		// Wait until it's time for another iteration.
		rate.sleep();
	}

	return 0;
}