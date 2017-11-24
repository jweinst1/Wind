#include "Compile.h"
#include "Executor.h"

int Compile_compile_all(char* srcCode)
{
        WindExecutor_INIT(compExec);
        // copy to maintain original src code string
        char* codePtr = srcCode;
        return 1; //successful
}
