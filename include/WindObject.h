#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// Header that defines WindObject and related macros.

#include <stdlib.h>

// The amount of extra space to add after expansion
#define WindObject_ADDSPC 5

#define WindObject_SIZE(wobj) (sizeof(WindObject) + wobj->cap)

#define WindObject_SPACE(wobj) (wobj->cap - wobj->len)
#define WindObject_FULL(wobj) (wobj->cap == wobj->len)

// Simple macro to check if object can fit a size of data.
#define WindObject_FITS(wobj, size) ((wobj->cap - wobj->len) > size)

#define WindObject_ALLOC(capacity) malloc(sizeof(WindObject) + (capacity * sizeof(unsigned char)))


#define WindObject_RESET(wobj) wobj->len = 0

// Evaluates to a pointer which corresponds to the next slot at which data can be written.
#define WindObject_WRITER(wobj) (wobj->data + wobj->len)


// Gets a casted pointer corresponding to the address at which new data will be written.
#define WindObject_WRITER_T(wobj, type) (type*)(wobj->data + wobj->len)

#define WindObject_NULLIFY(wobj) \
        wobj->next = NULL; \
        wobj->prev = NULL

// Expands via realloc the current allocated memory of the object.
#define WindObject_EXPAND(wobj, amount) do { \
                wobj = realloc(wobj, wobj->cap + amount + WindObject_ADDSPC); \
                wobj->cap += amount + WindObject_ADDSPC; \
} while (0)

// Connects 2 wind objects
#define WindObject_CONNECT(wobj1, wobj2) \
        wobj1->next = wobj2; \
        wobj2->prev = wobj1

// Disconnects 2 wind objects.
#define WindObject_DISCON(wobj1, wobj2) \
        wobj1->next = NULL; \
        wobj2->prev = NULL

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
