#include <stdio.h>
#include "WindNone.h"
#include "WindStream.h"

int main(int argc, char const *argv[]) {
        WindStream* stream = WindStream_new();
        WindNone* none = WindNone_new();
        WindNone* none2 = WindNone_new();
        WindStream_push(stream, (WindObject*)none);
        WindStream_push(stream, (WindObject*)none2);
        printf("type is %d\n", stream->front->next->type);
        printf("len is %lu\n", stream->len);
        WindStream_del(stream);
        return 0;

}
