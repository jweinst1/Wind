#include "WindVal.h"

int WindVal_print(unsigned char* item)
{
        switch(*item)
        {
        case WindType_None:
                printf("None ");
                break;
        case WindType_Bool:
                item++;
                printf(*item ? "True " : "False ");
                break;
        case WindType_Assign:
                printf("= ");
                break;
        case WindType_Not:
                printf("! ");
                break;
        case WindType_Sep:
                printf("| ");
                break;
        default:
                return 0; // error case.
        }
        return 1;
}

int WindVal_copy(unsigned char** dest, unsigned char** src, int amnt)
{
        unsigned char* writer = *dest;
        unsigned char* reader = *src;
        while(amnt--)
        {
                switch(*reader)
                {
                case WindType_Bool:
                        *writer++ = *reader++;
                        *writer++ = *reader++;
                        break;
                // single byte wind values
                case WindType_None:
                case WindType_Sep:
                case WindType_Not:
                        *writer++ = *reader++;
                        break;
                default:
                        *dest = writer;
                        return 0; // error
                }
        }
        *dest = writer;
        *src = reader;
        return 1;
}

int WindVal_apply_not(unsigned char* item)
{
        switch(*item)
        {
        case WindType_Bool:
                item[1] = !(item[1]);
                return 1;
        default:
                // If type is not bool, writes a false boolean. may change this.
                *item++ = WindType_Bool;
                *item++ = 0;
                return 1;
        }
}

int WindVal_apply_assign(unsigned char* item, unsigned char* inst)
{
        switch(*inst)
        {
        case WindType_None:
                *item = WindType_None;
                return 1;
        case WindType_Not:
        case WindType_Sep:
        case WindType_Assign:
                *item = *inst;
                return 1;
        case WindType_Bool:
                *item = WindType_Bool;
                item[1] = inst[1];
                return 1;
        default:
                return 0;
        }
        return 1;
}

int WindVal_move(unsigned char** item, int amnt)
{
        while(amnt--)
        {
                switch(**item)
                {
                case WindType_Not:
                case WindType_Sep:
                case WindType_Assign:
                case WindType_None:
                        *item += 1;
                        return 1;
                case WindType_Bool:
                        *item += 2;
                        return 1;
                default:
                        // error
                        return 0;
                }
        }
        return 1;
}
