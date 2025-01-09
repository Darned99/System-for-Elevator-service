#Required version of CMake
cmake_minimum_required(VERSION 3.10)

#Standard of C++
set(CMAKE_CXX_STANDARD 20)

# Project name
project(ElevatorSystem)

# Include directories
include_directories(include)

# Source files
aux_source_directory(src SRC_FILES)

# Executable
add_executable(ElevatorSystem ${SRC_FILES})
