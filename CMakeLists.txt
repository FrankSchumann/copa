cmake_minimum_required(VERSION 3.12)

# Set some basic project attributes
project(COPA 
		VERSION 0.0.0.1
		DESCRIPTION "Controller Platform")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#Manually add sources using the set command as follows:
#set( SOURCES "src/*.cpp" "src/plugin/Plugin.cpp" )

file(GLOB SOURCES "src/*.cpp" "src/plugin/*.cpp")

add_executable(copa ${SOURCES})

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(copa PUBLIC "${PROJECT_BINARY_DIR}")

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")
