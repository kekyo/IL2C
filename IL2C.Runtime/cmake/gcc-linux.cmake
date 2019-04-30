cmake_minimum_required (VERSION 3.7)

set(CMAKE_BUILD_TYPE, "${CONFIGURATION}")

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g2 -fdata-sections -ffunction-sections -Wl,--gc-sections")

if("${CONFIGURATION}" STREQUAL "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -D_DEBUG")
else()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -flto -fomit-frame-pointer -DNDEBUG")
endif()

set(IL2C_LIBRARY_NAME_BASE "il2c-gcc-linux-${PLATFORM}")
set(IL2C_LIBRARY_NAME "${IL2C_LIBRARY_NAME_BASE}-${CONFIGURATION}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/lib${IL2C_LIBRARY_NAME}.a)
