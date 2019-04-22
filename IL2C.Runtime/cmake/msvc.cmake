cmake_minimum_required (VERSION 3.8)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

add_definitions(-DWIN32)
add_definitions(-D_LIB)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS_GLOBALS)

set(CMAKE_C_FLAGS "/wd4100 /wd4197 /wd4206 /MP")
set(CMAKE_STATIC_LINKER_FLAGS "/ignore:4221")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zi /utf-8")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Od /Ob0 /Oi /RTC1 /GR /sdl -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ot /Ob2 /Oi /Oy -DNDEBUG")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
