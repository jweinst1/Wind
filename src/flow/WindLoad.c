#include "WindLoad.h"
#include "WindBuf.h"

// Used for fast loading of booleans
static unsigned char WIND_BOOL_T[] = {WindType_Bool, 1};
static unsigned char WIND_BOOL_F[] = {WindType_Bool, 0};

// Used for loading numbers onto a buffer.
static unsigned char WIND_NUM[sizeof(double) + sizeof(unsigned char)] = {WindType_Number};



// Used as default initalizer for moved C-string result.
static char* NUM_RESULT_INIT = "";


void WindLoad_false(void)
{
        WindData_load_write(WIND_BOOL_F, sizeof(WIND_BOOL_F));
}
void WindLoad_true(void)
{
        WindData_load_write(WIND_BOOL_T, sizeof(WIND_BOOL_T));
}

void WindLoad_number(const char** code)
{
        char** movedStr = &NUM_RESULT_INIT;
        *(double*)(WIND_NUM + sizeof(unsigned char)) = strtod(*code, movedStr);
        WindData_load_write(WIND_NUM, sizeof(WIND_NUM));
        // Sets the code to new location after number ends.
        *code = *movedStr;
}
