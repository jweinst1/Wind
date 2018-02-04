#include <stdio.h>
#include "WindNone.h"
#include "Bytebuf.h"
#include "Debug.h"

int main(int argc, char const *argv[]) {
        unsigned char foo[] = {0, 1, 55, 44, 33, 66, 77, 64, 64, 20, 20, 30, 30, 30, 30};
        Debug_bytes(foo, 9);
        return 0;
}
