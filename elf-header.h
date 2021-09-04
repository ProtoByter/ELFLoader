#ifndef H_ELF_HDEFS
#define H_ELF_HDEFS

#include "elf-defines.h"

// 64 bit

typedef struct {
  Elf64_Char e_ident[EI_NIDENT];
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

// 32 bit

typedef struct {
  Elf32_Char e_ident[EI_NIDENT];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

// Functions to build the header structures above

#include <stdio.h>

int getELFClass(FILE* file) {
  fseek(file,sizeof(Elf64_Char)*EI_CLASS,SEEK_SET);
  Elf64_Char ei_class;
  fread(&ei_class,1,sizeof(Elf64_Char),file);
  return ei_class;
}

int getELFFormat(FILE* file) {
  fseek(file,sizeof(Elf64_Char)*EI_DATA,SEEK_SET);
  Elf64_Char ei_data_fmt;
  fread(&ei_data_fmt,1,sizeof(Elf64_Char),file);
  return ei_data_fmt;
}

Elf64_Ehdr getHeaderLong(FILE* file) {
  Elf64_Ehdr hdr;
  fseek(file,0,SEEK_SET);
  fread(hdr.e_ident, 16, 1, file);
  fread(&hdr.e_type,1,sizeof(Elf64_Half), file);
  fread(&hdr.e_machine,1,sizeof(Elf64_Half), file);
  fread(&hdr.e_version,1,sizeof(Elf64_Word), file);
  fread(&hdr.e_entry,1,sizeof(Elf64_Addr), file);
  fread(&hdr.e_phoff,1,sizeof(Elf64_Off), file);
  fread(&hdr.e_shoff,1,sizeof(Elf64_Off), file);
  fread(&hdr.e_flags,1,sizeof(Elf64_Word), file);
  fread(&hdr.e_ehsize,1,sizeof(Elf64_Half),file);
  fread(&hdr.e_phentsize,1,sizeof(Elf64_Half),file);
  fread(&hdr.e_phnum,1,sizeof(Elf64_Half),file);
  fread(&hdr.e_shentsize,1,sizeof(Elf64_Half),file);
  fread(&hdr.e_shnum,1,sizeof(Elf64_Half),file);
  fread(&hdr.e_shstrndx,1,sizeof(Elf64_Half),file);
  return hdr;
}

#endif