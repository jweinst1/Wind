#include "WindData.h"

// Determiens which computational buffer is the active one.
static int WindData_ACTIVE_B = 0;

/*Load Buf*/
static unsigned char WindData_LOAD[WindData_LOAD_SIZE];
static const unsigned char* WindData_LOAD_BEGIN = WindData_LOAD;
static const unsigned char* WindData_LOAD_END = WindData_LOAD + WindData_LOAD_SIZE;

/*Load Pointer for boundary of in use memory*/
static unsigned char* WindData_LOAD_PTR = WindData_LOAD;

/*Computational buffers*/
static unsigned char WindData_B0[WindData_BUF_SIZE];
static const unsigned char* WindData_B0_BEGIN = WindData_B0;
static const unsigned char* WindData_B0_END = WindData_B0 + WindData_BUF_SIZE;

static unsigned char* WindData_B0_PTR = WindData_B0;

static unsigned char WindData_B1[WindData_BUF_SIZE];
static const unsigned char* WindData_B1_BEGIN = WindData_B1;
static const unsigned char* WindData_B1_END = WindData_B1 + WindData_BUF_SIZE;

static unsigned char* WindData_B1_PTR = WindData_B1;

int WindData_active_state(void)
{
        return WindData_ACTIVE_B;
}

void WindData_active_switch(void)
{
        WindData_ACTIVE_B = !WindData_ACTIVE_B;
}

const unsigned char*
WindData_load_begin(void)
{
        return WindData_LOAD_BEGIN;
}

const unsigned char*
WindData_load_end(void)
{
        return WindData_LOAD_END;
}

unsigned char*
WindData_load_ptr(void)
{
        return WindData_LOAD_PTR;
}

size_t WindData_load_space(void)
{
        return WindData_LOAD_END - WindData_LOAD_PTR;
}

void WindData_load_reset(void)
{
        WindData_LOAD_PTR = WindData_LOAD_BEGIN;
}

void WindData_load_adv_safe(size_t amount)
{
        WindData_LOAD_PTR += (amount > WindData_LOAD_END - WindData_LOAD_PTR);
}
