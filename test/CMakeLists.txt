cmake_minimum_required(VERSION 3.14)
project(copaTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories( "../include" "../src" )

file( GLOB SOURCES "src/*/*.cpp" "dummy/*/*.cpp" "../src/*/*.cpp" )

add_executable(${CMAKE_PROJECT_NAME}  ${SOURCES})

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  GTest::gmock_main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME})
