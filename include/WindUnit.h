#ifndef WIND_UNIT_H
#define WIND_UNIT_H
// Header That defines Wind Unit
// A Unit encapsulates a pointer to some WindObject

#include "DebugInterface.h"

template<class T>
class WindUnit : public DebugInterface
{
public:


WindUnit(T* ptr = nullptr, int size = 1) : _len(size), _data(ptr), _next(nullptr)
{

}


void debugInfo(void) const
{
        std::cout << "Unit:{ length: " << _len << " objectAd: " << static_cast<void*>(_data) << "}" << std::endl;
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

WindUnit* getNext(void) const
{
        return _next;
}

bool hasNext(void) const
{
        return _next != nullptr;
}

void setNext(WindUnit* wunit)
{
        _next = wunit;
}

WindUnit* getNextNext(void) const
{
        if(hasNext()) return _next->getNext();
        else return nullptr;
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
