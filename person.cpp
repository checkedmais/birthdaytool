#include "person.h"
#include "date.h"
#include <string>


Person::Person(std::string name, Date date) : name{name}, birthday{date}
{

}

Person::Person(const Person& other) : name{other.name}, birthday{other.birthday}
{
 //   birthday{Date(other.birthday)};
 //   name = other.name;
}

std::string Person::getName()
{
    return name;
}

std::string Person::getBirthday()
{
    return birthday.getFormattedDate();
}


Person::~Person()
{

}

Person& Person::operator=(const Person& other)
{

}

bool Person::operator==(const Person& other) const
{

}

bool Person::operator!=(const Person& other) const
{

}
