#ifndef WIND_STREAM_H
#define WIND_STREAM_H
// Header to define main Wind Stream Object

#include "WindUnit.h"
#include "WindObject.h"

// type abbreviation, WindNode is always used in WindStream
typedef WindUnit<WindObject> WindNode;

class WindStream
{
public:
WindStream();
~WindStream();

size_t getLen(void) const
{
        return _len;
}

bool isEmpty(void) const
{
        return _front == nullptr && _back == nullptr;
}

bool isSing(void) const
{
        return _back == _front;
}

WindNode* getFront(void) const
{
        return _front;
}

WindNode* getBack(void) const
{
        return _back;
}

WindObject* getFrontObj(void) const
{
        if(_len > 0) return _front->getData();
        else return nullptr;
}

WindObject* getBackObj(void) const
{
        if(_len > 0) return _back->getData();
        else return nullptr;
}

WindStream& operator<<(WindObject* wobj);
private:
WindNode* _front;
WindNode* _back;
size_t _len;
};

#endif
