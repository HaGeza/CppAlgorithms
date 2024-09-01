file(GLOB_RECURSE SRC_FILES "*.cpp")
add_library(Library SHARED ${SRC_FILES})