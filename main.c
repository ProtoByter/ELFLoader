#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "elf-header.h"

void print_error(const char* reason) {
  printf("This tool can only run AMD64 LSB ELF binaries (%s)\n", reason);
}

int parse_elf(char* filename) {
  FILE* elf_file = fopen(filename,"r");
  ELF_Header_64 header = getHeaderLong(elf_file);
  uint8_t expected_magic[4] = "\x7F""ELF";
  if (memcmp(expected_magic,header.magic,4) != 0) {
    print_error("you provided a non-ELF binary");
    return -2;
  }
  if (header._class != ELF_Class_64) {
    print_error("you provided a non-ELF binary");
    printf("This tool can only run AMD64 LSB ELF binaries (you provided a 32bit binary)\n");
    return -3;
  }
  if (header.data_encoding != ELF_Data_Encoding_Little) {
    print_error("you provided a big endian binary");
    return -4;
  }
  if (header.machine != ELF_Machine_Type_AMD64) {
    print_error("you provided a binary with a completely different architecture");
    return -5;
  }
  if (header.type != ELF_Executable_Type_Executable) {
    print_error("you provided a file which isn't an executable");
    return -6;
  }
  if (header.abi != ELF_ABI_SYSV) {
    printf("%i",header.abi);
    print_error("you provided a binary with an ABI other than sysv");
    return -7;
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