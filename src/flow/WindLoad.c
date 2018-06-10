#include "WindLoad.h"

/*static arrays for pre-init values to be written to buffer*/
// Used for fast loading of booleans
static unsigned char WIND_BOOL_T[] = {WindType_Bool, 1};
static unsigned char WIND_BOOL_F[] = {WindType_Bool, 0};

// Used for loading numbers onto a buffer.
static unsigned char WIND_NUM[sizeof(double) + sizeof(unsigned char)] = {WindType_Number};

static unsigned char WIND_NONE[] = {WindType_None};
static unsigned char WIND_NOT[] = {WindType_Not};
static unsigned char WIND_ASSIGN[] = {WindType_Assign};
static unsigned char WIND_SEP[] = {WindType_Sep};
static unsigned char WIND_PLUS[] = {WindType_Plus};
static unsigned char WIND_MINUS[] = {WindType_Minus};
static unsigned char WIND_MULTIPLY[] = {WindType_Multiply};
static unsigned char WIND_DEL[] = {WindType_Del};
static unsigned char WIND_LT[] = {WindType_Lt};

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

void WindLoad_none(void)
{
        WindData_load_write(WIND_NONE, sizeof(WIND_NONE));
}

void WindLoad_sep(void)
{
        WindData_load_write(WIND_SEP, sizeof(WIND_SEP));
}

void WindLoad_not(void)
{
        WindData_load_write(WIND_NOT, sizeof(WIND_NOT));
}

void WindLoad_assign(void)
{
        WindData_load_write(WIND_ASSIGN, sizeof(WIND_ASSIGN));
}

void WindLoad_plus(void)
{
        WindData_load_write(WIND_PLUS, sizeof(WIND_PLUS));
}

void WindLoad_minus(void)
{
        WindData_load_write(WIND_MINUS, sizeof(WIND_MINUS));
}

void WindLoad_multiply(void)
{
        WindData_load_write(WIND_MULTIPLY, sizeof(WIND_MULTIPLY));
}

void WindLoad_del(void)
{
        WindData_load_write(WIND_DEL, sizeof(WIND_DEL));
}

void WindLoad_lt(void)
{
        WindData_load_write(WIND_LT, sizeof(WIND_LT));
}

void WindLoad_number(const char** code)
{
        char** movedStr = &NUM_RESULT_INIT;
        *(double*)(WIND_NUM + sizeof(unsigned char)) = strtod(*code, movedStr);
        WindData_load_write(WIND_NUM, sizeof(WIND_NUM));
        // Sets the code to new location after number ends.
        *code = *movedStr;
}
