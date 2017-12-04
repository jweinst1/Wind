#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "Exec.h"






int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        char* src = "in \"foooooood\" -> foo -> d";
        char* codeSrc = src;
        Translate_cmd(foop, &codeSrc);
        Translate_transition(foop, &codeSrc);
        Exec_exec(foop);
        Debug_obj(foop);
        return 0;

}
