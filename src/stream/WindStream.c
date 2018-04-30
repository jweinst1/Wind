#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* newstream = malloc(sizeof(WindStream));
        for(int i = 0; i < WindStream_BUF_CNT; i++)
        {
                newstream->bufs[i] = WindBuf_new(WindStream_BUF_SIZE);
        }
        newstream->activeBuf = 0;
        return newstream;
}
