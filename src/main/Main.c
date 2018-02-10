#include <stdio.h>
#include "ObjectCreate.h"
#include "StringTool.h"



int main(int argc, char const *argv[]) {
        printf("Found the char %d\n", StringTool_len_to_ch("111  \n", '4'));
        return 0;
}
