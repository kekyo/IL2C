cmake_minimum_required (VERSION 3.7)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

if(DEFINED BUILD_UEFI)
    enable_language(ASM_MASM)
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c" "*_${PLATFORM}.asm")
else()
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c")
endif()

add_library(${IL2C_LIBRARY_NAME} STATIC ${IL2C_RUNTIME_SRCS})

target_include_directories(${IL2C_LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${IL2C_LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
