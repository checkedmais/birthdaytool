#ifndef PERSONLISTITERATOR_H
#define PERSONLISTITERATOR_H

#include <list>
#include "person.h"

/**
 * this iterator more or less wraps std::list<>::iterator
 * its main purpose is to cycle through PersonList starting from the next
 * upcomming birthday
 * to check whether we cycled through the whole list, we need to save
 * the begin-iterator
 */
class PersonListIterator
{
protected:
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
