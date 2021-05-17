#include "personlistiterator.h"
#include <list>
#include "personlist.h"

PersonListIterator::PersonListIterator(std::list<PersonList>::iterator it) : it{it}
{
    
}

