cmake_minimum_required(VERSION 3.14)
project(cppwc)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

#Fetch cxxopts
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT TAG        v3.2.0
)

# Make the cxxopts available
FetchContent_MakeAvailable(cxxopts)

# Specify include directory
include_directories(include)

# List all sources
set(SOURCES
    src/main.cpp
    src/WordCount.cpp)

# Add executable with source files
add_executable(cppwc ${SOURCES})

# Link external libraries
target_link_libraries(cppwc PRIVATE cxxopts)