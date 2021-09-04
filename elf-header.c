#include <stdio.h>
#include "elf-header.h"

int getELFClass(FILE* file) {
  fseek(file,sizeof(uint8_t)*4,SEEK_SET);
  uint8_t ei_class;
  fread(&ei_class,1,sizeof(uint8_t),file);
  return ei_class;
}

int getELFFormat(FILE* file) {
  fseek(file,sizeof(uint8_t)*5,SEEK_SET);
  uint8_t ei_data_fmt;
  fread(&ei_data_fmt,1,sizeof(uint8_t),file);
  return ei_data_fmt;
}

ELF_Header_64 getHeaderLong(FILE* file) {
  ELF_Header_64 hdr;
  fseek(file,0,SEEK_SET);
  fread(hdr.magic, 4, 1, file);
  fread(&hdr._class, 1, sizeof(uint8_t), file);
  fread(&hdr.data_encoding, 1, sizeof(uint8_t), file);
  fread(&hdr.version, 1, sizeof(uint32_t), file);
  fseek(file,16,SEEK_SET);
  fread(&hdr.type,1,sizeof(uint16_t), file);
  fread(&hdr.machine,1,sizeof(uint16_t), file);
  fread(&hdr.version,1,sizeof(uint32_t), file);
  fread(&hdr.entrypoint,1,sizeof(uint64_t), file);
  fread(&hdr.program_header_offset,1,sizeof(uint64_t), file);
  fread(&hdr.section_header_offset,1,sizeof(uint64_t), file);
  fread(&hdr.flags,1,sizeof(uint32_t), file);
  fread(&hdr.header_size,1,sizeof(uint16_t),file);
  fread(&hdr.program_header_entry_size,1,sizeof(uint16_t),file);
  fread(&hdr.program_header_entry_count,1,sizeof(uint16_t),file);
  fread(&hdr.section_header_entry_size,1,sizeof(uint16_t),file);
  fread(&hdr.section_header_entry_count,1,sizeof(uint16_t),file);
  fread(&hdr.section_header_index,1,sizeof(uint16_t),file);
  return hdr;
}