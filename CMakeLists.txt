# Copyright (c) 2021 The kOS authors.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software.
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.0.0)
project(kOS.ELFLoader LANGUAGES C VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/BuildScripts)
include(SystemCheck)

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
