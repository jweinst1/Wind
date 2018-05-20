#include <stdio.h>
#include <string.h>
#include "WindData.h"


int main(int argc, char const *argv[]) {
        if(argc != 3)
        {
                fprintf(stderr, "%s\n", "Error, need exactly two command line arguments.");
                exit(1);
        }
        else if(!strcmp(argv[1], "-c"))
        {
                printf("-C option\n");
        }
        // debug option
        else if(!strcmp(argv[1], "-d"))
        {
                printf("Buf size is %d\n", WindData_BUF_SIZE);
        }
        else
        {
                fprintf(stderr,  "Error, option not recognized found option %s\n", argv[1]);
        }

        return 0;

}
