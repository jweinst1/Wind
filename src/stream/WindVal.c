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

int WindVal_apply_not(unsigned char** item)
{
        switch(**item)
        {
        case WindType_Bool:
                (*item)[1] = !((*item)[1]);
                *item += 2;
                return 1;
        default:
                // If type is not bool, writes a false boolean. may change this.
                (*item)[0] = WindType_Bool;
                (*item)[1] = 0;
                *item += 2;
                return 1;
        }
}
