﻿cmake_minimum_required (VERSION 3.2)
project (shakhbat_avx CXX)

# Source files
file(GLOB_RECURSE SOURCES source/*.cpp )

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/shakhbat_vectorization/AVX)
install(DIRECTORY include DESTINATION ${CMAKE_SOURCE_DIR}/shakhbat_vectorization/AVX)

