#ifndef WIND_SAFEALLOC_H
#define WIND_SAFEALLOC_H
//contains malloc macros which check for null pointers

#include <stdio.h>
#include <stdlib.h>

#define SAFE_ALLOC_M(ptr, bufSize) if((ptr = malloc(bufSize)) == NULL) { \
                fprintf(stderr, "Memory Error: Cannot allocate, memory is full.\n"); \
                exit(1); \
}

#define SAFE_ALLOC_RE(ptr, bufSize) if((ptr = realloc(ptr, bufSize)) == NULL) { \
                fprintf(stderr, "Memory Error: Cannot allocate, memory is full.\n"); \
                exit(1); \
}

#endif
