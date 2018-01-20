#include "WindStream.h"


WindStream::WindStream() : _front(nullptr), _back(nullptr)
{

}

WindStream::~WindStream()
{
        for(WindNode* traverse = _front; traverse != nullptr; traverse = traverse->getNext())
        {
                delete traverse;
        }
}
