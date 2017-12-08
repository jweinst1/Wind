#ifndef WIND_TRANSLATE_H
#define WIND_TRANSLATE_H
//translates source code to instructions

#include <stdlib.h>
#include <ctype.h>
#include "WindObject.h"

#define Translate_BUF_CHECK(wobj) wobj->insMark > (wobj->insEnd - 16)

// helper
typedef enum {
        TransState_Off,
        TransState_On
} TransState;

//processes and prints a translation-time error
void Translate_err(WindObject* wobj);

//function responsible for transitioning to execution
void Translate_transition(WindObject* wobj, char** srcCode);

// Helper function that gets length of string.
size_t Translate_str_len(WindObject* wobj, char** srcCode);


//translates single cmd in wind
void Translate_cmd(WindObject* wobj, char** srcCode);

#endif
