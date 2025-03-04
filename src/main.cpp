#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/ply_io.h>
#include <pcl/common/transforms.h>
#include <Eigen/Dense>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.ply> <output.ply>\n";
        return 1;
    }

    // 1. Load point cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPLYFile<pcl::PointXYZ>(argv[1], *cloud) == -1) {
        std::cerr << "Error loading file!\n";
        return 1;
    }

    // 2. Filter point cloud
    pcl::VoxelGrid<pcl::PointXYZ> voxel_filter;
    voxel_filter.setInputCloud(cloud);
    voxel_filter.setLeafSize(0.1f, 0.1f, 0.1f);  // Adjust leaf size as needed
    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    voxel_filter.filter(*filtered_cloud);

    // 3. Transform point cloud
    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    transform.translation() << 1.0, 0.5, 0.0;  // Translate by (1.0, 0.5, 0.0)
    transform.rotate(Eigen::AngleAxisf(M_PI/4, Eigen::Vector3f::UnitZ()));  // Rotate 45° around Z-axis

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::transformPointCloud(*filtered_cloud, *transformed_cloud, transform);

    // 4. Save transformed point cloud
    pcl::io::savePLYFileASCII(argv[2], *transformed_cloud);

    std::cout << "Processing completed!\n";
    return 0;
}