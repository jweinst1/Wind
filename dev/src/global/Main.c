#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "ByteBuf.h"
#include "Eval.h"

int main(int argc, char const *argv[]) {
        WindObject_BASE(foo);
        ByteBuf* insts = Translate_code("+(\"f\" \"ar\").+(+(\"t\") +(\"aaaaa\" \"dhfkjhjkdhgjk\")).out()");
        Debug_print(insts->begin, insts->mark);
        Eval_code(&foo, insts->begin, insts->mark);
        ByteBuf_del(insts);

        return 0;
}
