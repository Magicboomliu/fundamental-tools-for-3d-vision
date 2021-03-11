cmake_minimum_required(VERSION 2.8)
project(ceres_beginners)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

# Show the path of the cmake confront file of Ceres
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)


# Found installed Ceres in your Device
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})


# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# # Ceres
# find_package(Ceres REQUIRED)
# include_directories(${CERES_INCLUDE_DIRS})

# # g2o
# find_package(G2O REQUIRED)
# include_directories(${G2O_INCLUDE_DIRS})

# Eigen
include_directories("/usr/include/eigen3")


# Run the project  自动求导法
add_executable(ceres_hello_world ceres_hello_world.cpp)
target_link_libraries(ceres_hello_world ${CERES_LIBRARIES})

# 解析求导法
add_executable(ceres_analytical_derivatives ceres_analytical_derivatives.cpp)
target_link_libraries(ceres_analytical_derivatives ${CERES_LIBRARIES} ${OpenCV_LIBS})

# 多个 residual Block的求解
add_executable(ceres_powell_function ceres_powell_function.cpp)
target_link_libraries(ceres_powell_function ${CERES_LIBRARIES} ${OpenCV_LIBS})

# 使用 Ceres 进行曲线拟合
add_executable(ceres_curve_fitting ceres_curve_fitting.cpp)
target_link_libraries(ceres_curve_fitting ${CERES_LIBRARIES} ${OpenCV_LIBS})
