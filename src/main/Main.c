#include <stdio.h>
#include "Debug.h"


int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        WindStream_put(stream, 0);
        WindStream_put(stream, 0);
        Debug_stream(stream);

        WindStream_del(stream);
        return 0;

}
