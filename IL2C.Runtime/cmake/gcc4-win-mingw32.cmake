cmake_minimum_required (VERSION 3.8)

add_definitions(-DWIN32)
add_definitions(-D_LIB)
add_definitions(-DWIN32_LEAN_AND_MEAN)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g2 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -fomit-frame-pointer -DNDEBUG")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PLATFORM_NAME "mingw64")
else()
    set(PLATFORM_NAME "mingw32")
endif()

set(TARGET_LIBRARY_NAME "il2c-gcc4-win-${PLATFORM_NAME}-${CMAKE_BUILD_TYPE}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../lib/lib${TARGET_LIBRARY_NAME}.a)
