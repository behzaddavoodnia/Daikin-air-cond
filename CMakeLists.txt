cmake_minimum_required(VERSION 3.14)
project(daikin_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

FetchContent_MakeAvailable(googletest)


#add_library(myLib STATIC air_cond.cpp)
add_library(myLib SHARED air_cond.cpp)


add_executable(mainApp main.cpp)
target_link_libraries(mainApp myLib)

# testing
enable_testing()

add_executable(testApp testApp.cpp)
target_link_libraries(testApp myLib gtest_main gmock_main)

