find_package(GTest REQUIRED)

# C++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

# we need to define where the source is once again
include_directories("${GTEST_INCLUDE_DIRS}" "${PROJECT_SOURCE_DIR}/lib" "${PROJECT_SOURCE_DIR}/src")

# add all tests
file(GLOB pikachuTests pikachu/*.cpp)
file(GLOB srcTests src/*.cpp)
add_executable(Test test.cpp ${pikachuTests} ${srcTests})

target_link_libraries(Test
  pikachu
  src
  ${GTEST_LIBRARIES} pthread
)
