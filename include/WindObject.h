#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

// Object base struct for common casting.
#define WindObject_BASE \
        WindType type; \
        WindObject* next; \
        WindObject* prev;

typedef enum
{
        WindType_None
} WindType;


// Wind Object
typedef struct
{

} WindObject;

#endif // WIND_OBJECT_H
