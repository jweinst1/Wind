#ifndef WIND_REGISTER_H
#define WIND_REGISTER_H
// contains wind register, class used for operations on wind objects

#include "WindObject.h"

#define WindRegister_load_r1(wreg, wobj) wreg.r1 = wobj
#define WindRegister_load_r2(wreg, wobj) wreg.r2 = wobj
#define WindRegister_load_r3(wreg, wobj) wreg.r3 = wobj

#define WindRegister_type_r1(wreg) wreg.r1.type
#define WindRegister_type_r2(wreg) wreg.r2.type
#define WindRegister_type_r3(wreg) wreg.r3.type

struct WindRegister
{
        WindObject* r1;
        WindObject* r2;
        WindObject* r3;
};

typedef struct WindRegister WindRegister;

#endif
