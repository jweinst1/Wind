#include <stdio.h>
#include <string.h>
#include "WindData.h"


int main(int argc, char const *argv[]) {
        WindData_active_adv(50);
        unsigned char* writer = WindData_active_start();
        while(writer != WindData_active_ptr()) *writer++ = 7;
        unsigned char* reader = WindData_active_start();
        while(reader != WindData_active_ptr()) printf("byte is %u\n", *reader++);
        WindData_active_switch();
        puts("sep----");
        WindData_active_switch();
        reader = WindData_active_start();
        while(reader != WindData_active_ptr()) printf("byte is %u\n", *reader++);

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
