#include <stdio.h>
#include "elf-header.h"

ELF_Header_64 getHeaderLong(FILE* file) {
  ELF_Header_64 hdr;
  fseek(file,0,SEEK_SET);
  fread(&hdr, 1, sizeof(ELF_Header_64), file);
  return hdr;
}