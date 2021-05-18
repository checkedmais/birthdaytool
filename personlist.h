#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"
#include "personlistiterator.h"
#include "personlistloopiterator.h"
#include <list>
#include <string>

/**
 * this type wraps around std::list
 * it's purpose is to handle importing and exporting from and to files and
 * to provide iterators which 1. start from the first upcomming birthday and
 * 2. loop around std::list
 */

//TODO: add a method for sorting, in case a given list is unsorted
//      or change retrieveListFromFile()
class PersonList
{
private:
    std::list<Person> pList;
    std::string path;
    void retrieveListFromFile();
    void writeListToFile();
public:
    PersonList(std::string filePath);
    void save();
    void addPerson(const Person &other);
    PersonListIterator begin(); //TODO: think about how this could be done more efficiently
    PersonListIterator end();
    PersonListLoopIterator beginl();
};

#endif // PERSONLIST_H
