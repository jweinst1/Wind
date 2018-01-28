#include <stdio.h>
#include "WindNone.h"
#include "Evaluate.h"
#include "WindErr.h"
#include "FixedMap.h"

int main(int argc, char const *argv[]) {
        /*  WindStream* stream = WindStream_new();

           EvalState state = EvalState_Command;
           const char* coding = "   \n\nout -> push False None -> out -> pop -> out -> add True None -> out -> clr -> out  ";
           Evaluate_code(stream, coding, &state);
           WindStream_del(stream);*/
        FixedMap foo;
        FixedMap_init(&foo);
        int* nums = malloc(sizeof(int));
        *nums = 6;
        FixedMap_set(&foo, "$hello", nums);
        FixedMap_set(&foo, "$shell", nums);
        printf("The number is %d\n", *(int*)FixedMap_get(&foo, "$shell"));

        return 0;

}
