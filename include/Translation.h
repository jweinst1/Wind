#ifndef WIND_TRANSLATION_H
#define WIND_TRANSLATION_H

#include <stdio.h>
#include "WindStream.h"
#include "WindLoad.h"

// header that defines translation functions and utils



int Translate_src_command(const char** code, WindStream* ws);

int Translate_src_sep(const char** code, WindStream* ws);

void Translate_src_code(const char* code, WindStream* ws);


#endif
