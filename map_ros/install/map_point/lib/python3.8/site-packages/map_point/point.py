from map_service.srv import PointRequest     # CHANGE
from ament_index_python.packages import get_package_share_directory
import rclpy
import os
from rclpy.node import Node


class MinimalService(Node):

    def __init__(self):
        self.waypoint_files_path = "/home/hayashi/map_ros/src/map_point/waypoint_files/waypoints.txt"
    
        super().__init__('minimal_service')
        self.get_logger().info('path %s' % str(self.waypoint_files_path))
        self.srv = self.create_service(PointRequest, 'receive_point', self.receive_point_callback)       

    def receive_point_callback(self, request, response):
        response.message = 'received lat and long'
        if  os.path.isfile(self.waypoint_files_path):
            with open(self.waypoint_files_path, mode='w') as f:                                          
                for i in range(0,len(request.lat)):
                    self.get_logger().info('Incoming request\nlat: %8f long: %8f' % (request.lat[i], request.lng[i])) 
                    f.write(str(request.lat[i]) + ' ' + str(request.lng[i]) + '\n')
                
        return response

def main(args=None):
    rclpy.init(args=args)

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()

if __name__ == '__main__':
    main()