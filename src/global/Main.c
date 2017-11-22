#include <stdio.h>
#include "Executor.h"






int main(int argc, char const *argv[]) {
        WindExecutor_INIT(foo);
        printf("The foo state is %d\n", foo.state);
        char* mes = "Hello!";
        char** mesad = &mes;
        printf("%c\n", *(*mesad + 1));
        return 0;


}
