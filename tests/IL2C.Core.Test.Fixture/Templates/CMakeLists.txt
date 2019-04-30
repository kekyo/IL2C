cmake_minimum_required (VERSION 3.8)

include(${CMAKE_BINARY_DIR}/../../../../../../../../../IL2C.Runtime/include/cmake/msvc-win.cmake)

project(test C)

file(GLOB_RECURSE TEST_SRCS "*.c")

target_link_libraries(test il2c)

add_executable(test ${TEST_SRCS})
