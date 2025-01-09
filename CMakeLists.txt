cmake_minimum_required(VERSION 3.10)

project(System-for-Elevator-service)

# Określenie wersji standardu C++
set(CMAKE_CXX_STANDARD 20)

# Ścieżki do kompilatorów (jeśli chcesz używać MSYS2, MinGW lub MSVC)
set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

# Katalogi z nagłówkami
include_directories(include)

# Dodanie plików źródłowych
aux_source_directory(src SRC_FILES)

# Utworzenie pliku wykonywalnego
add_executable(System-for-Elevator-service.out ${SRC_FILES})
