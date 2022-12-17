cmake_minimum_required(VERSION 2.8.12)

project(COPA)

set(CMAKE_BUILD_TYPE Debug)

#Manually add sources using the set command as follows:
# set( SOURCES src/main.cpp src/Component/Manager.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(copa ${SOURCES})
