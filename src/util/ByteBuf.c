
#include "ByteBuf.h"

ByteBuf* ByteBuf_new(size_t cap)
{
        ByteBuf* buf = malloc(sizeof(ByteBuf));
        buf->begin = malloc(sizeof(unsigned char) * cap);
        buf->mark = buf->begin;
        buf->end = buf->begin + cap;
        return buf;
}


void ByteBuf_del(ByteBuf* buf)
{
        free(buf->begin);
        free(buf);
}

void ByteBuf_expand(ByteBuf* buf, int factor)
{
        size_t oldLen = ByteBuf_LEN(buf);
        size_t newCap = ByteBuf_CAP(buf) * factor;
        if((buf->begin = realloc(buf->begin, newCap)) != NULL)
        {
                buf->mark = buf->begin + oldLen;
                buf->end = buf->begin + newCap;
        }
        else
        {
                fprintf(stderr, "%s\n", "Cannot expand ByteBuf, out of memory");
                exit(1);
        }
}

void ByteBuf_write_byte(ByteBuf* buf, unsigned char byte)
{
        if(ByteBuf_FULL(buf)) ByteBuf_expand(buf, 2);
        *(buf->mark) = byte;
        buf->mark++;
}

void ByteBuf_write_long(ByteBuf* buf, long num)
{
        if(ByteBuf_SPACE(buf) > sizeof(long)) ByteBuf_expand(buf, 2);
        *(long*)(buf->mark) = num;
        buf->mark += sizeof(long);
}

void ByteBuf_write_data(ByteBuf* buf, void* data, size_t amount)
{
        if(ByteBuf_SPACE(buf) < amount) ByteBuf_expand(buf, 3);
        memcpy(buf->begin, data, amount);
}

void ByteBuf_write_str(ByteBuf* buf, char** string, unsigned char bound)
{
        if(ByteBuf_FULL(buf)) ByteBuf_expand(buf, 2);
        *(buf->mark) = bound;
        buf->mark++;
        while(**string)
        {
                if(**string == '"')

                {
                        *string += 1;
                        if(ByteBuf_FULL(buf)) ByteBuf_expand(buf, 2);
                        *(buf->mark) = bound;
                        buf->mark++;
                        return;
                }
                else
                {
                        if(ByteBuf_FULL(buf)) ByteBuf_expand(buf, 2);
                        *(buf->mark) = **string;
                        buf->mark++;
                        *string += 1;
                }
        }
        fprintf(stderr, "%s\n", "String Error: Found null char inside string literal.");
}

void ByteBuf_to_file(ByteBuf* buf, const char* name)
{
        size_t fileSize = ByteBuf_LEN(buf);
        FILE* writePtr;
        writePtr = fopen(name, "wb");
        if(writePtr == NULL)
        {
                fprintf(stderr, "IO Error: Cannot open file '%s'\n", name);
                exit(1);
        }
        fwrite(&fileSize, sizeof(size_t), 1, writePtr);
        fseek(writePtr, sizeof(size_t), SEEK_SET);
        fwrite(buf->begin, fileSize, 1, writePtr);
        fclose(writePtr);
}
