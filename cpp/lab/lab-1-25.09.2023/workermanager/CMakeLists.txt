cmake_minimum_required(VERSION 3.25)
project(workermanager)

set(CMAKE_CXX_STANDARD 17)

set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dep)

add_subdirectory(${DEPENDENCIES_DIR}/CLI11)

add_executable(workermanager main.cpp)

target_link_libraries(workermanager PRIVATE CLI11)

