#ifndef H_ELF_DEFS
#define H_ELF_DEFS

// EIDENT offsets

#define EI_MAG0 0
#define EI_MAG1 1
#define EI_MAG2 2
#define EI_MAG3 3
#define EI_CLASS 4
#define EI_DATA 5
#define EI_VERSION 6
#define EI_PAD 7
#define EI_NIDENT 16

// Exectuable Types

#define ET_NONE 0
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define ET_CORE 4
#define ET_LOPROC 0xff00
#define ET_HIPROC 0xffff

// Machine types

#define EM_NONE 0
#define EM_M32 1
#define EM_SPARC 2
#define EM_386 3
#define EM_68K 4
#define EM_88K 5
#define EM_860 7
#define EM_EMIPS 8
#define EM_PPC 0x14
#define EM_ARM 0x28
#define EM_SUPERH 0x2A
#define EM_IA64 0x32
#define EM_AMD64 0x3E
#define EM_AARCH64 0xB7
#define EM_RISCV 0xF3

// ELF Version

#define EV_NONE 0
#define EV_CURRENT 1

// ELF Class

#define ELFCLASSNONE 0
#define ELFCLASS32 1
#define ELFCLASS64 2

// ELF Data encodings

#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

// Types

#include <stdint.h>

#define Elf64_Addr uint64_t
#define Elf64_Half uint16_t
#define Elf64_Off uint64_t
#define Elf64_Sword int32_t
#define Elf64_Word uint32_t
#define Elf64_Sxword int64_t
#define Elf64_Xword uint64_t
#define Elf64_Char uint8_t

#endif