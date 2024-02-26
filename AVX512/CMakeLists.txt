cmake_minimum_required (VERSION 3.2)
project (shakhbat_AVX512 CXX)

# Source files
file(GLOB_RECURSE SOURCES vector/source/*.cpp scalar/source/*.cpp)

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC vector/include scalar/include)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/package)
install(DIRECTORY include DESTINATION ${CMAKE_SOURCE_DIR}/package)
