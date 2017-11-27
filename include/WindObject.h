#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include <stdlib.h>

/* base properties to ensure inheritance
 #define WindObject_BASE struct WindObject* next; \
        enum WindType type;

   // casts some typed wind object back to its base form.
 #define WindObject_CAST(wobj) ((WindObj*)wobj)

   //casts and evaluates to the next of the wind object
 #define WindObject_NEXT(wobj) ((WindObject*)wobj)->next

 #define WindObject_IS_END(wobj) wobj->next == NULL

   //casts the next of some wind object back to base
 #define WindObject_CAST_NEXT(wobj) (WindObject*)(wobj->next)*/

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
        int _int;
        char* _str;
};

struct WindObject
{
        WindType type;
        union WindValue value;
};

typedef struct WindObject WindObject;

#endif
