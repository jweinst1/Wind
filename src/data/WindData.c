#include "WindData.h"

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


// Determiens which computational buffer is the active one.
static int WindData_ACTIVE_B = 0;
