cmake_minimum_required (VERSION 3.2)
project (AVX512_Example)

add_subdirectory (AVX512)
add_subdirectory (test)


add_executable(run run.cpp)
target_link_libraries(run PUBLIC shakhbat_AVX512)
