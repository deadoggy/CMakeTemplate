cmake_minimum_required(VERSION 3.16.3)

project(SPOON)

add_executable(${PROJECT_NAME} main.cpp)


# https://cmake.org/cmake/help/latest/command/add_subdirectory.html

# Individual library 

add_subdirectory(Adder)


# Git submodule library

#           DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
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

