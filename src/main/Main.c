#include <stdio.h>
#include "WindNone.h"
#include "Debug.h"

int main(int argc, char const *argv[]) {
        WindNone* none = WindNone_new();
        WindNone* none2 = WindNone_new();
        WindStream* stream = WindStream_new();
        WindStream_push(stream, (WindObject*)none);
        WindStream_push(stream, (WindObject*)none2);
        Debug_stream(stream);
        WindStream_del(stream);
        return 0;

}
