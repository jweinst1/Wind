#include "WindVal.h"

int WindVal_copy(unsigned char* dest, const unsigned char* src, int amnt)
{
        while(amnt--)
        {
                switch(*src)
                {
                case WindType_Bool:
                        *dest++ = *src++;
                        *dest++ = *src++;
                        break;
                // single byte wind values
                case WindType_None:
                case WindType_Sep:
                case WindType_Not:
                        *dest++ = *src++;
                        break;
                default:
                        return 0; // error
                }
        }
        return 1;
}
