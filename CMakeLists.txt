cmake_minimum_required(VERSION 3.0.0)
project(kOS.ELFLoader LANGUAGES C VERSION 1.0.0)

# TODO: allow this to be a static / shared library later down the line
add_executable(kOS.ELFLoader
    ${CMAKE_CURRENT_LIST_DIR}/Includes/ELF/ProgramHeader.h
    ${CMAKE_CURRENT_LIST_DIR}/Includes/ELF/SectionHeader.h
    ${CMAKE_CURRENT_LIST_DIR}/Includes/elf.h

    ${CMAKE_CURRENT_LIST_DIR}/Sources/ELF.c
    ${CMAKE_CURRENT_LIST_DIR}/Sources/ProgramHeader.c
    ${CMAKE_CURRENT_LIST_DIR}/Sources/SectionHeader.c

    ${CMAKE_CURRENT_LIST_DIR}/Sources/Main.c
)

target_include_directories(kOS.ELFLoader PRIVATE Includes)

if(WIN32) # TODO: remove later
    target_compile_definitions(kOS.ELFLoader PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
