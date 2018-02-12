#ifndef WIND_TYPES_H
#define WIND_TYPES_H
// This header contains various enum types used to select bytes in Wind.

// This enum enumerates the type marks for objects in binary format.
typedef enum
{
        WindObjType_None,
        WindObjType_Bool,
        WindObjType_Int,
        WindObjType_Instruction // Used for compiler
} WindObjType;

// This enum enumerates byte code compiled from the Wind language's source code.
typedef enum
{
        WindIns_Stop,
        WindIns_Push,
        WindIns_Out
} WindIns;



#endif
