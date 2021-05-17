#include "personlistiterator.h"
#include <list>
//#include "personlist.h"
#include "person.h"
#include "date.h"
#include <iostream>

PersonListIterator::PersonListIterator(std::list<Person>* pList_pointer) : pList_pointer{pList_pointer}
{
    it = pList_pointer->begin();
    Person TodayPerson("", Date(), false);
    while((*it) <= TodayPerson)
    {
        ++it;
    }
}

PersonListIterator & PersonListIterator::operator++()
{
    if((++it) == pList_pointer->end()) //wrap around
    {
        it = pList_pointer->begin();
    }
    return *this;
}

Person & PersonListIterator::operator*()
{
    return *it;
}
