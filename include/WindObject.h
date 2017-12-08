#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include <stdlib.h>
#include <string.h>
#include "Instruction.h"
#include "SafeAlloc.h"
#include "WindStr.h"
#include "WindError.h"

#define WindObject_INS_SIZE 5000



//instruction buffer space
#define WindObject_IB_SPACE(wobj) wobj->insEnd - wobj->insMark

#define WindObject_IB_FULL(wobj) (wobj->insEnd - wobj->insMark) == 0

//checks if some size can fit on the instruction buffer
#define WindObject_FITS(wobj, addSize) ((wobj->insEnd - wobj->insMark) > addSize)

#define WindObject_INIT(name) \
        WindObject name; \
        SAFE_ALLOC_M(name.instructions, WindObject_INS_SIZE); \
        name.insMark = name.instructions; \
        name.insEnd = name.insMark + WindObject_INS_SIZE; \
        name.type = WindType_None; \
        name.state = WindState_Translate; \
        name.error.active = 0; \
        name.curIns = WindInstruc_Nil;

#define WindObject_INIT_VAR(name, insSize) \
        WindObject name; \
        SAFE_ALLOC_M(name.instructions, insSize); \
        name.insMark = name.instructions; \
        name.insEnd = name.insMark + insSize; \
        name.type = WindType_None; \
        name.state = WindState_Translate; \
        name.error.active = 0; \
        name.curIns = WindInstruc_Nil;


// expands the instruction buffer by some growSize
#define WindObject_EXPAND(wobj, growSize) do { \
                size_t oldLen = wobj->insMark - wobj->instructions; \
                size_t newCap = (wobj->insEnd - wobj->instructions) + growSize; \
                SAFE_ALLOC_RE(wobj->instructions, newCap); \
                wobj->insMark = wobj->instructions + oldLen; \
                wobj->insEnd = wobj->instructions + newCap; \
} while(0)

// Doubles size of instruction buffer
#define WindObject_EXPAND_2(wobj) do { \
                size_t oldLen = wobj->insMark - wobj->instructions; \
                size_t newCap = (wobj->insEnd - wobj->instructions) * 2; \
                SAFE_ALLOC_RE(wobj->instructions, newCap); \
                wobj->insMark = wobj->instructions + oldLen; \
                wobj->insEnd = wobj->instructions + newCap; \
} while(0)

#define WindObject_EXPAND_IF(wobj, addSize) if (!WindObject_FITS(wobj, addSize)) WindObject_EXPAND(wobj, addSize)

#define WindObject_EXPAND_IF2(wobj, addSize) if (!WindObject_FITS(wobj, addSize)) WindObject_EXPAND_2(wobj)

#define WindObject_RESET_INS(wobj) wobj->insMark = wobj->instructions

#define WindObject_ERR_MES(wobj) wobj->error.mes


//works for a scoped, literal WindObject
#define WindObject_DELETE(wobj) do { \
                free(wobj.instructions); \
                wobj.insMark = NULL; \
                wobj.insEnd = NULL; \
} while(0)

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
        WindType_Str,
        WindType_List
};

typedef enum WindType WindType;

//main value container for Wind language
union WindValue
{
        long _int;
        WindStr _str;
        struct WindList* _lst;
};

typedef union WindValue WindValue;

// functions as a form of WindObject but no executing capability.
// allows for iteration for(witem = wlst->begin; witem != wlst->end; witem++)
struct WindItem
{
        WindType type;
        WindValue value;
};

typedef struct WindItem WindItem;

struct WindList
{
        WindItem* begin;
        WindItem* mark;
        WindItem* end;
};

typedef struct WindList WindList;


//main windobject, capable of executing instructions on itself
// similar to an objected oriented state machine
struct WindObject
{
        unsigned char* instructions;
        WindError error;
        union WindValue value;
        unsigned char* insMark;
        unsigned char* insEnd;
        WindInstruc curIns;
        WindState state;
        WindType type;
};

typedef struct WindObject WindObject;


#endif
