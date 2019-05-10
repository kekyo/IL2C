cmake_minimum_required (VERSION 3.7)

set(CMAKE_BUILD_TYPE "${CONFIGURATION}")

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g2 -Wall -Werror -Wstrict-prototypes -Wno-unused -fdata-sections -ffunction-sections -Wl,--gc-sections")

if("${CONFIGURATION}" STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -flto -fomit-frame-pointer -march=native -DNDEBUG")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -D_DEBUG")
endif()

set(IL2C_LIBRARY_NAME_BASE "il2c-gcc-linux-${PLATFORM}")
set(IL2C_LIBRARY_NAME "lib${IL2C_LIBRARY_NAME_BASE}.a")

set(TARGET_LIBRARY_NAME "${IL2C_LIBRARY_NAME_BASE}-${CONFIGURATION}")

include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/${CONFIGURATION})
