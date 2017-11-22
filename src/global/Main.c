#include <stdio.h>
#include "Executor.h"






int main(int argc, char const *argv[]) {
        WindExecutor_INIT(foo);
        printf("The foo state is %d", foo.state);
        return 0;


}
