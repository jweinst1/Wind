#include "WindLoad.h"

/*static arrays for pre-init values to be written to buffer*/
// Used for fast loading of booleans
static unsigned char WIND_BOOL_T[] = {WindType_Bool, 1};
static unsigned char WIND_BOOL_F[] = {WindType_Bool, 0};

// Used for loading numbers onto a buffer.
static unsigned char WIND_NUM[sizeof(double) + sizeof(unsigned char)] = {WindType_Number};
// Assists in loading the header of string type.
static unsigned char WIND_STRD[sizeof(unsigned char) + sizeof(unsigned)] = {WindType_String};

static unsigned char WIND_NONE[] = {WindType_None};
static unsigned char WIND_NOT[] = {WindType_Not};
static unsigned char WIND_ASSIGN[] = {WindType_Assign};
static unsigned char WIND_SEP[] = {WindType_Sep};
static unsigned char WIND_PLUS[] = {WindType_Plus};
static unsigned char WIND_MINUS[] = {WindType_Minus};
static unsigned char WIND_MULTIPLY[] = {WindType_Multiply};
static unsigned char WIND_POW[] = {WindType_Pow};
static unsigned char WIND_DIVIDE[] = {WindType_Divide};
static unsigned char WIND_DEL[] = {WindType_Del};
static unsigned char WIND_LT[] = {WindType_Lt};
static unsigned char WIND_GT[] = {WindType_Gt};

// Used as default initalizer for moved C-string result.
static char* NUM_RESULT_INIT = "";

static char* WIND_NULL_C = "";


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

void WindLoad_pow(void)
{
        WindData_load_write(WIND_POW, sizeof(WIND_POW));
}

void WindLoad_divide(void)
{
        WindData_load_write(WIND_DIVIDE, sizeof(WIND_DIVIDE));
}

void WindLoad_del(void)
{
        WindData_load_write(WIND_DEL, sizeof(WIND_DEL));
}

void WindLoad_lt(void)
{
        WindData_load_write(WIND_LT, sizeof(WIND_LT));
}

void WindLoad_gt(void)
{
        WindData_load_write(WIND_GT, sizeof(WIND_GT));
}

void WindLoad_number(const char** code)
{
        char** movedStr = &NUM_RESULT_INIT;
        *(double*)(WIND_NUM + sizeof(unsigned char)) = strtod(*code, movedStr);
        WindData_load_write(WIND_NUM, sizeof(WIND_NUM));
        // Sets the code to new location after number ends.
        *code = *movedStr;
}


int WindLoad_string(const char** code)
{
        const char* mover = *code;
        unsigned stringSize = 0;
        while(*mover != '"')
        {
                // end quote not found, err
                if(*mover == '\0') return 0;
                else mover++;
        }
        stringSize = (++mover) - (*code);
        *(unsigned*)(WIND_STRD + sizeof(unsigned char)) = stringSize;
        WindData_load_write(WIND_STRD, sizeof(WIND_STRD));
        WindData_load_write((char*)(*code), stringSize - 1);
        WindData_load_write(WIND_NULL_C, sizeof(char));
        *code += stringSize;
        return 1;
}
