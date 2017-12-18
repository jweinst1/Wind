#ifndef WIND_ERR_MESSAGE_H
#define WIND_ERR_MESSAGE_H
// header to handle reading or writing of errors.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
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
// returns pointer to error message buffer
const char* ErrMessage_buf(void);
// prints current error message to stderr
void ErrMessage_print(void);
// prints the current error and exits program.
void ErrMessage_terminate(void);
// clears error message buffer
void ErrMessage_clear(void);

#endif
