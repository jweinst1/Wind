#include "WindExec.h"
#include <Math.h>


static inline int
_fl_is_int(unsigned char* number)
{
        double numFloat = *(double*)number;
        return numFloat == floor(numFloat);
}

int WindExec_out(void)
{
        unsigned char* start = WindData_active_start();
        unsigned char* end = WindData_active_ptr();
        printf("[ ");
        while(start != end)
        {
                switch(*start)
                {
                case WindType_None:
                        start++;
                        printf("None ");
                        break;
                case WindType_Bool:
                        start++;
                        printf(*start++ ? "True " : "False ");
                        break;
                case WindType_Number:
                        start++;
                        if(_fl_is_int(start)) printf("%ld ", (long)(*(double*)start));
                        else printf("%.3f ", *(double*)start);
                        start += sizeof(double);
                        break;
                case WindType_Assign:
                        start++;
                        printf("= ");
                        break;
                case WindType_Not:
                        start++;
                        printf("! ");
                        break;
                case WindType_Sep:
                        start++;
                        printf("| ");
                        break;
                default:
                        return 0;         // error case.
                }
        }
        puts("]");
        return 1;
}

int WindExec_push(void)
{
        size_t pushLen = WindData_load_len();
        WindData_active_write(WindData_load_start(), pushLen);
        return 1;
}

void WindExec_clr(void)
{
        WindData_active_reset();
}

int WindExec_map(void)
{
        unsigned char* loadStart;
        const unsigned char* loadStop;

        unsigned char* activeStart = WindData_active_start();
        const unsigned char* activeStop = WindData_active_ptr();

        WindData_inactive_reset(); // resets inactive for writing new data.
        while(activeStart != activeStop)
        {
                loadStart = WindData_load_start();
                loadStop = WindData_load_ptr();
                // loads into the comp buf.
                activeStart += WindComp_write_typed(activeStart);
                // map proceeds.
                if(!WindComp_map(loadStart, loadStop)) return 0;
                // If inactive buffer is full, this will exit program.
                // Only happens in map if using size increasing ops.
                WindData_inactive_write(WindComp_begin(), WindComp_get_len());
        }

        WindData_active_switch();
        return 1;
}
