#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
// Header that contains instruction enums for the Wind language


// This enum contains instructions for Wind Processess
// These act as enumarations over byte code
typedef enum
{
        WindPrcIns_Stop,
        WindPrcIns_End,
        WindPrcIns_Bool,
        WindPrcIns_None,
        WindPrcIns_Add,
        WindPrcIns_Sub
} WindPrcIns;

#endif
