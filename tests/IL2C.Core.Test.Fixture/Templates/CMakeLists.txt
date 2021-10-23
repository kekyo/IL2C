cmake_minimum_required (VERSION 3.8)

include(${CMAKE_CURRENT_LIST_DIR}/../../../../../../IL2C.Runtime/cmake/${CMAKE_TARGET_SCRIPT_NAME})

project(test C)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(test ${CMAKE_CURRENT_LIST_DIR}/test.c)
target_link_libraries(test)
