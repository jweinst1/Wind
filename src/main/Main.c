#include <stdio.h>
#include "WindNone.h"
#include "Debug.h"

int main(int argc, char const *argv[]) {
        WindNone* none = WindNone_new();
        Debug_object((WindObject*)none);
        return 0;

}
