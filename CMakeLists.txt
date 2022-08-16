cmake_minimum_required(VERSION 3.10)

project(BreakOut)

add_definitions("-Wall -g")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${CMAKE_SOURCE_DIR}/utility"
					"${CMAKE_SOURCE_DIR}/libs" 
					"${CMAKE_SOURCE_DIR}/libs/GLFW/include" 
					"${CMAKE_SOURCE_DIR}/src"
					"${CMAKE_SOURCE_DIR}/libs/glad/include"
					"${CMAKE_SOURCE_DIR}/libs/stb"
					"/usr/local/Cellar/freetype/2.12.1/include/freetype2/")

link_directories("${CMAKE_SOURCE_DIR}/libs/GLFW/lib"
				 "/usr/local/Cellar/freetype/2.12.1/lib/")

aux_source_directory("${CMAKE_SOURCE_DIR}/utility" UTILITY)
aux_source_directory("${CMAKE_SOURCE_DIR}/libs/stb" STB)
aux_source_directory("${CMAKE_SOURCE_DIR}/src" SRC)

aux_source_directory("${CMAKE_SOURCE_DIR}/libs/glad/src" GLAD)
add_library(libglad ${GLAD})

add_executable(${PROJECT_NAME} ${SRC} ${UTILITY} ${STB})

target_link_libraries(${PROJECT_NAME} libglad libglfw.3.dylib libfreetype.6.dylib)