#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "elf-header.h"

int parse_elf(char* filename) {
  FILE* elf_file = fopen(filename,"r");
  ELF_Header_64 header = getHeaderLong(elf_file);
  uint8_t expected_magic[4] = "\x7F""ELF";
  if (memcmp(expected_magic,header.magic,4) != 0) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a non-ELF binary)\n");
    return -2;
  }
  if (getELFClass(elf_file) != ELF_Class_64) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a 32bit binary)\n");
    return -3;
  }
  if (getELFFormat(elf_file) != ELF_Data_Encoding_Little) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a big endian binary)\n");
    return -4;
  }
  if (header.machine != ELF_Machine_Type_AMD64) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a binary with a completely different architecture)\n");
    return -5;
  }
  if (header.type != ELF_Executable_Type_Executable) {
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a file which isn't an excutable)\n");
  }
  printf("Number of segment entries is: %u\nEntry point is 0x%lx\n",header.section_header_entry_count,header.entrypoint);
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