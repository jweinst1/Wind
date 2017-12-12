#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H
//contains the debug function

#include <stdio.h>
#include "Instruction.h"

#define Debug_HEADER puts("---Wind--Translate---Debug----")

#define Debug_FOOTER puts("-------------end--------------")

/** Debug Printing Function
 * - prints out readable version of Translated Wind Instructions
 *
 */
void Debug_print(unsigned char* start, unsigned char* end);

#endif
