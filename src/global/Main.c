#include <stdio.h>
#include "Compile.h"






int main(int argc, char const *argv[]) {
        /*WindExecutor_INIT(foo);
           printf("The foo state is %d\n", foo.state);
           WindExecutor* wePtr = &foo;
           char* code = "  \n in 7 ->";
           Translate_unit(wePtr, &code);
           Exec_exec(wePtr);
           printf("val of int is %d\n", foo.object.value._int);*/


        printf("succes: %d\n", Compile_compile_all("in \"foo\" -> out -> in 6 -> out -> in \"barf\" -> out -> out ->\n\n\nout"));
        return 0;

}
