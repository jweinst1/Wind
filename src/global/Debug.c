#include "Debug.h"

void Debug_obj(WindObject* wobj)
{
        Debug_START;
        puts("Error: ");
        if(wobj->error.active) printf("%s\n", wobj->error.mes);
        else puts("No Error");
        puts("Instructions: ");
        puts("{");
        unsigned char* insPtr = wobj->instructions;
        while(insPtr != wobj->insMark)
        {
                switch(*insPtr)
                {
                case WindInstruc_Stop:
                        puts("Stop;");
                        insPtr++;
                        break;
                case WindInstruc_In:
                        puts("In;");
                        insPtr++;
                        break;
                case WindInstruc_Out:
                        puts("Out;");
                        insPtr++;
                        break;
                case WindInstruc_Nil:
                        puts("Nil;");
                        insPtr++;
                        break;
                case WindInstruc_Add:
                        puts("+;");
                        insPtr++;
                        break;
                case WindInstruc_Int:
                        insPtr++;
                        printf("int: %ld;\n", *(long*)insPtr);
                        insPtr += sizeof(long);
                        break;
                case WindInstruc_Str:
                        insPtr++;
                        printf("str: \"%.*s\";\n", (int)(*(size_t*)insPtr), (insPtr + sizeof(size_t)));
                        insPtr += (*(size_t*)insPtr) + sizeof(size_t);
                        break;
                default:
                        printf("Invalid Instruction: %u;\n", *insPtr++);
                }
        }
        puts("}");
        Debug_END;
}
