#ifndef WIND_INSTRUCTION_H
#define WIND_INSTRUCTION_H

enum WindInstruc
{
        WindInstruc_Nil, // not a true instruction, for zeroing and errors
        WindInstruc_Stop,
        WindInstruc_In,
        WindInstruc_Out,
        WindInstruc_Int,
        WindInstruc_Str,
        WindInstruc_Add,
        WindInstruc_Sub,
        WindInstruc_Mul,
        WindInstruc_Div
};

typedef enum WindInstruc WindInstruc;

#endif
