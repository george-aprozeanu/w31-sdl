cmake_minimum_required(VERSION 3.10)

# Set the project name
project(win31)

# Enable C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
add_subdirectory(vendor)
add_subdirectory(src)
