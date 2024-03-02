cmake_minimum_required(VERSION 3.12)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 

add_subdirectory(googletest) 
add_subdirectory(unit_test/AVX)



