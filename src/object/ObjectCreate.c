#include "ObjectCreate.h"

WindObject* WindObject_new_n(size_t n)
{
        WindObject* newObj = WindObject_ALLOC(n);
        WindObject_NULLIFY(newObj);
        newObj->len = 0;
        newObj->cap = n;
        return newObj;
}

WindObject* WindObject_new_none(void)
{
        WindObject* newObj = WindObject_ALLOC(1);
        WindObject_NULLIFY(newObj);
        newObj->len = 1;
        newObj->cap = 1;
        newObj->data[0] = WindObjType_None;
        return newObj;
}
