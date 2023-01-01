cmake_minimum_required(VERSION 3.12)

# Set some basic project attributes
project(COPA 
		VERSION 0.0.0.4
		DESCRIPTION "Controller Platform")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(APPLICATION_NAME copa)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

#Shared libraries
set ( PROJECT_LINK_LIBS libOsal.so )
link_directories( ./lib )

add_executable(${APPLICATION_NAME} ${SOURCES})
target_link_libraries(${APPLICATION_NAME} ${PROJECT_LINK_LIBS} -ldl)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(copa PUBLIC "${PROJECT_BINARY_DIR}" include)

set_target_properties( copa PROPERTIES ENABLE_EXPORTS 1 )

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")
