#include "Debug.h"

void Debug_print(unsigned char* start, unsigned char* end)
{
        Debug_HEADER;

        puts("Literal Instructions:");
        unsigned char* insPtr;
        printf("[ ");
        for(insPtr = start; insPtr != end; insPtr++)
        {
                printf("%u ", *insPtr);
        }
        puts("]");
        while(start != end)
        {
                switch(*start)
                {
                case WindInstruc_Stop:
                        puts("Stop;");
                        start++;
                        break;
                case WindInstruc_ExpStart:
                        puts("ExpStart: '(';");
                        start++;
                        break;
                case WindInstruc_ExpEnd:
                        puts("ExpStart: ')';");
                        start++;
                        break;
                case WindInstruc_ListStart:
                        puts("ListStart: '[';");
                        start++;
                        break;
                case WindInstruc_ListEnd:
                        puts("ListEnd: ']';");
                        start++;
                        break;
                case WindInstruc_String:
                        start++;
                        printf("String: '");
                        while(*start != WindInstruc_String)
                        {
                                putc(*start++, stdout);
                        }
                        puts("';");
                        start++;
                        break;
                case WindInstruc_Continue:
                        puts("Continue: '->';");
                        start++;
                        break;
                case WindInstruc_Apply:
                        puts("Apply: '.';");
                        start++;
                        break;
                case WindInstruc_Int:
                        start++;
                        printf("Int: %ld;\n", *(long*)start);
                        start += sizeof(long);
                        break;
                default:
                        printf("Unrecognized Instruction: %u\n;", *start++);
                }
        }
        Debug_FOOTER;
}
