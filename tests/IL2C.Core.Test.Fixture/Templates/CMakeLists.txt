cmake_minimum_required (VERSION 3.8)

include(${CMAKE_BINARY_DIR}/../../../../../../../../../IL2C.Runtime/cmake/gcc4-win-mingw32.cmake)

project(test C)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(test ${CMAKE_CURRENT_LIST_DIR}/test.c)
target_link_libraries(test ${IL2C_LIBRARY_NAME})
