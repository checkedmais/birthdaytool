#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"
#include "personlistiterator.h"
#include <list>
#include <string>

/**
 * @todo write docs
 */
class PersonList
{
private:
    std::list<Person> pList;
    std::string path;
    void retrieveListFromFile();
    void writeListToFile();
public:
    PersonList(std::string filePath);
    void pr();
    void save();
    void addPerson(const Person other);
    PersonListIterator begin(); //todo: think about how this could be done more efficiently
    PersonListIterator end();
};

#endif // PERSONLIST_H
