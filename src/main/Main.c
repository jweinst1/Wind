#include <stdio.h>
#include "Translation.h"
#include "Debug.h"


int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        Translate_src_code("out -> out", stream);
        Debug_stream(stream);

        WindStream_del(stream);
        return 0;

}
