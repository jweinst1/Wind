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

void WindStream::push(WindObject* wobj)
{
        _len++;
        if(isEmpty())
        {
                _front = new WindNode(wobj);
                _back = _front;
        }
        else
        {
                _back->setNext(new WindNode(wobj));
                _back = _back->getNext();
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

void WindStream::removeFront(void)
{
        if(isEmpty()) return;
        else if(isSing())
        {
                _len--;
                delete _front;
                _front = nullptr;
                _back = nullptr;
        }
        else
        {
                _len--;
                WindNode* frontHold = _front;
                delete _front;
                _front = frontHold->getNext();
        }
}
