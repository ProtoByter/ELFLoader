#include <stdlib.h>
#include <stdio.h>
#include "elf-defines.h"
#include "elf-header.h"


int parse_elf(char* filename) {
  FILE* elf_file = fopen(filename,"r");
  if (getELFClass(elf_file) != ELFCLASS64) {
    printf("This tool can only run 64bit ELF binaries\n");
    return -2;
  }
  if (getELFFormat(elf_file) != ELFDATA2LSB) {
    printf("This tool can only run 64bit *LSB* ELF binaries\n");
    return -3;
  }
  Elf64_Ehdr header = getHeaderLong(elf_file);
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