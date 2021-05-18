#include "person.h"
#include "date.h"
#include <string>
#include <sstream>
#include <iostream>

Person::Person(std::string name, Date date, bool family) : name{name}, birthday{date}, family{family}
{

}

Person::Person(const Person& other) : name{other.name}, birthday{other.birthday}, family{other.family}
{

}


/*
 * This constructor takes the date in string format and converts it to a Date-type
 * dateFamily must be in the correct format: DD.MM.YYYYf, where f is only appended when
 * the person is supposed to be a family member
 */

//TODO: check for wrong format

Person::Person(std::string name, std::string dateFamily) : name{name}, family{false}
{
        std::stringstream h;
        auto it = dateFamily.begin();
        //day
        h<<*it<<*(++it);
        int day; 
        h >> day;
        
        h.str(std::string()); //reset h
        h.clear();
        
        ++it; //point
        
        //month
        h<<*(++it)<<*(++it);
        int month;
        h >> month;
        
        h.str(std::string()); //reset h
        h.clear();
        ++it; //point
        
        //year
        h<<*(++it)<<*(++it)<<*(++it)<<*(++it);
        int year;
        h >> year;
        
        if((++it) != dateFamily.end()) //extra signs mean family
        {
            family = true;
        }
        
        birthday = Date(day, month, year);
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


bool Person::operator<=(const Person& other)
{
    return birthday <= other.birthday; //we leverage the work to Date::operator<=
}

bool Person::operator<(const Person& other)
{
    return birthday < other.birthday;
}
