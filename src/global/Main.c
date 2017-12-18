#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "ByteBuf.h"
#include "Eval.h"


int main(int argc, char const *argv[]) {
        WindObject foo;
        ByteBuf* insts = Translate_code("\"Hello \" # this is a comment\n -> +(\"World!\" \" My\" \" \nis charles!\").out()");
        Debug_print(insts->begin, insts->mark);

        Eval_code(&foo, insts->begin, insts->mark);
        ByteBuf_del(insts);
        return 0;
}
