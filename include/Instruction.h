#ifndef WIND_INSTRUCTION_H
#define WIND_INSTRUCTION_H

enum WindInstruc
{
        WindInstruc_Nil, // not a true instruction, for zeroing and errors
        WindInstruc_Stop,
        WindInstruc_In,
        WindInstruc_Out
};

typedef enum WindInstruc WindInstruc;

#endif
