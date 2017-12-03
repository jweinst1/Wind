#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include <stdlib.h>
#include "Instruction.h"
#include "WindStr.h"
#include "WindError.h"

#define WindObject_INS_SIZE 4000
#define WindObject_CODE_SIZE 500

//code buffer space
#define WindObject_CB_SPACE(wobj) wobj->codeEnd - wobj->codeMark

#define WindObject_CB_FULL(wobj) (wobj->codeEnd - wobj->codeMark) == 0

//instruction buffer space
#define WindObject_IB_SPACE(wobj) wobj->insEnd - wobj->insMark

#define WindObject_IB_FULL(wobj) (wobj->insEnd - wobj->insMark) == 0

#define WindObject_INIT(name) \
        WindObject name; \
        name.codeMark = name.code; \
        name.codeEnd = name.codeMark + WindObject_CODE_SIZE; \
        name.insMark = name.instructions; \
        name.insEnd = name.insMark + WindObject_INS_SIZE; \
        name.type = WindType_None; \
        name.state = WindState_Translate; \
        name.error.active = 0; \
        name.curIns = WindInstruc_Nil;

enum WindState
{
        WindState_Translate,
        WindState_Transition,
        WindState_Execution,
        WindState_Done // for end of current source code reached
};

typedef enum WindState WindState;

enum WindType
{
        WindType_None, //None evaluates to zero
        WindType_Int,
        WindType_Str
};

typedef enum WindType WindType;

//main value container for Wind language
union WindValue
{
        long _int;
        WindStr _str;
};

typedef union WindValue WindValue;

struct WindObject
{
        unsigned char instructions[WindObject_INS_SIZE];
        char code[WindObject_CODE_SIZE];
        WindError error;
        union WindValue value;
        unsigned char* insMark;
        unsigned char* insEnd;
        char* codeMark;
        char* codeEnd;
        WindInstruc curIns;
        WindState state;
        WindType type;
};

typedef struct WindObject WindObject;

//variably size windobject, used for other architectures and specific environments
struct VarWindObject
{
        unsigned char* instructions;
        char* code;
        size_t insCap;
        size_t codeCap;
        WindError error;
        union WindValue value;
        unsigned char* insMark;
        unsigned char* insEnd;
        char* codeMark;
        char* codeEnd;
        WindInstruc curIns;
        WindState state;
        WindType type;
};

typedef struct VarWindObject VarWindObject;


#endif
