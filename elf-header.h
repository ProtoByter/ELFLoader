#pragma once

#include <stdint.h>

enum ELF_Executable_Type
{
    ELF_Executable_Type_None,
    ELF_Executable_Type_Relocatable,
    ELF_Executable_Type_Executable,
    ELF_Executable_Type_Dynamic,
    ELF_Executable_Type_Core,
};

enum ELF_Machine_Type // TODO: remove unused (SPARC, MIPS, SuperH, IA-64 (the others may be supported in the future))
{
    ELF_Machine_Type_None,
    ELF_Machine_Type_SPARC      = 0x02,
    ELF_Machine_Type_i386       = 0x03,
    ELF_Machine_Type_MIPS       = 0x08,
    ELF_Machine_Type_PowerPC    = 0x14,
    ELF_Machine_Type_ARM        = 0x28,
    ELF_Machine_Type_SUPERH     = 0x2a,
    ELF_Machine_Type_IA_64      = 0x32,
    ELF_Machine_Type_AMD64      = 0x3e,
    ELF_Machine_Type_AArch64    = 0xb7,
    ELF_Machine_Type_RISC_V     = 0xf3
};

enum ELF_Version
{
    ELF_Version_None,
    ELF_Version_Current
};

enum ELF_Class
{
    ELF_Class_None,
    ELF_Class_32,
    ELF_Class_64
};

enum ELF_Data_Encoding
{
    ELF_Data_Encoding_None,
    ELF_Data_Encoding_Little,
    ELF_Data_Encoding_Big
};

typedef struct ELF_Header_64
{
    uint8_t     magic[4];
    uint8_t     _class;
    uint8_t     data_encoding;
    uint16_t    type;
    uint16_t    machine;
    uint32_t    version;
    uint64_t    entrypoint;
    uint64_t    program_header_offset;
    uint64_t    section_header_offset;
    uint32_t    flags;
    uint16_t    header_size;
    uint16_t    program_header_entry_size;
    uint16_t    program_header_entry_count;
    uint16_t    section_header_entry_size;
    uint16_t    section_header_entry_count;
    uint16_t    section_header_index;
} ELF_Header_64;


// Functions to build the header structures above

#include <stdio.h>

int getELFClass(FILE* file);

int getELFFormat(FILE* file);

ELF_Header_64 getHeaderLong(FILE* file);