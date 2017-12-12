#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// contains windobject definition


typedef struct
{
        char* begin;
        char* end;
} WindStr;

typedef enum
{
        WindType_None,
        WindType_Int
} WindType;

typedef union
{
        long _int;
        struct WindStr* _str;
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
