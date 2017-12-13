#include "Exec.h"

int Exec_load_ins(WindCell* cell, unsigned char* data)
{
        switch(*data)
        {
        case WindInstruc_Add:
                cell->ins = WindInstruc_Add;
                return 1;
        default:
                return 0;
        }
        return 0;
}

void Exec_code(unsigned char* begin, unsigned char* end)
{
        WindCell* curCell = WindTuring_head();
        unsigned char* reader = begin;
        ExecState state = ExecState_Go;
        while(state)
        {
                if(!Exec_load_ins(curCell, reader))
                {
                        fprintf(stderr, "%s\n", "Exec Error: Invalid instruction for op.");
                        exit(1);
                }
                // Load the instruction into the baseCell;
                // Based on Instruction, determine to load first object into the cell.
                // executate the cell
        }

}
