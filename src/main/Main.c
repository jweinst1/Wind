#include <stdio.h>
#include "Windrun.h"
#include "Debug.h"


int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        WindRun_code(stream, "out -> push None -> push None ->out -> clr -> out ");
        Debug_stream(stream);

        WindStream_del(stream);
        return 0;

}
