cmake_minimum_required(VERSION 3.10)

project(BreakOut)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${CMAKE_SOURCE_DIR}/utility"
					"${CMAKE_SOURCE_DIR}/libs" 
					"${CMAKE_SOURCE_DIR}/libs/GLFW/include" 
					"${CMAKE_SOURCE_DIR}/src"
					"${CMAKE_SOURCE_DIR}/libs/glad/include"
					"${CMAKE_SOURCE_DIR}/libs/stb")

link_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/lib")

aux_source_directory("${CMAKE_SOURCE_DIR}/utility" UTILITY)
aux_source_directory("${CMAKE_SOURCE_DIR}/libs/stb" STB)
aux_source_directory("${CMAKE_SOURCE_DIR}/src" SRC)

aux_source_directory("${CMAKE_SOURCE_DIR}/libs/glad/src" GLAD)
add_library(libglad ${GLAD})

add_executable(${PROJECT_NAME} ${SRC} ${UTILITY} ${STB})

target_link_libraries(${PROJECT_NAME} libglad libglfw.3.dylib)