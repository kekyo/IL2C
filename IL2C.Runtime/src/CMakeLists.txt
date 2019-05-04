cmake_minimum_required (VERSION 3.7)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../lib)

add_definitions(-D_LIB)

if(DEFINED BUILD_UEFI)
    enable_language(ASM_MASM)
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c" "*_${PLATFORM}.asm")
else()
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c")
endif()

add_library(${TARGET_LIBRARY_NAME} STATIC ${IL2C_RUNTIME_SRCS})

target_include_directories(${TARGET_LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(${TARGET_LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
