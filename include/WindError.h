#ifndef WIND_ERROR_H
#define WIND_ERROR_H
//struct type to contain errors.

#define WindError_ON(werr) werr->active = 1;

#define WindError_OFF(werr) werr->active = 0;

struct WindError
{
        char mes[256];
        int active;
};

typdef struct WindError WindError;

#endif
