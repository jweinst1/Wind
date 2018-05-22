#include "WindData.h"

// Determiens which computational buffer is the active one.
static int WindData_ACTIVE_B = 1;

/*Load Buf*/
static unsigned char WindData_LOAD[WindData_LOAD_SIZE];
static unsigned char* WindData_LOAD_BEGIN = WindData_LOAD;
static unsigned char* WindData_LOAD_END = WindData_LOAD + WindData_LOAD_SIZE;

/*Load Pointer for boundary of in use memory*/
static unsigned char* WindData_LOAD_PTR = WindData_LOAD;

/*Computational buffers*/
static unsigned char WindData_B0[WindData_BUF_SIZE];
static unsigned char* WindData_B0_BEGIN = WindData_B0;
static unsigned char* WindData_B0_END = WindData_B0 + WindData_BUF_SIZE;

static unsigned char* WindData_B0_PTR = WindData_B0;

static unsigned char WindData_B1[WindData_BUF_SIZE];
static unsigned char* WindData_B1_BEGIN = WindData_B1;
static unsigned char* WindData_B1_END = WindData_B1 + WindData_BUF_SIZE;

static unsigned char* WindData_B1_PTR = WindData_B1;

/*BUF STATE CONTROLLER*/
int WindData_active_state(void)
{
        return WindData_ACTIVE_B;
}

void WindData_active_switch(void)
{
        WindData_ACTIVE_B = !WindData_ACTIVE_B;
}

const unsigned char* WindData_active_begin(void)
{
        return (WindData_ACTIVE_B ? WindData_B1_BEGIN : WindData_B0_BEGIN);
}

const unsigned char* WindData_active_end(void)
{
        return (WindData_ACTIVE_B ? WindData_B1_END : WindData_B0_END);
}

unsigned char* WindData_active_ptr(void)
{
        return (WindData_ACTIVE_B ? WindData_B1_PTR : WindData_B0_PTR);
}

unsigned char* WindData_active_start(void)
{
        return (WindData_ACTIVE_B ? WindData_B1_BEGIN : WindData_B0_BEGIN);
}

size_t WindData_active_space(void)
{
        return WindData_ACTIVE_B ? WindData_B1_END - WindData_B1_PTR : WindData_B0_END - WindData_B0_PTR;
}

int WindData_active_is_full(void)
{
        return WindData_ACTIVE_B ? WindData_B1_END == WindData_B1_PTR : WindData_B0_END == WindData_B0_PTR;
}
void WindData_active_reset(void)
{
        WindData_ACTIVE_B ? (WindData_B1_PTR = WindData_B1_BEGIN) : (WindData_B0_PTR = WindData_B0_BEGIN);
}

void WindData_active_adv_safe(size_t amount)
{
        if(WindData_ACTIVE_B)
        {
                WindData_B1_PTR += (amount > WindData_B1_END - WindData_B1_PTR ? WindData_B1_END - WindData_B1_PTR : amount );
        }
        else WindData_B0_PTR += (amount > WindData_B0_END - WindData_B0_PTR ? WindData_B0_END - WindData_B0_PTR : amount );
}
void WindData_active_adv(size_t amount)
{
        size_t space = WindData_ACTIVE_B ? WindData_B1_END - WindData_B1_PTR : WindData_B0_END - WindData_B0_PTR;
        if(amount > space)
        {
                fprintf(stderr, "%s\n", "Memory Error: Ran out of active buffer memory, exiting.");
                exit(1);
        }
        else
        {
                if(WindData_ACTIVE_B) WindData_B1_PTR += amount;
                else WindData_B0_PTR += amount;
        }
}
void WindData_active_set(unsigned char* place)
{
        if(WindData_ACTIVE_B) WindData_B1_PTR = place;
        else WindData_B0_PTR = place;
}

/*INACTIVE FUNCTIONS*/

const unsigned char* WindData_inactive_begin(void)
{
        return (!WindData_ACTIVE_B ? WindData_B1_BEGIN : WindData_B0_BEGIN);
}

const unsigned char* WindData_inactive_end(void)
{
        return (!WindData_ACTIVE_B ? WindData_B1_END : WindData_B0_END);
}

unsigned char* WindData_inactive_ptr(void)
{
        return (!WindData_ACTIVE_B ? WindData_B1_PTR : WindData_B0_PTR);
}

unsigned char* WindData_inactive_start(void)
{
        return (!WindData_ACTIVE_B ? WindData_B1_BEGIN : WindData_B0_BEGIN);
}
size_t WindData_inactive_space(void)
{
        return !WindData_ACTIVE_B ? WindData_B1_END - WindData_B1_PTR : WindData_B0_END - WindData_B0_PTR;
}

int WindData_inactive_is_full(void)
{
        return !WindData_ACTIVE_B ? WindData_B1_END == WindData_B1_PTR : WindData_B0_END == WindData_B0_PTR;
}

void WindData_inactive_reset(void)
{
        !WindData_ACTIVE_B ? (WindData_B1_PTR = WindData_B1_BEGIN) : (WindData_B0_PTR = WindData_B0_BEGIN);
}

void WindData_inactive_adv_safe(size_t amount)
{
        if(!WindData_ACTIVE_B)
        {
                WindData_B1_PTR += (amount > WindData_B1_END - WindData_B1_PTR ? WindData_B1_END - WindData_B1_PTR : amount );
        }
        else WindData_B0_PTR += (amount > WindData_B0_END - WindData_B0_PTR ? WindData_B0_END - WindData_B0_PTR : amount );
}

void WindData_inactive_adv(size_t amount)
{
        size_t space = !WindData_ACTIVE_B ? WindData_B1_END - WindData_B1_PTR : WindData_B0_END - WindData_B0_PTR;
        if(amount > space)
        {
                fprintf(stderr, "%s\n", "Memory Error: Ran out of active buffer memory, exiting.");
                exit(1);
        }
        else
        {
                if(!WindData_ACTIVE_B) WindData_B1_PTR += amount;
                else WindData_B0_PTR += amount;
        }
}

void WindData_inactive_set(unsigned char* place)
{
        if(!WindData_ACTIVE_B) WindData_B1_PTR = place;
        else WindData_B0_PTR = place;
}

/*LOAD FUNCTIONS*/

unsigned char* WindData_load_start(void)
{
        return WindData_LOAD;
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

int WindData_load_is_full(void)
{
        return WindData_LOAD_END == WindData_LOAD_PTR;
}

void WindData_load_reset(void)
{
        WindData_LOAD_PTR = WindData_LOAD_BEGIN;
}

void WindData_load_adv_safe(size_t amount)
{
        size_t space = WindData_LOAD_END - WindData_LOAD_PTR;
        WindData_LOAD_PTR += (amount > space ? space : amount);
}

void WindData_load_adv(size_t amount)
{
        if(amount > WindData_LOAD_END - WindData_LOAD_PTR)
        {
                fprintf(stderr, "%s\n", "Memory Error: Ran out of load buffer memory, exiting.");
                exit(1);
        }
        else WindData_LOAD_PTR += amount;
}

void WindData_load_set(unsigned char* place)
{
        if(place >= WindData_LOAD_BEGIN && place <= WindData_LOAD_END)
                WindData_LOAD_PTR = place;
}

void WindData_load_write(void* data, size_t length)
{
        if(length > WindData_LOAD_END - WindData_LOAD_PTR)
        {
                fprintf(stderr, "%s\n", "Memory Error: Ran out of load buffer memory, exiting.");
                exit(1);
        }
        else
        {
                memcpy(WindData_LOAD_PTR, data, length);
                WindData_LOAD_PTR += length;
        }
}
