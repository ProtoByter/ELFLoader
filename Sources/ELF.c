#include <ELF.h>

#include <string.h>

ELF_Result ELF_Read_Header(ELF_Header* header, uint8_t* buffer, size_t length)
{
    if (header == NULL || buffer == NULL || length < sizeof(ELF_Header)) return ELF_Result_Invalid_Arguments;

    ELF_Header header_internal;
    memcpy(&header_internal, buffer, sizeof(ELF_Header));

    // TODO: verify integrity

    memcpy(header, &header_internal, sizeof(ELF_Header));
    return ELF_Result_Success;
}
