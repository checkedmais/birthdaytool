#include "person.h"
#include "date.h"
#include <string>


Person::Person(std::string name, Date date, bool family) : name{name}, birthday{date}, family{family}
{

}

Person::Person(const Person& other) : name{other.name}, birthday{other.birthday}, family{other.family}
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

bool Person::isFamily()
{
    return family;
}


Person::~Person()
{

}

bool Person::operator<=(const Person& other)
{
    return birthday <= other.birthday;
}
