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
private:
WindUnit<WindObject>* _front;
WindUnit<WindObject>* _back;
};

#endif
