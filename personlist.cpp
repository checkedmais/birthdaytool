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

/*
 * This method reads names and birthdays in specific format from a text file 
 * it expects the list to be already sorted
 */

void PersonList::retrieveListFromFile()
{
    //file format: name | date
    std::ifstream file;
    file.open(path, std::ifstream::in); //TODO: handle wrong path
    std::string input;
    std::stringstream personName;
    bool parseDate = false; //are we parsing the date right now?
    
    while(file>>input) //parse file
    {
        if(input == "|") //finished parsing the name
        {
            parseDate = true;
            continue;
        }
        if(parseDate)
        {
            pList.push_back(Person(personName.str(), input));   //add Person to the list
                                                                //alternatively we could use addPerson,
                                                                //if the list is unsorted
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


void PersonList::addPerson(const Person& other)
{
    if(pList.empty()) //first person
    {
        pList.push_back(other);
        return;
    }
    auto it = pList.begin(); //we insert the person at the right position
    while((*it) <= other)
    {
        ++it;
        if(it == pList.end()) //make sure to not dereference pList.end()
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

