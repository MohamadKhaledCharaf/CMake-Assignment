cmake_minimum_required(VERSION 3.10)
project(PointCloudProcessor)

# set C++ standard

set(CMAKE_CXX_STANDARD 14)


#Find required packages 
find_package(PCL 1.8 REQUIRED COMPONENTS common io filters)
find_package(Eigen3 REQUIRED)

# Include directories

include_directories(
	$(PCL_INCLUDE_DIRS)}
	${EIGEN3_INCLUDE_DIR}
	include/
)

## Add executable 
add_executable(point_cloud_processor src/main.cpp)

#Link libraries
target_link_libraries(point_cloud_processor
	${PCL_LIBRARIES}
)

# Install target
install(TARGETS point_cloud_processor DESTINATION bin)



