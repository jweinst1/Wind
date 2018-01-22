#include <stdio.h>
#include "WindNone.h"

int main(int argc, char const *argv[]) {
        WindNone* none = WindNone_new_arr(2);
        printf("%s%d\n", "Hello!", (none + 1)->type);
        free(none);
        return 0;
}
