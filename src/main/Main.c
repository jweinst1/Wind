#include <stdio.h>
#include "WindNone.h"
#include "Evaluate.h"
#include "WindErr.h"
#include "IntMap.h"

int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();

        EvalState state = EvalState_Command;
        const char* coding = "   \n\nout -> push False None -> out -> pop -> out -> add True None -> out -> clr -> out  ";
        Evaluate_code(stream, coding, &state);
        WindStream_del(stream);
        IntMap_INIT(foomapp);
        IntMap_add(&foomapp, "Hello!");
        unsigned char g = IntMap_add(&foomapp, "Hello");
        printf("Result is %u\n", IntMap_get(&foomapp, "Hello"));
        return 0;

}
