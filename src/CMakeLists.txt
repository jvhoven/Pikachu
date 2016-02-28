file(GLOB_RECURSE entities entities/*.cpp)
file(GLOB_RECURSE items items/*.cpp)
file(GLOB_RECURSE objects objects/*.cpp)

add_library(src ${entities} ${items} ${objects})
