#include "IOUtil.h"
#include "LangInfo.h"



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
                case WindType_Plus:
                        start++;
                        printf("+ ");
                        break;
                case WindType_Minus:
                        start++;
                        printf("- ");
                        break;
                case WindType_Multiply:
                        start++;
                        printf("* ");
                        break;
                case WindType_Divide:
                        start++;
                        printf("/ ");
                        break;
                case WindType_Lt:
                        start++;
                        printf("< ");
                        break;
                case WindType_Gt:
                        start++;
                        printf("> ");
                        break;
                case WindType_Del:
                        start++;
                        printf("Del ");
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
        printf("\nCommand: ");
        WindState_print_cmd();
        puts("\n\n..........Data.........");
        printf("Load Buffer: -> [ ");
        IOUtil_print(WindData_load_begin(), WindData_load_ptr());
        printf("]\n");
        printf("Active Buffer: -> [ ");
        IOUtil_print(WindData_active_begin(), WindData_active_ptr());
        printf("]\n");
        printf("Inactive Buffer: -> [ ");
        IOUtil_print(WindData_inactive_begin(), WindData_inactive_ptr());
        printf("]\n");
        puts("\n..........Computation.........");
        printf("Comp Buffer: -> [ ");
        IOUtil_print(WindComp_begin(), WindComp_ptr());
        printf("]\n");
        puts("________________________");
}

void IOUtil_repl(void)
{
        int running = 1;
        char replBuf[IOUtil_REPL_SIZE];
        printf("%s - Version (%s)\n%s", LangInfo_NAME, LangInfo_VERSION, LangInfo_REPL_INS);
        while(running)
        {
                printf(IOUtil_REPL_PROMPT);
                if(fgets(replBuf, IOUtil_REPL_SIZE, stdin) != NULL)
                {
                        if(replBuf[0] == 'e' && replBuf[1] == 'x' && replBuf[2] == 'i' && replBuf[3] == 't')
                        {
                                return;
                        }
                        else
                        {
                                WindRun_code(replBuf);
                        }
                }
        }
}

// Will be used for saving output
int IOUtil_save(const char* path)
{
        FILE* saveFile;
        saveFile = fopen ("path", "wb");
        if(saveFile == NULL)
        {
                return 0;
        }
        fclose(saveFile);
        return 1;
}
