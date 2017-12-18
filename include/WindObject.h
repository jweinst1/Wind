#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// contains windobject definition



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
        struct WindList* _lst;

} WindValue;

typedef struct
{
        WindValue value;
        WindType type;
} WindObject;

typedef struct
{
        WindObject* begin;
        WindObject* mark;
        WindObject* end;
} WindList;

#endif
