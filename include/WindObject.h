#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

// Main object type
class WindObject
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
