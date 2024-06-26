cmake_minimum_required(VERSION 3.5)
project(P4 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the image library
ADD_SUBDIRECTORY(lib)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

# build the compare program
ADD_EXECUTABLE(compare compare.cpp)
TARGET_LINK_LIBRARIES(compare image)

set(QUEUE_SOURCE
  list.hpp list.tpp queue.hpp queue.tpp)

if(EXISTS "${PROJECT_SOURCE_DIR}/Node.tpp" AND EXISTS "${PROJECT_SOURCE_DIR}/Node.hpp")
    set(QUEUE_SOURCE ${QUEUE_SOURCE} Node.tpp Node.hpp)
endif()

set(TEST_SOURCE
  test_queue.cpp)

set(PATHFINDER_SOURCE pathfinder.cpp problem.hpp problem.tpp)

set(SOURCE ${QUEUE_SOURCE} ${TEST_SOURCE} ${PATHFINDER_SOURCE})

# create unittests
add_executable(test-queue catch.hpp abstract_list.hpp abstract_queue.hpp ${DEQUE_SOURCE} ${TEST_SOURCE})
TARGET_LINK_LIBRARIES(test-queue)

# build executable
add_executable(pathfinder abstract_list.hpp abstract_queue.hpp ${QUEUE_SOURCE} ${PATHFINDER_SOURCE})
TARGET_LINK_LIBRARIES(pathfinder image)

# some simple tests
enable_testing()
add_test(NAME test-queue COMMAND test-queue)
add_test(NAME test00 COMMAND pathfinder ${CMAKE_SOURCE_DIR}/tests/maze00.png output00.png)
add_test(NAME test00-compare COMMAND compare ${CMAKE_SOURCE_DIR}/tests/output00.png output00.png)
add_test(NAME test01 COMMAND pathfinder ${CMAKE_SOURCE_DIR}/tests/maze01.png output01.png)
add_test(NAME test01-compare COMMAND compare ${CMAKE_SOURCE_DIR}/tests/output01.png output01.png)
add_test(NAME test02 COMMAND pathfinder ${CMAKE_SOURCE_DIR}/tests/maze02.png output02.png)
add_test(NAME test02-compare COMMAND compare ${CMAKE_SOURCE_DIR}/tests/output02.png output02.png)
set_tests_properties(test00 test00-compare test01 test01-compare test02 test02-compare PROPERTIES RUN_SERIAL TRUE)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/p4_pathfinder.zip" --format=zip
  ${SOURCE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
