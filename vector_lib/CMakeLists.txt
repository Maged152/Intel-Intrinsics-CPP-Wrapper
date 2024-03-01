cmake_minimum_required (VERSION 3.2)
project (shakhbat_vector CXX) 


  # Add AVX-512 flags if supported
 #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Qavx512")
  

# Source files
file(GLOB_RECURSE SOURCES source/*.cpp )

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/package)
install(DIRECTORY include DESTINATION ${CMAKE_SOURCE_DIR}/package)
