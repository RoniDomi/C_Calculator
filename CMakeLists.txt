cmake_minimum_required(VERSION 3.28)
project(C_Calculator C)

set(CMAKE_C_STANDARD 11)

# Specify the MSYS2 Mingw-w64 environment
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

# Find PkgConfig and GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

# Include GTK headers
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

# Add the executable and your source files
add_executable(C_Calculator main.c
        appStructure.c
        appStructure.h
)

# Link GTK libraries
target_link_libraries(C_Calculator ${GTK_LIBRARIES})
