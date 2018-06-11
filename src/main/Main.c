#include <stdio.h>
#include <string.h>
#include <time.h>

#include "IOUtil.h"
#include "WindRun.h"


int main(int argc, char const *argv[]) {
        if(argc == 1)
        {
                IOUtil_repl();
                exit(0);
        }
        if(argc > 3)
        {
                fprintf(stderr, "Error, need two or no command line arguments, got %d\n", argc - 1);
                exit(1);
        }
        else if(!strcmp(argv[1], "-c"))
        {
                WindRun_code(argv[2]);
        }
        // Timed option
        else if(!strcmp(argv[1], "-t"))
        {
                clock_t start, end;
                start = clock();
                WindRun_code(argv[2]);
                end = clock();
                printf("Time: %f\n", (end-start)/(double)CLOCKS_PER_SEC);
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
