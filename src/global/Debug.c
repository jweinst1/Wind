#include "Debug.h"

void Debug_obj(WindObject* wobj)
{
        Debug_START;
        puts("Error: ");
        if(wobj->error.active) printf("-> %s\n", wobj->error.mes);
        else puts(" -> No Error");

        puts("Current State: ");
        switch(wobj->state)
        {
        case WindState_Transition:
                puts("-> Transition");
                break;
        case WindState_Execution:
                puts("-> Execution");
                break;
        case WindState_Translate:
                puts("-> Translation");
                break;
        case WindState_Done:
                puts("-> Done");
                break;
        }
        puts("...................");
        printf("Ins Buffer Space = %lu;\n", WindObject_IB_SPACE(wobj));
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
                case WindInstruc_Sub:
                        puts("-;");
                        insPtr++;
                        break;
                case WindInstruc_Mul:
                        puts("*;");
                        insPtr++;
                        break;
                case WindInstruc_Div:
                        puts("/;");
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
        puts("}\n................");
        puts("Object: ");
        switch(wobj->type)
        {
        case WindType_None:
                printf("Type = None;\n");
                break;
        case WindType_Str:
                printf("Type = Str;\n");
                printf("str: \"%.*s\";\n", (int)(wobj->value._str.end - wobj->value._str.begin), wobj->value._str.begin);
                printf("size: %lu;\n", (wobj->value._str.end - wobj->value._str.begin));
                break;
        case WindType_Int:
                printf("Type = Int;\n");
                printf("Value = %ld;\n", wobj->value._int);
                break;
        }
        Debug_END;

}
