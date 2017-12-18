#ifndef WIND_ERR_MESSAGE_H
#define WIND_ERR_MESSAGE_H
// header to handle reading or writing of errors.

#include <stdio.h>
// size of error buffer
#define ErrMessage_SIZE 256

// Determines if an error is currently active
int ErrMessage_active(void);
// turns error message on.
void ErrMessage_on(void);
// turns error off
void ErrMessage_off(void);
// writes message to error buffer
void ErrMessage_write(const char* fmt, ...);
// clears error message buffer
void ErrMessage_clear(void);

#endif
