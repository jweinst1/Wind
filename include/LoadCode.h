#ifndef WIND_LOAD_CODE_H
#define WIND_LOAD_CODE_H
//loads code onto windobject

#include <string.h>
#include "WindObject.h"

//loads a string onto the code buffer. Only copies up to cb_size, uses strncpy
void LoadCode_null(WindObject* wobj, char* srcCode);

void LoadCode_upto_null(WindObject* wobj, char* restrict srcCode);





#endif
