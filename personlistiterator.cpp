#include "personlistiterator.h"
#include <list>
//#include "personlist.h"
#include "person.h"

PersonListIterator::PersonListIterator(std::list<Person>* pList_pointer) : pList_pointer{pList_pointer}
{
    it = pList_pointer->begin();
}

