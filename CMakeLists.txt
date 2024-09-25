cmake_minimum_required(VERSION 3.10)
project(CppAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_)

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP True
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(lib)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXXCOMPILER=/usr/bin/clang++")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Debug build: enabling debugging flags")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstandalone-debug -g -glldb -lgtest -lgtest_main -O0 -pthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstandalone-debug -g3 -glldb -lgtest -lgtest_main -O0 -pthread")
endif()
