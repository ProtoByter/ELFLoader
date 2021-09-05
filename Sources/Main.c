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

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int args_count, char** args)
{
    if (args_count < 2)
    {
        printf("Please provide a file.\n");
        return 1;
    }

    FILE* file = fopen(args[1], "r");
    if (file == NULL)
    {
        printf("Failed to open \"%s\": code %d.\n", args[1], errno);
        return 2;
    }

    if (fseek(file, 0, SEEK_END) != 0)
    {
        printf("Failed to seek to the end of \"%s\": code %d.\n", args[1], ferror(file));
        fclose(file);
        return 3;
    }

    int64_t size = (int64_t)ftell(file); // long is 32 bits wide on Windows and 64 bits wide everywhere else, this is just a mess
    if (size < sizeof(ELF_Header))
    {
        printf("Failed to get the full size of \"%s\": code %d\n", args[1], errno);
        fclose(file);
        return 4;
    }

    rewind(file);

    uint8_t* buffer = calloc(size, sizeof(uint8_t));
    if (buffer == NULL)
    {
        printf("Failed to allocate memory.\n");

        fclose(file);

        return 5;
    }

    size_t read_result = fread(buffer, size, 1, file);
    fclose(file);
    if (read_result < 1)
    {
        printf("Failed to read \"%s\": code %d.\n", args[1], ferror(file));
        free(buffer);
        return 5;
    }

    ELF_Header header;
    ELF_Result elf_result = ELF_Read_Header(&header, buffer, size);
    switch (elf_result)
    {
    case ELF_Result_Success:
        break;

    case ELF_Result_Invalid_Data:
        printf("The ELF file \"%s\" contains an invalid header.\n", args[1]);
        free(buffer);
        return 6;

    default:
        printf("Internal Fault: Received result %d when calling ELF_Read_Header (%s | %lld)", elf_result, args[1], size);
        free(buffer);
        return 7;
    }

    // TODO: read other stuff from our buffer

    free(buffer);
    return 0;
}
