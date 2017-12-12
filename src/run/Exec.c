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
        WindCell* baseCell = WindTuring_last_move();
        unsigned char* reader = begin;
        ExecState state = ExecState_Go;

}
