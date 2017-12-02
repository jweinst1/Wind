#include <stdio.h>
#include "WindObject.h"






int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        printf("space is %lu\n", WindObject_CB_SPACE(foop));
        return 0;

}
