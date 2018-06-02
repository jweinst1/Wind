#include "IOUtil.h"


static inline int
_fl_is_int(const unsigned char* number)
{
        double numFloat = *(double*)number;
        return numFloat == floor(numFloat);
}

int IOUtil_print(const unsigned char* start, const unsigned char* end)
{
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
                        return 0;   // error case.
                }
        }
        return 1;
}

void IOUtil_debug(void)
{
        puts("_____Wind___Debug_______");
        puts("..........State.........");
        printf("Has Error: %s\n", WindState_has_err() ? "true" : "false");
        WindState_print_err(); //other func
        printf("Mode: ");
        WindState_print_mode();
        printf("Command: ");
        WindState_print_cmd();
        puts("\n..........Data.........");
        printf("Load Buffer: -> [");
        IOUtil_print(WindData_load_begin(), WindData_load_ptr());
        printf("]\n");
        puts("________________________");
}
