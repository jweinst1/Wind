#include <stdio.h>
#include "Translation.h"


int main(int argc, char const *argv[]) {
        StreamState st = StreamState_sep;
        WindStream* stream = WindStream_new();
        const char* sample = "   \n \n   ->e  ";
        Translate_src_sep(&sample, stream, &st);
        printf("the state is %d\n", st);
        return 0;

}
