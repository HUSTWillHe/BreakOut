cmake_minimum_required(VERSION 3.10)

project(BreakOut)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${CMAKE_SOURCE_DIR}/utility")

link_directories("${CMAKE_SOURCE_DIR}/libs")

add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/main.cpp")

# target_link_libraries(${PROJECT_NAME} libglew)