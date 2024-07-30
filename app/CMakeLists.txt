# Application CMakeList.txt
cmake_minimum_required (VERSION 3.12)

# Sources files
add_executable (${CMAKE_PROJECT_NAME} "Main.cpp")

# Add library
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)

# installation
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
