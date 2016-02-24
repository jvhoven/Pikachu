#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(game CXX)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Include subdirs
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory("${PROJECT_SOURCE_DIR}/lib")
include_directories("${PROJECT_SOURCE_DIR}/src")
add_subdirectory("${PROJECT_SOURCE_DIR}/src")

# Define sources and executable
set(EXECUTABLE_NAME "game")
add_executable(${EXECUTABLE_NAME} main.cc)
target_link_libraries(${EXECUTABLE_NAME} pikachu)

# C++11
set (CMAKE_CXX_STANDARD 11)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
