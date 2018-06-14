#include "WindReduce.h"


int WindReduce_plus(void)
{
        if(!WindData_active_len()) return 1; // cannot reduce if empty
        unsigned char* comp = WindComp_begin();
        unsigned char* compBody = WindComp_get_body();

        unsigned char* activeStart = WindData_active_start();
        unsigned char* activeStop = WindData_active_ptr();

        // load first onto comp buffer
        activeStart += WindComp_write_typed(activeStart);
        if(*comp != WindType_Number)
        {
                // todo: String will be added
                WindState_write_err("Attempted to reduce + on type: '%s'", WindType_get_str(*comp));
                return 0;
        }
        WindData_inactive_reset();
        while(activeStart != activeStop)
        {
                switch(*activeStart)
                {
                case WindType_Number:
                        activeStart++;
                        // todo: macros of these need to be in separate head.
                        *(double*)(compBody) += *(double*)(activeStart);
                        activeStart += sizeof(double);
                        break;
                default:
                        WindState_write_err("Cannot perform reduce (+) with argument type: '%s'", WindType_get_str(*activeStart));
                        return 0;
                }
        }
        WindData_inactive_write(WindComp_begin(), WindComp_get_len());
        WindData_active_switch();
        return 1;
}

int WindReduce_reduce(void)
{
        unsigned char* reduceInst = WindData_load_start();
        switch(*reduceInst)
        {
        case WindType_Plus:
                return WindReduce_plus();
        default:
                WindState_write_err("Cannot run reduce operation with instruction type: '%s'", WindType_get_str(*reduceInst));
                return 0;
        }
        return 1;
}
