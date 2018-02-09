#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// Header that defines WindObject and related macros.

#include <stdio.h>
#include <stdlib.h>

// The amount of extra space to add after expansion
#define WindObject_ADDSPC 5
// Extra space to add during allocation.
#define WindObject_ALLSPC 5

#define WindObject_SIZE(wobj) (sizeof(WindObject) + wobj->cap)

#define WindObject_SPACE(wobj) (wobj->cap - wobj->len)
#define WindObject_FULL(wobj) (wobj->cap == wobj->len)

// Simple macro to check if object can fit a size of data.
#define WindObject_FITS(wobj, size) ((wobj->cap - wobj->len) > size)

#define WindObject_ALLOC(capacity) malloc(sizeof(WindObject) + (capacity * sizeof(unsigned char)))

#define WindObject_NEW(name, capacity) \
        WindObject* name = WindObject_ALLOC(capacity); \
        wobj->next = NULL; \
        wobj->prev = NULL; \
        wobj->len = 0; \
        wobj->cap = capacity


#define WindObject_MEM_CHECK(memPtr) if(memPtr == NULL) { \
                fprintf(stderr, "%s\n", "Memory Error: Out of memory, exiting."); \
                exit(1); \
}


#define WindObject_RESET(wobj) wobj->len = 0

// Evaluates to a pointer which corresponds to the next slot at which data can be written.
#define WindObject_WRITER(wobj) (wobj->data + wobj->len)


// Gets a casted pointer corresponding to the address at which new data will be written.
#define WindObject_WRITER_T(wobj, type) (type*)(wobj->data + wobj->len)

// Writes one byte and increments the length
#define WindObject_PUT_BYTE(wobj, byte) (wobj->data[wobj->len++] = byte)

// Writes 1 int to the object.
#define WindObject_PUT_INT(wobj, num) \
        *(int*)(wobj->data + wobj->len) = num; \
        wobj->len += sizeof(int)

#define WindObject_NULLIFY(wobj) \
        wobj->next = NULL; \
        wobj->prev = NULL

// sets prev and next to NULL and resets cap and len.
#define WindObject_WIPE(wobj) \
        wobj->next = NULL; \
        wobj->prev = NULL; \
        wobj->len = 0; \
        wobj->cap = 0

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

#define WindObject_IS_SING(wobj) (wobj->next == NULL && wobj->prev == NULL)
#define WindObject_IS_FRONT(wobj) (wobj->prev == NULL && wobj->next != NULL)
#define WindObject_IS_BACK(wobj) (wobj->prev != NULL && wobj->next == NULL)

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
