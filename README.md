# Point Cloud Processor

A C++ project that processes point clouds using the Point Cloud Library (PCL) and Eigen. It loads a point cloud from a PLY file, filters it using a voxel grid, applies a transformation, and saves the result to a new PLY file.

---

## Table of Contents
1. [Features](#features)
2. [Dependencies](#dependencies)
3. [Build Instructions](#build-instructions)
4. [Usage](#usage)
---

## Features
- **Load PLY Files**: Reads point cloud data from a PLY file.
- **Voxel Grid Filter**: Downsamples the point cloud using a voxel grid.
- **Transformations**: Applies rotation and translation to the point cloud.
- **Save PLY Files**: Writes the processed point cloud to a new PLY file.

---

## Dependencies
- **PCL (Point Cloud Library)**: For point cloud processing.
- **Eigen**: For linear algebra and transformations.
- **CMake**: For building the project.

Install dependencies on Ubuntu:
```bash
sudo apt install libpcl-dev libeigen3-dev cmake
```

## Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/PointCloudProcessor.git
   cd PointCloudProcessor
   ```
2. Create a build directory and compile the project:
   ```bash
   mkdir build
    cd build
    cmake ..
    make
   ```
## Usage
   ```bash
   ./point_cloud_processor ../data/input.ply ../data/output.ply
   ```

