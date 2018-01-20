#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

// Main object type
class WindObject
{
public:
enum Type
{
        Type_None
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

// The None type class
class WindNone : public WindObject
{
public:
WindNone()
{
        setType(WindObject::Type_None);
}
~WindNone()
{
}

static WindNone* create(int amount = 1)
{
        return new WindNone[amount];
}
};

#endif
