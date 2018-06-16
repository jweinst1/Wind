#include "DataUtil.h"

unsigned long DataUtil_copy(unsigned char* dest,
                            const unsigned char* src,
                            const unsigned char* srcEnd,
                            int* err)
{
        unsigned stringMove = 0;
        unsigned char* startDest = dest;
        while(src != srcEnd)
        {
                switch(*src)
                {
                case WindType_Not:
                case WindType_Sep:
                case WindType_Assign:
                case WindType_None:
                case WindType_Del:
                case WindType_Lt:
                case WindType_Gt:
                case WindType_Plus:
                case WindType_Minus:
                case WindType_Multiply:
                case WindType_Divide:
                        *dest++ = *src++;
                        break;
                case WindType_Bool:
                        *dest++ = *src++;
                        *dest++ = *src++;
                        break;
                case WindType_Number:
                        *dest++ = *src++;
                        for(size_t ds = 0; ds < sizeof(double); ds++) *dest++ = *src++;
                        break;
                case WindType_String:
                        *dest++ = *src++;
                        stringMove = *(unsigned*)(src) + sizeof(unsigned);
                        while(stringMove--) *dest++ = *src++;
                        break;
                default:
                        // Error, unrecognized marker
                        *err = 0;
                        return 0;
                }
        }
        *err = 1;
        return dest - startDest;
}

int DataUtil_validate(const unsigned char* start, const unsigned char* end)
{
        unsigned stringMove = 0;
        while(start != end)
        {
                switch(*start)
                {
                case WindType_Not:
                case WindType_Sep:
                case WindType_Assign:
                case WindType_None:
                case WindType_Del:
                case WindType_Lt:
                case WindType_Gt:
                case WindType_Plus:
                case WindType_Minus:
                case WindType_Multiply:
                case WindType_Divide:
                        start++;
                        break;
                case WindType_Bool:
                        start += 2;
                        break;
                case WindType_Number:
                        start += sizeof(unsigned char) + sizeof(double);
                        break;
                case WindType_String:
                        start++;
                        stringMove = *(unsigned*)(start) + sizeof(unsigned);
                        start += stringMove;
                        break;
                default:
                        return 0;
                }
        }
        return 1;
}
