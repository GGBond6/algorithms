cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms main.cpp)
add_executable(test test.cpp)
add_executable(Exercise6_7_1_Set_similarity Exercise6/7_1_Set_similarity.cpp)
add_executable(Exercise6_7_2_Social_cluster Exercise6/7_2_Social_cluster.cpp)

add_executable(Exercise6_7_3_Iceland's_family_tree Exercise6/7_3_Iceland's_family_tree.cpp)