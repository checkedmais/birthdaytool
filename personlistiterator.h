#ifndef PERSONLISTITERATOR_H
#define PERSONLISTITERATOR_H

#include <list>
#include "person.h"

/**
 * @todo write docs
 */
class PersonListIterator
{
private:
    std::list<Person>* pList_pointer;
    std::list<Person>::iterator it;
    std::list<Person>::iterator begin;
public:
    /**
     * Default constructor
     */
    PersonListIterator(std::list<Person>* pList_pointer);
    PersonListIterator(std::list<Person>* pList_pointer, bool end);
    PersonListIterator& operator++();
    Person& operator*();
    bool operator==(const PersonListIterator &other);
    bool operator!=(const PersonListIterator &other);
};

#endif // PERSONLISTITERATOR_H
