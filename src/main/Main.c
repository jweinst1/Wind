#include <stdio.h>
#include "Translation.h"


int main(int argc, char const *argv[]) {
        StreamState st = StreamState_sep;
        WindStream* stream = WindStream_new();
        const char* sample = "   \n \n   -te  ";
        Translate_src_sep(&sample, stream, &st);
        WindStream_print_err(stream);
        printf("The error is gone %d\n", stream->hasErr);

        WindStream_del(stream);
        return 0;

}
