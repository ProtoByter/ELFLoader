cmake_minimum_required(VERSION 3.0.0)
project(ELFLoader LANGUAGES C VERSION 1.0.0)

add_executable(ELFLoader
    ${CMAKE_CURRENT_LIST_DIR}/Includes/ELF/ProgramHeader.h
    ${CMAKE_CURRENT_LIST_DIR}/Includes/ELF/SectionHeader.h
    ${CMAKE_CURRENT_LIST_DIR}/Includes/ELF.h

    ${CMAKE_CURRENT_LIST_DIR}/Sources/ELF.c
    ${CMAKE_CURRENT_LIST_DIR}/Sources/ProgramHeader.c
    ${CMAKE_CURRENT_LIST_DIR}/Sources/SectionHeader.c

    ${CMAKE_CURRENT_LIST_DIR}/Sources/Main.c
)

target_include_directories(ELFLoader PRIVATE Includes)

if(WIN32) # TODO: remove later
    target_compile_definitions(ELFLoader PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
