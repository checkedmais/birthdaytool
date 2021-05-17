#ifndef PERSONLISTITERATOR_H
#define PERSONLISTITERATOR_H

#include <list>
//#include "personlist.h"
#include "person.h"

/**
 * @todo write docs
 */
class PersonListIterator
{
private:
    std::list<Person>* pList_pointer;
    std::list<Person>::iterator it;
public:
    /**
     * Default constructor
     */
    PersonListIterator(std::list<Person>* pList_pointer);

};

#endif // PERSONLISTITERATOR_H
