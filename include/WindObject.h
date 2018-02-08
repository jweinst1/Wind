#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// Header that defines WindObject and related macros.

#include <stdlib.h>

#define WindObject_SIZE(wobj) (sizeof(WindObject) + wobj->cap)

#define WindObject_SPACE(wobj) (wobj->cap - wobj->len)
#define WindObject_FULL(wobj) (wobj->cap == wobj->len)

// Simple macro to check if object can fit a size of data.
#define WindObject_FITS(wobj, size) ((wobj->cap - wobj->len) > size)


// Core Object model of wind programming language.
struct WindObject
{
        struct WindObject* next;
        struct WindObject* prev;
        size_t len;
        size_t cap;
        unsigned char data[0];
};

typedef struct WindObject WindObject;


#endif // WIND_OBJECT_H
