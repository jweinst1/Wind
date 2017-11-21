#include <stdio.h>
#include "WindObject.h"



void dynoArr(int n)
{
        WindObject items[n];
        printf("The type is %d\n", items[0].type);

}

int main(int argc, char const *argv[]) {
        puts("Hello World!");
        dynoArr(7);
        return 0;
}
