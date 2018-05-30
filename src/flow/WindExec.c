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

/*int WindExec_map(void)
   {

        // Traversing Pointers
        unsigned char* loadCurrent;
        unsigned char* loadEnd;

        unsigned char* activeCurrent = WindData_active_start();
        unsigned char* activeEnd = WindData_active_ptr();


        unsigned char* altCurrent = WindData_inactive_start();
        while(activeCurrent != activeEnd)
        {
                // needs movable head.
                WindVal_copy(&altCurrent, &activeCurrent, 1);
                // These are restarted each loop since entire map seq
                // is applied to one value at a time.
                loadCurrent = WindData_load_start();
                loadEnd = WindData_load_ptr();
                while(loadCurrent != loadEnd)
                {
                        switch(*loadCurrent)
                        {
                        case WindType_Not:
                                loadCurrent++;
                                //WindVal_apply_not(target->head);
                                break;
                        case WindType_Assign:
                                loadCurrent++;
                                //WindVal_apply_assign(target->head, loadCurrent);
                                WindVal_move(&loadCurrent, 1);
                                break;
                        case WindType_Sep:
                                loadCurrent++;
                                break;
                        default:
                                WindState_write_err("Unrecognized map argument %u", *loadCurrent);
                                return 0;
                        }
                }
                //WindVal_move(&(target->head), 1);
        }
        WindData_active_switch();

        return 1;
   }*/
