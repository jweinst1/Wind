#include "IntMap.h"

unsigned char IntMap_add(IntMap* imap, const char* string)
{
        // Checks if map is full.
        if(imap->count != INT_MAP_LST_LEN)
        {
                int bound = INT_MAP_NAME_LEN - 1;
                char* writer = imap->items[imap->count++].name;
                while(bound--) *writer++ = *string++;
                return imap->count - 1;
        }
        else return INT_MAP_BAD;
}
