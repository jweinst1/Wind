#include "Compile.h"
#include "Executor.h"

int Compile_compile_all(char* srcCode)
{
        WindExecutor_INIT(compExec);

        WindExecutor* wExecP = &compExec;
        // copy to maintain original src code string
        char* codePtr = srcCode;
        while(wExecP->state != ExecutorState_Done)
        {
                if(wExecP->errMode == ExecutorError_active)
                {
                        Translate_err(wExecP);
                        return 0;
                }
                wExecP->state = ExecutorState_Translate;
                Translate_unit(wExecP, &codePtr);
                if(wExecP->errMode == ExecutorError_active)
                {
                        Translate_err(wExecP);
                        return 0;
                }
                Translate_transition(wExecP, &codePtr);
                Exec_exec(wExecP);
        }
        return 1; //successful
}
