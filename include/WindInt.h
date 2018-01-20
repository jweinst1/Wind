#ifndef WIND_INT_H
#define WIND_INT_H

#include "WindObject.h"
#include "PrintInterface.h"

class WindInt : public WindObject, public Printable
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


private:
long _int;
};

#endif // WIND_INT_H
