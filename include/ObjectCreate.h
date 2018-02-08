#ifndef WIND_OBJECT_CREATE_H
#define WIND_OBJECT_CREATE_H
// Header responsible for creating new wind objects.

#include "WindTypes.h"
#include "WindObject.h"

// Creates a new WindObject with space for n bytes
WindObject* WindObject_new_n(size_t n);

#endif
