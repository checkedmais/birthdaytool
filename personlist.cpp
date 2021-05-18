#include "personlist.h"

#include "person.h"
#include "date.h"
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

PersonList::PersonList(std::string filePath) : path{filePath}
{
    retrieveListFromFile();
}

void PersonList::retrieveListFromFile()
{
    //file format: name | date
    std::ifstream file;
    file.open(path, std::ifstream::in); //todo: handle wrong path
    std::string input;
    std::stringstream personName;
    bool parseDate = false;
    while(file>>input) //parse file
    {
        if(input == "|") //
        {
            parseDate = true;
            continue;
        }
        if(parseDate)
        {
  /*          bool familyMember = false;   
            std::stringstream h;
            auto it = input.begin();
            
            //day
            h<<*it<<*(++it);
            int day; 
            h >> day;
            
            h.str(std::string()); //reset h
            h.clear();
            
            ++it; //point
            
            //month
            std::stringstream h2;
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
            
            if((++it) != input.end()) //extra signs mean family
            {
                familyMember = true;
            }
            
            Date date(day, month, year);
            pList.push_back(Person(personName.str(), date, familyMember)); 
            
            personName.str(std::string()); //reset personName
            personName.clear();
            parseDate = false; */
            pList.push_back(Person(personName.str(), input));
            personName.str(std::string()); //reset personName
            personName.clear();
            parseDate = false;
            continue;
        }
        personName << input;
    }
    file.close();
}

void PersonList::writeListToFile()
{
    std::ofstream file;
    file.open(path, std::ofstream::out); //replace previous content
    
    for(auto it = pList.begin(); it != pList.end(); ++it)
    {
        file << (*it).getName(); //name
        file << " | "; //seperator
        file << (*it).getBirthday(); //date
        if((*it).isFamily())
        {
            file << "f";
        }
        file << std::endl; //family
    }
    file.close();
}

void PersonList::save()
{
    writeListToFile();
}


void PersonList::pr()
{
    for(auto it = pList.begin(); it != pList.end(); (++it))
    {
        std::cout<<"1. "<<(*it).getName()<<(*it).getBirthday()<<std::endl;
    }
}

void PersonList::addPerson(const Person& other)
{
    if(pList.empty())
    {
        pList.push_back(other);
        return;
    }
    auto it = pList.begin();
    while((*it) <= other)
    {
        ++it;
        if(it == pList.end())
        {
            break;
        }
    }
    pList.insert(it, other);
}

PersonListIterator PersonList::begin()
{
    return PersonListIterator(&pList);
}

PersonListIterator PersonList::end()
{
    return PersonListIterator(&pList, true);
}

PersonListLoopIterator PersonList::beginl()
{
    return PersonListLoopIterator(&pList);
}

