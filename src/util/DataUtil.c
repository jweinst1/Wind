#include "DataUtil.h"

int DataUtil_copy(unsigned char* dest, const unsigned char* src, const unsigned char* srcEnd)
{
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
                        WindComp_BUF[0] = *item++;
                        for(size_t ds = 1; ds < sizeof(double) + 1; ds++)
                                WindComp_BUF[ds] = *item++;
                        WindComp_ITEM_LEN = sizeof(unsigned char) + sizeof(double);
                        return WindComp_ITEM_LEN;
                case WindType_String:
                        WindComp_BUF[0] = *item++;
                        WindComp_ITEM_LEN = *(unsigned*)(item) + sizeof(unsigned) + sizeof(unsigned char);
                        memcpy(WindComp_BODY, (unsigned char*)item, WindComp_ITEM_LEN);
                        return WindComp_ITEM_LEN;
                default:
                        return 0;
                }
        }
        return 1;
}
