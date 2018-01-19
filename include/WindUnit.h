#ifndef WIND_UNIT_H
#define WIND_UNIT_H
// Header That defines Wind Unit
// A Unit encapsulates a pointer to some WindObject

template<class T>
class WindUnit
{
public:
// Allocating Constructor
WindUnit(int size) : _len(size), _data(new T[_len]), _next(nullptr)
{

}

WindUnit(T* ptr, int size = 1) : _len(size), _data(ptr), _next(nullptr)
{

}
// Reference Constructor
// object must have copy constructor
WindUnit(const T& object) : _len(1), _data(new T[1]), _next(nullptr)
{
        *_data = object;
}

~WindUnit()
{
        delete[] _data;
}

// Swaps the stored pointer for a new one.
void reset(T* ptr, int size = 1)
{
        delete[] _data;
        _data = ptr;
        _len = size;
}

T& operator* ()
{
        return *_data;
}

T& operator[] (long index)
{
        return _data[index % _len];
}

T* operator-> ()
{
        return _data;
}

bool operator==(const WindUnit& other) const
{
        return other.getLen() == _len && other.getData() == _data;
}

bool operator!=(const WindUnit& other) const
{
        return !(*this == other);
}

int getLen(void) const
{
        return _len;
}

bool isSingle(void) const
{
        return _len == 1;
}

T* getData(void) const
{
        return _data;
}
private:

int _len; // Denotes the amount of members in this unit
T* _data;
WindUnit* _next;
};

#endif
