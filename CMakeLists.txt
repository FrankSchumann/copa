cmake_minimum_required(VERSION 2.8.12)

project(COPA)

set(CMAKE_BUILD_TYPE Debug)

#Manually add sources using the set command as follows:
#set( SOURCES "src/*.cpp" "src/plugin/Plugin.cpp" )

file(GLOB SOURCES "src/*.cpp" "src/plugin/*.cpp")

add_executable(copa ${SOURCES})
