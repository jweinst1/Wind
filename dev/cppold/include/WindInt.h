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

void debugInfo(void) const
{
        std::cout << "Object:{type = Type_Int, value = " << _int << "}\n";
}

void print(void) const
{
        std::cout << _int;
}

long& getInt(void)
{
        return _int;
}

void setInt(long num)
{
        _int = num;
}

// Creates a new WindInt[1] with specified number.
static WindInt* create(long num);

private:
long _int;
};

#endif // WIND_INT_H
