#include <stdio.h>
#include "Translate.h"
#include "Debug.h"






int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        char* src = "in \"food\" -> foo -> d";
        char* codeSrc = src;
        Translate_cmd(foop, &codeSrc);
        Translate_transition(foop, &codeSrc);
        Debug_obj(foop);
        return 0;

}
