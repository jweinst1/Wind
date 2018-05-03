#include <stdio.h>
#include "Debug.h"


int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        Debug_stream(stream);

        WindStream_del(stream);
        return 0;

}
