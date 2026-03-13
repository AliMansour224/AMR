import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from visualization_msgs.msg import Marker, MarkerArray
import math
import numpy as np

class ConeDetector(Node):
    def __init__(self):
        super().__init__('cone_detector')
        self.sub = self.create_subscription(
            LaserScan, '/lidar_topic', self.scan_callback, 10)
        self.cone_pub = self.create_publisher(
            MarkerArray, '/perception/cones', 10)
        self.get_logger().info('Cone detector started')

    def scan_callback(self, msg):
        # Convert polar to Cartesian
        points = []
        angle = msg.angle_min
        for r in msg.ranges:
            if msg.range_min < r < msg.range_max:
                x = r * math.cos(angle)
                y = r * math.sin(angle)
                points.append([x, y])
            angle += msg.angle_increment

        if len(points) < 3:
            return

        # Cluster points (simple Euclidean distance threshold)
        # For simplicity, we use a custom clustering based on distance
        points = np.array(points)
        clusters = self.cluster_points(points, eps=0.3)

        # Create marker array for visualization
        marker_array = MarkerArray()
        for i, cluster in enumerate(clusters):
            if len(cluster) < 2:
                continue
            # Compute centroid
            centroid = np.mean(cluster, axis=0)
            # Create a sphere marker at centroid
            marker = Marker()
            marker.header = msg.header
            marker.ns = 'cones'
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            marker.pose.position.x = float(centroid[0])
            marker.pose.position.y = float(centroid[1])
            marker.pose.position.z = 0.0
            marker.scale.x = 0.2
            marker.scale.y = 0.2
            marker.scale.z = 0.2
            # Color based on cluster size or distance (dummy)
            marker.color.a = 1.0
            marker.color.r = 1.0
            marker.color.g = 0.0
            marker.color.b = 0.0
            marker_array.markers.append(marker)

        self.cone_pub.publish(marker_array)
        self.get_logger().info(f'Published {len(marker_array.markers)} cones')

    def cluster_points(self, points, eps=0.3):
        """Group 2D points into clusters based on proximity.

        If ``scikit-learn`` is installed, :class:`sklearn.cluster.DBSCAN`
        is used; otherwise a simple O(n²) breadth-first search is run.
        """
        # try to import DBSCAN lazily, it's optional
        try:
            # optional dependency
            from sklearn.cluster import DBSCAN  # type: ignore[import]
        except ImportError:
            DBSCAN = None

        if DBSCAN is not None:
            clustering = DBSCAN(eps=eps, min_samples=2).fit(points)
            labels = clustering.labels_
            clusters = []
            for label in set(labels):
                if label == -1:
                    continue
                clusters.append(points[labels == label])
            return clusters

        # fallback: naive distance-based clustering
        n = len(points)
        visited = [False] * n
        clusters = []

        for i in range(n):
            if visited[i]:
                continue
            cluster = [points[i]]
            visited[i] = True
            queue = [i]
            while queue:
                idx = queue.pop(0)
                for j in range(n):
                    if not visited[j]:
                        if np.linalg.norm(points[j] - points[idx]) < eps:
                            visited[j] = True
                            queue.append(j)
                            cluster.append(points[j])
            if len(cluster) >= 2:
                clusters.append(np.array(cluster))
        return clusters

def main(args=None):
    rclpy.init(args=args)
    node = ConeDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()