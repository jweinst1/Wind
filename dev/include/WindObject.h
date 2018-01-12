#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// contains windobject definition

// Initalizes a WindObject for the root of Wind evaluation
#define WindObject_BASE(name) \
        WindObject name; \
        name.type = WindType_None; \
        name.parent = NULL


typedef enum
{
        WindType_None,
        WindType_Int,
        WindType_Str
} WindType;

typedef struct
{
        long _int;
        struct WindStr
        {
                char* begin;
                char* mark;
                char* end;
        } _str;

} WindValue;

typedef struct
{
        WindValue value;
        WindType type;
        struct WindObject* parent;
} WindObject;

#endif
