
#ifndef WIND_INSTRUCTION_H
#define WIND_INSTRUCTION_H

typedef enum
{
        WindInstruc_Stop,
        WindInstruc_Apply,
        WindInstruc_Int,
        WindInstruc_Add,
        WindInstruc_Sub,
        WindInstruc_Mul,
        WindInstruc_Print,
        WindInstruc_ExpStart,
        WindInstruc_ExpEnd,
        WindInstruc_ListStart,
        WindInstruc_ListEnd,
        WindInstruc_String
} WindInstruc;

#endif
