cmake_minimum_required(VERSION 3.14)
project(cppwc)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Boost library with the Program Options component
find_package(Boost 1.70 REQUIRED COMPONENTS program_options)

# Check if Boost was found
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found. Please install Boost.")
endif()

# Specify include directory
include_directories(include)

# List all sources
set(SOURCES
    src/main.cpp
    src/WordCount.cpp)

# Add executable with source files
add_executable(cppwc ${SOURCES})

# Link the Boost::program_options library to your target
target_link_libraries(cppwc PRIVATE Boost::program_options)

# Optionally, include Boost's headers
target_include_directories(cppwc PRIVATE ${Boost_INCLUDE_DIRS})