#include "Exec.h"
#include "WindInfo.h"

int Exec_load_ins(WindCell* cell, unsigned char** data)
{
        switch(*data)
        {
        case WindInstruc_Add:
                cell->ins = WindInstruc_Add;
                *data += 1;
                return 1;
        case WindInstruc_Int:
                cell->ins = WindInstruc_Int;
                cell->obj.value._int = *(long*)(data + 1);
                *data += 1 + sizeof(long);
                return 1;
        default:
                return 0;
        }
}



void Exec_code(unsigned char* begin, unsigned char* end)
{
        WindInfo info;
        WindCell* curCell = WindTuring_head();
        unsigned char* reader = begin;
        ExecState state = ExecState_Load;
        while(state)
        {
                switch(state)
                {
                case ExecState_Load:
                        Exec_load_ins(curCell, &reader);
                        state = ExecState_NextIns;
                        break;
                }
                /*switch(state)
                   {
                   case ExecState_Load:

                        break;
                   }*/
                /*{
                        fprintf(stderr, "%s\n", "Exec Error: Invalid instruction for op.");
                        exit(1);
                   }*/
                // Load the instruction into the baseCell;
                // Based on Instruction, determine to load first object into the cell.
                // executate the cell
        }

}
