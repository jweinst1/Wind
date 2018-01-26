#include <stdio.h>
#include "WindNone.h"
#include "Evaluate.h"
#include "WindErr.h"

int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();

        EvalState state = EvalState_Command;
        const char* coding = "   \n\nout -> push None None -> out -> pop -> out";
        Evaluate_code(stream, coding, &state);
        WindStream_del(stream);

        return 0;

}
