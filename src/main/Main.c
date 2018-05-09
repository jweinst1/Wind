#include <stdio.h>
#include "WindRun.h"
#include "Debug.h"


int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        if(argc != 3)
        {
                fprintf(stderr, "%s\n", "Error, need exactly two command line arguments.");
                exit(1);
        }
        else if(strcmp(argv[1], "-c"))
        {
                fprintf(stderr,  "Error, option not recognized found option %s\n", argv[1]);
        }
        WindRun_code(stream, argv[2]);
        Debug_stream(stream);

        WindStream_del(stream);
        return 0;

}
