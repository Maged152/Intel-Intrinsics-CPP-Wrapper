cmake_minimum_required(VERSION 3.12)
project(avx_test)

# Find all test source files
file(GLOB_RECURSE TEST_SOURCES *.cpp)

# Create a target for each test file
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} shakhbat_avx gtest_main) # Link with Google Test and pthread
    target_include_directories(${TEST_NAME} 
        PRIVATE ../include
        PRIVATE ${GTEST_INCLUDE_DIRS})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME}) # Register the test with CTest
endforeach() 