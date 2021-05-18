#ifndef PERSONLISTLOOPITERATOR_H
#define PERSONLISTLOOPITERATOR_H

#include "person.h"
#include "personlistiterator.h"

/**
 * @todo write docs
 */
class PersonListLoopIterator : public PersonListIterator
{

public:
    PersonListLoopIterator(std::list<Person>* pList_pointer);
    PersonListLoopIterator& operator++();
};

#endif // PERSONLISTLOOPITERATOR_H
