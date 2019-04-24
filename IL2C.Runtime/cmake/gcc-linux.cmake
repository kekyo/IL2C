cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE, "${CONFIGURATION}")

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g2 -fdata-sections -ffunction-sections -Wl,--gc-sections")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -fomit-frame-pointer -DNDEBUG")

set(IL2C_LIBRARY_NAME_BASE "il2c-gcc-linux-${PLATFORM}")
set(IL2C_LIBRARY_NAME "${IL2C_LIBRARY_NAME_BASE}-${CONFIGURATION}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/lib${IL2C_LIBRARY_NAME}.a)
