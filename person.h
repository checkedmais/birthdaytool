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
    Person(std::string name, Date date);

    /**
     * Copy constructor
     *
     * @param other TODO
     */
    Person(const Person& other);

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
    Person& operator=(const Person& other);

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator==(const Person& other) const;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!=(const Person& other) const;

private:
    std::string name;
    Date birthday;
};

#endif // PERSON_H
