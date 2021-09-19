// Copyright (c) 2021 The kOS authors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software.
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <ELF.h>

#include <string.h>

ELF_Result ELF_Read_Header(ELF_Header* header, uint8_t* buffer, size_t length)
{
    if (header == NULL || buffer == NULL || length < sizeof(ELF_Header_64)) return ELF_Result_Invalid_Arguments;

    ELF_Header internal_header;

    switch (buffer[4]) 
    {
    case ELF_Class_32:
    {
        internal_header.class = ELF_Class_32;
        ELF_Header_32 header32;
        memcpy(&header32, buffer, sizeof(ELF_Header_32));
        internal_header.header_data.Header_32 = header32;
        break;
    }

    case ELF_Class_64:
    {
        internal_header.class = ELF_Class_64;
        ELF_Header_64 header64;
        memcpy(&header64, buffer, sizeof(ELF_Header_64));
        internal_header.header_data.Header_64 = header64;
        break;
    }
    
    default:
        return ELF_Result_Invalid_Data;
    }

    memcpy(header, &internal_header, sizeof(ELF_Header));
    return ELF_Result_Success;
}
