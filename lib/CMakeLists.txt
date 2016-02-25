file(GLOB_RECURSE system pikachu/system/*.hpp pikachu/system/*.cpp)
file(GLOB_RECURSE base pikachu/base/*.hpp)

add_library(pikachu ${base} ${system})
set_target_properties(pikachu PROPERTIES LINKER_LANGUAGE CXX)
