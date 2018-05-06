#ifndef WIND_STREAM_DEF_H
#define WIND_STREAM_DEF_H
// header for definition of wind stream

// enum that acts as way of specifying which buffer you want to perform action on.
typedef enum
{
        BufKey_active,
        BufKey_alt,
        BufKey_load
} BufKey;

//enum to track what tokens the stream will accept next.
typedef enum
{
        StreamState_command,
        StreamState_sep
} StreamState;

typedef struct
{
        char err[256];
        StreamState state;
        int hasErr;
        WindBuf* altBuf;
        WindBuf* activeBuf;
        WindBuf* loadBuf; // for loading args or values.
        // Indicates which stream is active, while the other(s) is reserved for copy operations
        int activeIndex;
} WindStream;


#endif
