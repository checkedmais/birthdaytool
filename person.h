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

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    Person(const Person& other);

    Person(std::string name, std::string dateFamily);
    
    /**
     * Destructor
     */
    ~Person();

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */

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
