#ifndef WIND_STREAM_H
#define WIND_STREAM_H
// Header to define main Wind Stream Object

#include "WindUnit.h"
#include "WindObject.h"

class WindStream
{
public:
WindStream()
{

}
~WindStream()
{

}
private:
WindUnit<WindObject>* _front;
WindUnit<WindObject>* _back;
};

#endif
