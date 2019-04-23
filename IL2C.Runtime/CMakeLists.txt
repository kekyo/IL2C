cmake_minimum_required (VERSION 3.8)

project(IL2C.Runtime C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(include)
add_subdirectory(src)
