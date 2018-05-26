#include <stdio.h>
#include <string.h>
#include "WindRun.h"


int main(int argc, char const *argv[]) {
        WindRun_code("push 3 2 1 -> out");

        return 0;

}
/*if(argc != 2)
   {
        fprintf(stderr, "%s\n", "Error, need exactly one command line arguments.");
        exit(1);
   }
   else if(!strcmp(argv[1], "-c"))
   {
        printf("-C option\n");
   }
   // debug option
   else if(!strcmp(argv[1], "-d"))
   {
        printf("Load size is %d\n", WindData_LOAD_SIZE);
   }
   else
   {
        fprintf(stderr,  "Error, option not recognized found option %s\n", argv[1]);
   }*/
