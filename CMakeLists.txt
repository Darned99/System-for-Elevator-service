#Required version of CMake
cmake_minimum_required(VERSION 3.10)

#Standard of C++
set(CMAKE_CXX_STANDARD 20)

# Path to the compiler
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

# Project name
project(ElevatorSystem)

# Include directories
include_directories(include)

# Source files
aux_source_directory(src SRC_FILES)

# Executable
add_executable(ElevatorSystem ${SRC_FILES})
