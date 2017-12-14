#include "Exec.h"

int Exec_is_nested(unsigned char* data)
{
        switch(*data)
        {
        case WindInstruc_Stop:
                return 0;
        case WindInstruc_Int:
                data += sizeof(unsigned char) + sizeof(long);
                switch(*data)
                {
                case WindInstruc_Apply:
                        return 1;
                default:
                        return 0;
                }
                break;
        case WindInstruc_Add:
        case WindInstruc_Print:
                return 1;
        default:
                return 0; // needs error handled
        }
}

int Exec_load(WindCell* cell, unsigned char** data)
{
        switch(**data)
        {
        case WindInstruc_Add:
                cell->ins = WindInstruc_Add;
                cell->obj.type = WindType_None;
                *data += 1;
                return 1;
        case WindInstruc_Print:
                cell->ins = WindInstruc_Print;
                cell->obj.type = WindType_None;
                *data += 1;
                return 1;
        case WindInstruc_Int:
                cell->ins = WindInstruc_Int;
                cell->obj.value._int = *(long*)(data + 1);
                cell->obj.type = WindType_Int;
                *data += 1 + sizeof(long);
                return 1;
        default:
                return 0;
        }
}

// Main function for eval/executing instructions

void Exec_code(unsigned char* begin, unsigned char* end)
{
        WindInfo info;
        WindCell* curCell = WindTuring_head();
        unsigned char* reader = begin;
        goto EXEC_LOAD; // begins chain of execution transitions.

EXEC_ERROR:
        fprintf(stderr, "%s\n", info.err);
        exit(1);
        // responsible for loading an instruction into a cell.
EXEC_LOAD:
        switch(*reader)
        {
        case WindInstruc_Add:
                curCell->ins = WindInstruc_Add;
                curCell->obj.type = WindType_None;
                reader++;
                goto EXEC_EXPSTART;
        case WindInstruc_Print:
                curCell->ins = WindInstruc_Print;
                curCell->obj.type = WindType_None;
                reader++;
        case WindInstruc_Int:
                curCell->ins = WindInstruc_Int;
                curCell->obj.value._int = *(long*)(reader + 1);
                curCell->obj.type = WindType_Int;
                reader += 1 + sizeof(long);
        default:
                goto EXEC_ERROR;
        }
        // checks for exp start instruction, prior to execution.
EXEC_EXPSTART:
        if(*reader == WindInstruc_ExpStart)
        {
                reader++;
                goto EXEC_EVAL;
        }
        else goto EXEC_ERROR;
EXEC_EVAL:
        puts("NA");

}
