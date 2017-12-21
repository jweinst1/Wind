#include "ErrMessage.h"

static char ErrMessage_BUFFER[ErrMessage_SIZE];

static int ErrMessage_STATE = 0;


int ErrMessage_active(void)
{
        return ErrMessage_STATE;
}
void ErrMessage_on(void)
{
        ErrMessage_STATE = 1;
}

void ErrMessage_off(void)
{
        ErrMessage_STATE = 0;
}

void ErrMessage_write(const char* fmt, ...)
{
        va_list args;
        va_start(args, fmt);
        vsprintf(ErrMessage_BUFFER,fmt, args);
        va_end (args);
        ErrMessage_STATE = 1;
}

const char* ErrMessage_buf(void)
{
        return ErrMessage_BUFFER;
}

void ErrMessage_print(void)
{
        fprintf(stderr, "%s\n", ErrMessage_BUFFER);
}

void ErrMessage_terminate(void)
{
        fprintf(stderr, "%s\n", ErrMessage_BUFFER);
        exit(1);
}

void ErrMessage_clear(void)
{
        char* cPtr = ErrMessage_BUFFER;
        while(*cPtr) *cPtr++ = '\0';
}
