cmake_minimum_required (VERSION 3.2)
project (shakhbat_vector CXX) 
  
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory (AVX)

install(DIRECTORY common DESTINATION ${CMAKE_SOURCE_DIR}/package)
