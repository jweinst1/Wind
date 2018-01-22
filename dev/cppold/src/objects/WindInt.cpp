#include "WindInt.h"

WindInt::WindInt(long num) : _int(num)
{
        setType(WindObject::Type_Int);
}


WindInt* WindInt::create(long num)
{
        WindInt* newint = new WindInt[1];
        newint->setInt(num);
        return newint;
}
