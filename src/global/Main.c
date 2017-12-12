#include <stdio.h>
#include "Instruction.h"
#include "ByteBuf.h"

int main(int argc, char const *argv[]) {
        ByteBuf* buf = ByteBuf_new(50);
        unsigned char ins[] = {WindInstruc_In, WindInstruc_In, WindInstruc_Stop};
        ByteBuf_write(buf, ins, 3);
        printf("%u\n", *(buf->begin));
        return 0;
}
