#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"
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
};

#endif // PERSONLIST_H
