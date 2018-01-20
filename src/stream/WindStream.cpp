#include "WindStream.h"


WindStream::WindStream() : _front(nullptr), _back(nullptr), _len(0)
{

}

WindStream::~WindStream()
{
        for(WindNode* traverse = _front; traverse != nullptr; traverse = traverse->getNext())
        {
                delete traverse;
        }
}

WindStream& WindStream::operator<<(WindObject* wobj)
{
        _len++;
        if(isEmpty())
        {
                _front = new WindNode(wobj);
                _back = _front;
                return *this;
        }
        else
        {
                _back->setNext(new WindNode(wobj));
                _back = _back->getNext();
                return *this;
        }
}
