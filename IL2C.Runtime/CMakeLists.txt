cmake_minimum_required (VERSION 3.8)

project(IL2C.Runtime C)

add_definitions(-DIL2C_USE_RUNTIME_DEBUG_LOG)

add_subdirectory(include)
add_subdirectory(src)
