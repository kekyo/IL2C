cmake_minimum_required (VERSION 3.8)

set(CMAKE_SYSTEM_NAME Generic)

add_definitions(-DWIN32)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g2 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -fomit-frame-pointer -DNDEBUG")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
