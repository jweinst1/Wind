#include <stdio.h>
#include <string.h>
#include "IOUtil.h"
#include "WindRun.h"


int main(int argc, char const *argv[]) {
        if(argc != 3)
        {
                fprintf(stderr, "Error, need exactly two command line arguments, got %d\n", argc - 1);
                exit(1);
        }
        else if(!strcmp(argv[1], "-c"))
        {
                WindRun_code(argv[2]);
        }
        // debug option
        else if(!strcmp(argv[1], "-d"))
        {
                WindRun_code(argv[2]);
                IOUtil_debug();
        }
        else
        {
                fprintf(stderr,  "Error, option not recognized found option %s\n", argv[1]);
        }

}
