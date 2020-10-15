cmake_minimum_required (VERSION 3.7)

project(Calculator.CMake C)

include(${CMAKE_CURRENT_LIST_DIR}/../../../IL2C.Runtime/cmake/${ARCHITECTURE}.cmake)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../Generated/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../Generated/src)

file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_LIST_DIR}/../Generated/src/*.c")

add_executable(Calculator ${SRCS} main.c)
target_link_libraries(Calculator ${IL2C_LIBRARY_NAME})
