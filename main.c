#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "elf-defines.h"
#include "elf-header.h"

int parse_elf(char* filename) {
  FILE* elf_file = fopen(filename,"r");
  Elf64_Ehdr header = getHeaderLong(elf_file);
  Elf64_Char expected_magic[4] = "\x7F""ELF";
  if (memcmp(expected_magic,header.e_magic,4) != 0) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a non-ELF binary)\n");
    return -2;
  }
  if (getELFClass(elf_file) != ELFCLASS64) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a 32bit binary)\n");
    return -3;
  }
  if (getELFFormat(elf_file) != ELFDATA2LSB) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a big endian binary)\n");
    return -4;
  }
  if (header.e_machine != EM_AMD64) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a binary with a completely different architecture)\n");
    return -5;
  }
  printf("Number of segment entries is: %u\nEntry point is %lx\n",header.e_shnum,header.e_entry);
  return 0;
}

int main(int argc, char** argv) {
  if (argc > 1) {
    return parse_elf(argv[1]);
  }
  else {
    return -1;
  }
}