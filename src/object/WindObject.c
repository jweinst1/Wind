#include "WindObject.h"

// This file contains core implement for windobject functions.
// Create, writing, reading and more.

WindObject* WindObject_new_n(size_t n)
{
        WindObject* newObj = WindObject_ALLOC(n);
        WindObject_NULLIFY(newObj);
        newObj->len = 0;
        newObj->cap = n;
        return newObj;
}

WindObject* WindObject_new_nmark(unsigned char byte, size_t n)
{
        WindObject* newObj = WindObject_ALLOC(n + 1);
        WindObject_NULLIFY(newObj);
        newObj->len = 1;
        newObj->cap = n + 1;
        newObj->data[0] = byte;
        return newObj;
}

WindObject* WindObject_new_data(void* data, size_t amount)
{
        WindObject* newObj = WindObject_ALLOC(amount + WindObject_ALLSPC);
        WindObject_NULLIFY(newObj);
        newObj->len = amount;
        newObj->cap = amount + WindObject_ALLSPC;
        memcpy(newObj->data, data, amount);
        return newObj;
}

void WindObject_write_n(WindObject* wobj, void* data, size_t n)
{
        if(WindObject_FITS_N(wobj, n)) WindObject_EXPAND(wobj, n);
        memcpy(WindObject_WRITER(wobj), data, n);
        wobj->len += n;
}

void WindObject_write_recn(WindObject* wobj, void* data, size_t n)
{
        long totalPut = n + sizeof(long);
        if(WindObject_FITS_N(wobj, n)) WindObject_EXPAND(wobj, n);
        WindObject_PUT_LONG(wobj, totalPut);
        memcpy(WindObject_WRITER(wobj), data, n);
        wobj->len += totalPut;
}

void WindObject_write_over(WindObject* wobj, void* data, size_t n)
{
        if(n > wobj->cap) WindObject_EXPAND(wobj, n);
        memcpy(wobj->data, data, n);
        wobj->len = n;
}

WindObject* WindObject_new_copy(WindObject* wobj)
{
        size_t objSize = WindObject_SIZE(wobj);
        WindObject* newObj = WindObject_ALLOC(objSize);
        memcpy(newObj, wobj, objSize);
        return newObj;
}
