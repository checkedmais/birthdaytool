#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "date.h"

/**
 * @todo write docs
 */
class Person
{
public:
    /**
     * Default constructor
     */
    Person(std::string name, Date date, bool family);

    Person(const Person& other);

    Person(std::string name, std::string dateFamily); //see person.cpp
    

    std::string getName();
    std::string getBirthday();
    bool isFamily();
    bool operator<=(const Person& other);

private:
    std::string name;
    Date birthday;
    bool family;
};

#endif // PERSON_H
