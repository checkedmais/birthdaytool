#include "personlistloopiterator.h"
#include "person.h"
#include "personlist.h"
#include "personlistiterator.h"


PersonListLoopIterator::PersonListLoopIterator(std::list<Person>* pList_pointer) : PersonListIterator(pList_pointer)
{
    
}

PersonListLoopIterator & PersonListLoopIterator::operator++()
{
    if((++it) == pList_pointer->end()) //wrap around
    {
        it = pList_pointer->begin();
    }
    return *this;
}
