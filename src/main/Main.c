#include <stdio.h>
#include "Bytebuf.h"
#include "ObjectCreate.h"


int main(int argc, char const *argv[]) {
        WindObject* nonetest = WindObject_new_none();
        printf("IS none %d\n", nonetest->data[0] == WindObjType_None);
        return 0;
}
