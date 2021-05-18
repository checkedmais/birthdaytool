#ifndef PERSONLISTLOOPITERATOR_H
#define PERSONLISTLOOPITERATOR_H

#include "person.h"
#include "personlistiterator.h"

/**
 * @todo write docs
 * This is an iterator, which loops
 * it is the same as PersonListIterator, the only difference is that in operator++
 * the check whether we cycled through all elements is omitted
 */
class PersonListLoopIterator : public PersonListIterator
{

public:
    PersonListLoopIterator(std::list<Person>* pList_pointer);
    PersonListLoopIterator& operator++();
};

#endif // PERSONLISTLOOPITERATOR_H
