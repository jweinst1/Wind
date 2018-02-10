#include "StringTool.h"

int StringTool_len_to_ch(const char* string, char ch)
{
        int lent = 0;
        while(*string != ch)
        {
                if(*string++ == '\0') return -1;
                else lent++;

        }
        return lent;
}
