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
