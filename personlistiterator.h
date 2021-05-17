#ifndef PERSONLISTITERATOR_H
#define PERSONLISTITERATOR_H

#include <list>
#include "personlist.h"

/**
 * @todo write docs
 */
class PersonListIterator
{
private:
    std::list<PersonList>::iterator it;
public:
    /**
     * Default constructor
     */
    PersonListIterator(std::list<PersonList>::iterator it);

};

#endif // PERSONLISTITERATOR_H
