#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "ByteBuf.h"
#include "Eval.h"


int main(int argc, char const *argv[]) {
        WindObject foo;
        ByteBuf* insts = Translate_code("*(3 +(3 3) 5) -> /(2).out()");
        Debug_print(insts->begin, insts->mark);


        Eval_code(&foo, insts->begin, insts->mark);
        printf("The result is %ld\n", foo.value._int);
        ByteBuf_del(insts);
        return 0;
}
