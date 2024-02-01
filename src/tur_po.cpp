#include"rclcpp/rclcpp.hpp"
#include"turtlesim/msg/pose.hpp"
#include "math.h"

class turNode: public rclcpp::Node

{
private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub;
     float x = 0;
     float y = 0;
     double rad1 = 0;
     double angle = 0;
     double length = 0;
    void tur_call_back(const turtlesim::msg::Pose::SharedPtr msg)
    {
        x=msg->x;
        y=msg->y;
        rad1=std::atan2(y,x);
        angle=std::round(rad1*180/3.14);
        length=std::sqrt(pow(x,2)+pow(y,2));
        RCLCPP_INFO(get_logger(),"小海龟与原点偏离角度为%lf度,距离为%lf",angle,length);
    }

public:
  turNode():Node("tur_po")
  {
      sub = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose",10,std::bind(&turNode::tur_call_back,this,std::placeholders::_1));
  } 
};

int main(int argc,char ** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<turNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}