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
 //   birthday{Date(other.birthday)};
 //   name = other.name;
}

Person::Person(std::string name, std::string dateFamily) : name{name}
{
 //       bool familyMember = false;   
        std::stringstream h;
        auto it = dateFamily.begin();
     //   std::cout<<name<<dateFamily<<std::endl;
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
            //familyMember = true;
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


Person::~Person()
{

}

bool Person::operator<=(const Person& other)
{
    return birthday <= other.birthday;
}
