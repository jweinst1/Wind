#ifndef WIND_LOAD_CODE_H
#define WIND_LOAD_CODE_H
//loads code onto windobject

#include <string.h>
#include "WindObject.h"

//loads a string onto the code buffer. Only copies up to cb_size
void LoadCode_null(WindObject* wobj, char* srcCode);

// loads n characters from a string. n must be smaller than remaining space in code buffer.
// void LoadCode_str_n(WindObject* wobj, char* srcCode, size_t n);



#endif
