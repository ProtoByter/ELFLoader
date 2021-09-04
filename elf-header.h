#ifndef H_ELF_HDEFS
#define H_ELF_HDEFS

#include "elf-defines.h"

typedef struct {
  Elf64_Char e_magic[4];
  Elf64_Char e_class;
  Elf64_Char e_data_fmt;
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;

// Functions to build the header structures above

#include <stdio.h>

int getELFClass(FILE* file);

int getELFFormat(FILE* file);

Elf64_Ehdr getHeaderLong(FILE* file);

#endif