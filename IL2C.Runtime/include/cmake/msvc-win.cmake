cmake_minimum_required (VERSION 3.8)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

add_definitions(-D_WIN32)
add_definitions(-D_LIB)
add_definitions(-DWIN32_LEAN_AND_MEAN)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS_GLOBALS)

include(ProcessorCount)
ProcessorCount(pc)
math(EXPR pc2 "${pc}*2")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /EHa /GF /Gy /Zi /utf-8 /wd4100 /wd4197 /wd4206 /MP${pc2}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Od /Ob0 /Oi /RTC1 /GR /sdl /MTd -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Ox /GL /GS /sdl- /MT -DNDEBUG")

set(CMAKE_STATIC_LINKER_FLAGS "/ignore:4221")
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "/LTCG")

set(CMAKE_EXE_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

set(CMAKE_SHARED_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../lib/libil2c-msvc-win-x64.a)
