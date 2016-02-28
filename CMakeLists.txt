#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(game CXX)
include(CTest)

# configure test
if(BUILD_TESTING)
  enable_testing()
  add_subdirectory("${PROJECT_SOURCE_DIR}/test")
  add_test(NAME unitTest COMMAND Test)
endif()

# C++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()


# Include directories
include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/lib" "${PROJECT_SOURCE_DIR}/src")

# Subdirectories
add_subdirectory("${PROJECT_SOURCE_DIR}/lib")
add_subdirectory("${PROJECT_SOURCE_DIR}/src")

# Define sources and executable
set(EXECUTABLE_NAME "game")
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} pikachu src)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
