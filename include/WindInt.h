#ifndef WIND_INT_H
#define WIND_INT_H

#include "WindObject.h"

class WindInt : public WindObject
{
public:
WindInt(long num = 0);
~WindInt()
{
}

long& getInt(void)
{
        return _int;
}
private:
long _int;
};

#endif // WIND_INT_H
