#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H
// Header that defines WindObject and related macros.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The amount of extra space to add after expansion
#define WindObject_ADDSPC 5
// Extra space to add during allocation.
#define WindObject_ALLSPC 5

#define WindObject_SIZE(wobj) (sizeof(WindObject) + wobj->cap)

#define WindObject_SPACE(wobj) (wobj->cap - wobj->len)
#define WindObject_FULL(wobj) (wobj->cap == wobj->len)

// Simple macro to check if object can fit a size of data.
#define WindObject_FITS(wobj, size) ((wobj->cap - wobj->len) > size)

// Checks if object does NOT fit the size
#define WindObject_FITS_N(wobj, size) ((wobj->cap - wobj->len) <= size)

#define WindObject_ALLOC(capacity) malloc(sizeof(WindObject) + (capacity * sizeof(unsigned char)))

#define WindObject_NEW(name, capacity) \
        WindObject* name = WindObject_ALLOC(capacity + WindObject_ALLSPC); \
        wobj->next = NULL; \
        wobj->prev = NULL; \
        wobj->len = 0; \
        wobj->cap = capacity + WindObject_ALLSPC


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

// Writes one long to the object.
#define WindObject_PUT_LONG(wobj, num) \
        *(long*)(wobj->data + wobj->len) = num; \
        wobj->len += sizeof(long)

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

// Doubles the capacity of the windobject
#define WindObject_EXPAND_2X(wobj) do { \
                wobj->cap *= 2; \
                wobj = realloc(wobj, wobj->cap); \
} while(0)

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

// Creates a new WindObject with space for n bytes
WindObject* WindObject_new_n(size_t n);

// Creates a new WindObject but marks the beginning of the object with a byte.
WindObject* WindObject_new_nmark(unsigned char byte, size_t n);

// Creates a new WindObject from existing memory space.
WindObject* WindObject_new_data(void* data, size_t amount);

// Writes, to the end of an object, some n bytes of data.
void WindObject_write_n(WindObject* wobj, void* data, size_t n);

//Writes to data to the end of an object, but first writes the size of that data.
// As a long integer.
void WindObject_write_recn(WindObject* wobj, void* data, size_t n);

//Copies data from a C-String and moves it.
//void WindObject_write_move(WindObject* wobj, const char** string, size_t n);

// Makes a copy of the entire object.
WindObject* WindObject_new_copy(WindObject* wobj);




#endif // WIND_OBJECT_H
