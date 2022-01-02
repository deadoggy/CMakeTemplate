cmake_minimum_required(VERSION 3.16.3)

project(SPOON)

add_executable(${PROJECT_NAME} main.cpp)


# https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(Adder)


# https://cmake.org/cmake/help/v3.0/command/target_link_libraries.html
target_link_libraries(${PROJECT_NAME} adder)
