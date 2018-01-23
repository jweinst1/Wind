#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include "PrintInterface.h"

// Main object type
class WindObject : public Printable
{
public:
enum Type
{
        Type_None,
        Type_Int
};
public:
virtual ~WindObject(){
}

Type getType(void) const
{
        return _type;
}

void setType(Type type)
{
        _type = type;
}
private:
Type _type;
};

#endif
