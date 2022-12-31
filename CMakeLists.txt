cmake_minimum_required(VERSION 3.24)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(RayTracer main.cpp CoordFiles/point.cpp CoordFiles/point.h CoordFiles/vec.cpp CoordFiles/vec.h CoordFiles/coordOps.cpp CoordFiles/coordOps.h CanvasFiles/color.cpp CanvasFiles/color.h CanvasFiles/colorOps.cpp CanvasFiles/colorOps.h CanvasFiles/canvas.cpp CanvasFiles/canvas.h CoordFiles/matrix.cpp CoordFiles/matrix.h CoordFiles/matrixOps.cpp CoordFiles/matrixOps.h SceneFiles/RayFiles/ray.cpp SceneFiles/RayFiles/ray.h SceneFiles/Shapes/sphere.cpp SceneFiles/Shapes/sphere.h SceneFiles/Shapes/shape.h SceneFiles/RayFiles/rayOps.cpp SceneFiles/RayFiles/rayOps.h SceneFiles/RayFiles/intersection.cpp SceneFiles/RayFiles/intersection.h CoordFiles/coord.h SceneFiles/RayFiles/pointLight.cpp SceneFiles/RayFiles/pointLight.h SceneFiles/Shapes/material.cpp SceneFiles/Shapes/material.h)
