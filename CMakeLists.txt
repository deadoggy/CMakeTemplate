cmake_minimum_required(VERSION 3.16.3)

project(SPOON)

add_executable(${PROJECT_NAME} main.cpp)


# https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(Adder)
add_subdirectory(external/glfw)



# https://cmake.org/cmake/help/v3.0/command/target_link_libraries.html
# The name of GLFW library is glfw although the file name is libglfw3.a. It is specified in external/glfw/src/CMakeLists.txt
target_link_libraries(${PROJECT_NAME} 
        adder
        glfw
)

# https://cmake.org/cmake/help/latest/command/target_link_directories.html
# The relative path is to the target, which is out/build/SPOON in this project
target_link_directories(${PROJECT_NAME}
        PRIVATE Adder
        PRIVATE external/glfw/src
)

# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${PROJECT_NAME} 
        PUBLIC Adder 
        PUBLIC external/glfw/include
)

