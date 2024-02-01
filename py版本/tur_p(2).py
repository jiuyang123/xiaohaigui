import rclpy
import math
from rclpy.node import Node
from turtlesim.msg import Pose

class turNode(Node):
    def __init__(self) -> None:
        super().__init__("tur_p")
        self.pose_ = None
        self.pose_ = self.create_subscription(Pose, "turtle1/pose", self.tur_call_back, 10)
  
    def tur_call_back(self, msg):
        self.pose_ = msg
        x = self.pose_.x
        y = self.pose_.y
        rad1 = math.atan2(y,x)
        angle = round(rad1*180/3.14)
        length = math.sqrt(pow(x,2)+pow(y,2))
        self.get_logger().info("小海龟与原点偏离角度为：%lf度 ,距离为:%lf"%(angle,length))

def main(args=None):
    rclpy.init(args=args)
    node = turNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()    