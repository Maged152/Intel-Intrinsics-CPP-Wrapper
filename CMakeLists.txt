cmake_minimum_required (VERSION 3.2)
project (vector_Example)

add_subdirectory (vector_lib)
add_subdirectory (test)

add_executable(run run.cpp)
target_link_libraries(run PUBLIC shakhbat_vector)
