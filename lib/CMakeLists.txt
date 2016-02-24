file(GLOB_RECURSE sources pikachu/*.hpp)

add_library(pikachu ${sources})
set_target_properties(pikachu PROPERTIES LINKER_LANGUAGE CXX)
