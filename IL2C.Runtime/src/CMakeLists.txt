cmake_minimum_required (VERSION 3.8)

if(DEFINED BUILD_UEFI)
    enable_language(ASM_MASM)
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c" "*.asm")
else()
    file(GLOB_RECURSE IL2C_RUNTIME_SRCS "*.c")
endif()

add_library(il2c STATIC ${IL2C_RUNTIME_SRCS})

target_include_directories(il2c PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(il2c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
