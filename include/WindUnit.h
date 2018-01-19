#ifndef WIND_UNIT_H
#define WIND_UNIT_H
// Header That defines Wind Unit
// A Unit encapsulates a pointer to some WindObject

template<class T>
class WindUnit
{
public:
// Allocating Constructor
WindUnit(int size) : _len(size), _data(new T[_len])
{

}

WindUnit(T* ptr, int size = 1) : _len(size), _data(ptr)
{

}

// Reference Constructor
// object must have copy constructor
WindUnit(const T& object) : _len(1), _data(new T[1])
{
        *_data = T;
}

~WindUnit()
{
        delete[] _data;
}

T& operator* ()
{
        return *_data;
}

T* operator-> ()
{
        return _data;
}


int getLen(void) const
{
        return _len;
}
private:

int _len; // Denotes the amount of members in this unit
T* _data;
};

#endif
