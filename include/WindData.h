#ifndef WIND_DATA_H
#define WIND_DATA_H

// Header that defines static memory buffers for Wind language.
// These buffers are configurable in size depending on the platform Wind is needed for.

// defines size for the loading buffer.
#define WindData_LOAD_SIZE 100000

//defines size for the computational buffers.
#define WindData_BUF_SIZE 100000



// Function to get load buf pointer.
static inline unsigned char*
WindData_get_load(void)
{
        return WindData_LOAD_PTR;
}

static inline unsigned long
WindData_load_space(void)
{
        return WindData_LOAD_END - WindData_LOAD_PTR;
}

// Switches the active buffer.
static inline void
WindData_active_switch(void)
{
        WindData_ACTIVE_B = !WindData_ACTIVE_B;
}

// Checks the active state for buffers.
static inline int
WindData_active_check(void)
{
        return WindData_ACTIVE_B;
}

// Returns the beginning pointer of active buffer.
static inline unsigned char*
WindData_active_begin(void)
{
        return WindData_ACTIVE_B ? WindData_B1_BEGIN : WindData_B0_BEGIN;
}

static inline unsigned char*
WindData_active_end(void)
{
        return WindData_ACTIVE_B ? WindData_B1_END : WindData_B0_END;
}



#endif
