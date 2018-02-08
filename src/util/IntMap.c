#include "IntMap.h"

unsigned char IntMap_add(IntMap* imap, const char* string)
{
        // Checks if map is full.
        if(imap->count != INT_MAP_LST_LEN)
        {
                int bound = INT_MAP_NAME_LEN - 1;
                char* writer = imap->items[imap->count++].name;
                while(bound--) *writer++ = *string++;
                *writer = '\0';
                return imap->count - 1;
        }
        else return INT_MAP_BAD;
}

unsigned char IntMap_get(IntMap* imap, const char* string)
{
        const char* cmpKey1;
        const char* cmpKey2;
        for(int i = 0; i < INT_MAP_LST_LEN; i++)
        {
                cmpKey1 = imap->items[i].name;
                cmpKey2 = string;
                while(*cmpKey1 == *cmpKey2)
                {
                        if(*cmpKey1 == '\0' && *cmpKey2 == '\0') return i;
                        else
                        {
                                cmpKey1++;
                                cmpKey2++;
                        }
                }
        }
        return INT_MAP_BAD;
}
