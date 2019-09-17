cmake_minimum_required (VERSION 3.7)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_BUILD_TYPE "${CONFIGURATION}")

add_definitions(-D_WIN32)
add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS_GLOBALS)

include(ProcessorCount)
ProcessorCount(pc)
math(EXPR pc2 "${pc}*2")

set(CMAKE_C_FLAGS "/EHa /GF /Gy /Zi /utf-8 /W4 /WX /wd4100 /wd4197 /wd4206 /wd4127 /MP${pc2}")

if("${RUNTIMELIB}" STREQUAL "rts")
    set(CMAKE_C_FLAGS_DEBUG "/Od /Ob0 /Oi /RTC1 /GR /sdl /MTd -D_DEBUG")           # MTd - Multi threaded debug (static)
    set(CMAKE_C_FLAGS_RELEASE "/Ox /Ot /Ob2 /Oi /Oy /GL /GS /sdl- /MT -DNDEBUG")   # MT  - Multi threaded (static)
else()
    set(CMAKE_C_FLAGS_DEBUG "/Od /Ob0 /Oi /RTC1 /GR /sdl /MDd -D_DEBUG")           # MDd - Multi threaded debug DLL
    set(CMAKE_C_FLAGS_RELEASE "/Ox /Ot /Ob2 /Oi /Oy /GL /GS /sdl- /MD -DNDEBUG")   # MD  - Multi threaded DLL
endif()

set(CMAKE_STATIC_LINKER_FLAGS "/ignore:4221")
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "/LTCG")

set(CMAKE_EXE_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

set(CMAKE_SHARED_LINKER_FLAGS "/OPT:ICF /OPT:REF /INCREMENTAL:NO /DEBUG /MAP /MERGE:.rdata=.text")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/RELEASE /LTCG")

if("${PLATFORM}" STREQUAL "Win32")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:SSE2")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH")
endif()

set(IL2C_LIBRARY_NAME_BASE "il2c-msvc-win-${PLATFORM}-${RUNTIMELIB}")
set(IL2C_LIBRARY_NAME "lib${IL2C_LIBRARY_NAME_BASE}.lib")

set(TARGET_LIBRARY_NAME "lib${IL2C_LIBRARY_NAME_BASE}")

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/${CONFIGURATION})
