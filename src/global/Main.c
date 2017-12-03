#include <stdio.h>
#include "WindObject.h"
#include "Translate.h"






int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        char* src = "in \"food\" -> foo -> d";
        char* codeSrc = src;
        Translate_cmd(foop, &codeSrc);
        Translate_transition(foop, &codeSrc);
        printf("%s\n", codeSrc);
        for (size_t i = 0; i < 30; i++) {
                printf("%u\n", foop->instructions[i]);
        }
        return 0;

}
