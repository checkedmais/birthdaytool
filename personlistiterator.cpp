#include "personlistiterator.h"
#include <list>
#include "person.h"
#include "date.h"
#include <iostream>


//We set it to point to the next upcomming birthday
PersonListIterator::PersonListIterator(std::list<Person>* pList_pointer) : pList_pointer{pList_pointer}
{
    it = pList_pointer->begin();
    Person TodayPerson("", Date(), false);
    while((*it) < TodayPerson)
    {
        ++it;
        if(it == pList_pointer->end())  // this means every birthday of the current year has already happened
        {
            it = pList_pointer->begin();
            break;
        }
    }
    begin = it;
}

/*
 * The iterator is supposed to point to the end of the PersonList,
 * we use the .end() iterator of the std::list inside of PersonList
 */

PersonListIterator::PersonListIterator(std::list<Person>* pList_pointer, bool end) : PersonListIterator(pList_pointer)
{
    if(end)
    {
        it = pList_pointer->end();
    }
}


PersonListIterator & PersonListIterator::operator++()
{
    if((++it) == pList_pointer->end()) //wrap around
    {
        it = pList_pointer->begin();
    }
    if(it == begin) //we cycled through every element
    {
        it = pList_pointer->end();
    }
    return *this;
}

Person & PersonListIterator::operator*()
{
    return *it;
}

bool PersonListIterator::operator==(const PersonListIterator& other)
{
    return other.it == this->it; //we compare std::list<Person>::iterator
}

bool PersonListIterator::operator!=(const PersonListIterator& other)
{
    return !(*this == other);
}
