# Src CMakeList.txt
cmake_minimum_required(VERSION 3.12)

# Set language and the project name
project(${CMAKE_PROJECT_NAME}_lib CXX)

# Other commands
if(FOR_EXAMPLE)
	message("there may be other commands here")
endif()

# Compile library
add_library(${PROJECT_NAME} STATIC Singleton.cpp)

# Include folders
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
