#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// contains windobject definition



typedef enum
{
        WindType_None,
        WindType_Int,
        WindType_Str,
        WindType_List
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
        struct WindList
        {
                struct WindObject* begin;
                struct WindObject* mark;
                struct WindObject* end;
        } _lst;

} WindValue;

typedef struct
{
        WindValue value;
        WindType type;
} WindObject;

#endif
