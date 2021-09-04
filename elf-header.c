#include <stdio.h>
#include "elf-defines.h"
#include "elf-header.h"

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
  fread(hdr.e_magic, 4, 1, file);
  fread(&hdr.e_class, 1, sizeof(Elf64_Char), file);
  fread(&hdr.e_data_fmt, 1, sizeof(Elf64_Char), file);
  fread(&hdr.e_version, 1, sizeof(Elf64_Char), file);
  fseek(file,16,SEEK_SET);
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