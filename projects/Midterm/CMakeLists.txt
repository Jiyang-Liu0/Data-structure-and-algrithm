cmake_minimum_required(VERSION 3.5)
project(lists CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE Pokemon.hpp Bag.hpp Bag.cpp ExamBag.hpp)

add_executable(test-Pokemon catch.hpp ${SOURCE})

enable_testing()


add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem03_lists.zip" --format=zip
       ${SOURCE}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})