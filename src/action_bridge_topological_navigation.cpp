#include <action_bridge/action_bridge.hpp>

#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include <ori_topological_navigation_msgs/TraverseToNodeAction.h>
#ifdef __clang__
# pragma clang diagnostic pop
#endif

// include ROS 2
#include <stretch_topological_navigation_msgs/action/traverse_to_node.hpp>

using TopoNavBridge = ActionBridge_2_1<ori_topological_navigation_msgs::TraverseToNodeAction,
    stretch_topological_navigation_msgs::action::TraverseToNode>;

template<>
void TopoNavBridge::translate_goal_2_to_1(const ROS2Goal & goal2, ROS1Goal & goal1)
{
  goal1.node_id = goal2.node_id;
}

template<>
void TopoNavBridge::translate_result_1_to_2(
  ROS2Result & result2,
  const ROS1Result & result1)
{
  result2.success = result1.success;
}

template<>
void TopoNavBridge::translate_feedback_1_to_2(
  ROS2Feedback & feedback2,
  const ROS1Feedback & feedback1)
{
  // no feedback message
  return;
}

int main(int argc, char * argv[])
{
  return TopoNavBridge::main("traverse_to_node", "traverse_to_node", argc, argv);
}
