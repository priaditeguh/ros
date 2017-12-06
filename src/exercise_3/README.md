## Setup

- Open new terminal, go to workspace '...\...\ros' 
- Build your workspace by running 'catkin_make'
- Then run 'source devel/setup.bash'
- Finally run 'roscore'

- Open new 3 terminals 
- For each terminal, in workspace directory run 'source devel/setup.bash'
- For each terminal, run 
	- 'rosrun exercise_3 exercise_3_pubvel'
	- 'rosrun exercise_3 exercise_3_vel_filter'
	- 'rosrun exercise_3 exercise_3_vel_printer'

- Open a new terminal
- run 'rqt_graph' to visualize the publish-subscribe relationships between ROS nodes

- If you're done, type CTRL+C in the last terminal to stop the graph.
- run 'rosnode list'
- then stop all listed node by running 'rosnode kill node-name', except 'rosout'
	- rosnode kill subscribe_geometry_Twist
	- rosnode kill filter_twist
	- rosnode kill publish_velocity
- then stop the master node (terminal that runs roscore) by typing CTRL+C