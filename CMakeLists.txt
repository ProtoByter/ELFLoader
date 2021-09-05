cmake_minimum_required(VERSION 3.0)
project(ELF_Loader)

add_executable(ELFLoader Source/main.c Source/elf-fheader.c Source/elf-pheader.c Source/elf-sheader.c)
target_include_directories(ELFLoader PRIVATE Includes)