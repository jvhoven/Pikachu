file(GLOB_RECURSE sources system/*.cpp)

add_library(src ${sources})
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)
