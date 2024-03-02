cmake_minimum_required (VERSION 3.2)
project (shakhbat_vector CXX) 
  
add_subdirectory (AVX)

install(DIRECTORY common DESTINATION ${CMAKE_SOURCE_DIR}/package)
