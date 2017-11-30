#include <stdio.h>
#include "WindObjectMethods.h"






int main(int argc, char const *argv[]) {
        /*WindExecutor_INIT(foo);
           printf("The foo state is %d\n", foo.state);
           WindExecutor* wePtr = &foo;
           char* code = "  \n in 7 ->";
           Translate_unit(wePtr, &code);
           Exec_exec(wePtr);
           printf("val of int is %d\n", foo.object.value._int);*/


        //printf("succes: %d\n", Compile_compile_all("in \"foo\" -> out -> in 6 -> out -> in \"barf\" -> out -> out ->\n\n\nout"));

        WindObject foo;
        unsigned char* mes = "hel";
        WindObject_make_str(&foo, mes, 3);
        for(char* beg = foo.value._str.begin; beg != foo.value._str.end; beg++) printf("%c\n", *beg);
        return 0;

}
