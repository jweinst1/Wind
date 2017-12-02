#include <stdio.h>
#include "WindObject.h"
#include "LoadCode.h"






int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        char* src = "foo -> foo -> d";
        LoadCode_upto_null(foop, src);
        printf("space is %s\n", foop->code);
        return 0;

}
