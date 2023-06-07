#include <action_bridge/action_bridge.hpp>

#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include <move_base_msgs/MoveBaseAction.h>
#ifdef __clang__
# pragma clang diagnostic pop
#endif

// include ROS 2
#include <nav2_msgs/action/navigate_to_pose.hpp>

using MoveBaseActionBridge = ActionBridge<move_base_msgs::MoveBaseAction,
    nav2_msgs::action::NavigateToPose>;

template<>
void MoveBaseActionBridge::translate_goal_1_to_2(const ROS1Goal & goal1, ROS2Goal & goal2)
{
  // goal2.pose = goal1.target_pose
  goal2.pose.pose.position.x = goal1.target_pose.pose.position.x;
  goal2.pose.pose.position.y = goal1.target_pose.pose.position.y;
  goal2.pose.pose.position.z = goal1.target_pose.pose.position.z;
  goal2.pose.pose.orientation.w = goal1.target_pose.pose.orientation.w;
  goal2.pose.pose.orientation.x = goal1.target_pose.pose.orientation.x;
  goal2.pose.pose.orientation.y = goal1.target_pose.pose.orientation.y;
  goal2.pose.pose.orientation.z = goal1.target_pose.pose.orientation.z;

  goal2.pose.header.frame_id = goal1.target_pose.header.frame_id;
  goal2.pose.header.stamp.sec = goal1.target_pose.header.stamp.sec;
  goal2.pose.header.stamp.nanosec = goal1.target_pose.header.stamp.nsec;
}

template<>
void MoveBaseActionBridge::translate_result_2_to_1(
  ROS1Result & result1,
  const ROS2Result & result2)
{
  return;
}

template<>
void MoveBaseActionBridge::translate_feedback_2_to_1(
  ROS1Feedback & feedback1,
  const ROS2Feedback & feedback2)
{
  //feedback1.base_position = feedback2.current_pose;
  feedback1.base_position.pose.position.x = feedback2.current_pose.pose.position.x;
  feedback1.base_position.pose.position.y = feedback2.current_pose.pose.position.y;
  feedback1.base_position.pose.position.z = feedback2.current_pose.pose.position.z;
  feedback1.base_position.pose.orientation.w = feedback2.current_pose.pose.orientation.w;
  feedback1.base_position.pose.orientation.x = feedback2.current_pose.pose.orientation.x;
  feedback1.base_position.pose.orientation.y = feedback2.current_pose.pose.orientation.y;
  feedback1.base_position.pose.orientation.z = feedback2.current_pose.pose.orientation.z;

  feedback1.base_position.header.frame_id = feedback2.current_pose.header.frame_id;
  feedback1.base_position.header.stamp.sec = feedback2.current_pose.header.stamp.sec;
  feedback1.base_position.header.stamp.nsec = feedback2.current_pose.header.stamp.nanosec;
}

int main(int argc, char * argv[])
{
  return MoveBaseActionBridge::main("move_base", argc, argv);
}
