#include "WindExec.h"

int WindExec_out(void)
{
        unsigned char* start = WindData_active_start();
        unsigned char* end = WindData_active_ptr();
        printf("[ ");
        IOUtil_print(start, end);
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
        if(!WindData_load_len()) return 1;
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

int WindExec_filter(void)
{
        if(!WindData_load_len()) return 1;
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
                if(!WindComp_filter(loadStart, loadStop)) return 0;

                WindData_inactive_write(WindComp_begin(), WindComp_get_len());
        }

        WindData_active_switch();
        return 1;
}

int WindExec_save(void)
{
        unsigned char* loadBuf = WindData_load_start();
        if(*loadBuf != WindType_String)
        {
                WindState_write_err("Expected type 'string' for save command, got type '%s'", WindType_get_str(*loadBuf));
                return 0;
        }
        const char* savePath = (const char*)(loadBuf + sizeof(unsigned char) + sizeof(unsigned));
        if(!IOUtil_save(savePath))
        {
                WindState_write_err("File path '%s' cannot be written to.", savePath);
                return 0;
        }
        printf("Saved at: %s\n", savePath);
        return 1;
}

int WindExec_load(void)
{
        unsigned char* loadBuf = WindData_load_start();
        if(*loadBuf != WindType_String)
        {
                WindState_write_err("Expected type 'string' for load command, got type '%s'", WindType_get_str(*loadBuf));
                return 0;
        }
        const char* loadPath = (const char*)(loadBuf + sizeof(unsigned char) + sizeof(unsigned));
        if(!IOUtil_load(loadPath))
        {
                WindState_write_err("File path '%s' cannot be read from.", loadPath);
                return 0;
        }
        printf("Loaded data from: %s\n", loadPath);
        return 1;
}
