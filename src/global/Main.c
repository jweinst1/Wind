#include <stdio.h>
#include "Translate.h"






int main(int argc, char const *argv[]) {
        WindExecutor_INIT(foo);
        printf("The foo state is %d\n", foo.state);
        WindExecutor* wePtr = &foo;
        char* code = "  \n in  5 ->";
        Translate_unit(wePtr, &code);
        for (size_t i = 0; i < 10; i++) {
                printf("%u\n", foo.instructions[i]);
        }
        return 0;

}
