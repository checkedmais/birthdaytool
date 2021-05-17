#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include "person.h"
#include "personlist.h"
#include "personlistiterator.h"

void printHelp();

int main(int argc, char **argv) {
    std::string fileName = "dates";
    bool fileSet = false;
    std::vector<Person> addHelper;
 /*   if(argc == 1)  //no arguments, standard procedure
    {
        PersonList list("dates"); //standard file
        for(auto it = list.begin(); it != list.end(); ++it) //cycle through the birthdays
        {                                                   //PersonListIterator ensures that the order of dates is good
            std::cout<<(*it).getName()<<(*it).getBirthday()<<std::endl;
        }   
        return 0;
    } */
    
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if( (arg == "-h") || (arg =="--help") )
        {
            printHelp();
            return 0;
        }
        if( (arg == "-f") || (arg == "--file") )
        {
            if ((i + 1 >= argc) || fileSet)
            {
                printHelp();
                return 0;
            } //no file selected or a file has already been selected
            
            fileName = argv[++i];
            
            //TODO: check for bad fileNames
            
            continue;
        }
        
        if( (arg == "-a") || (arg == "--add") )
        {
            if(i + 2 >= argc) //nothing to add there
            {
                printHelp();
                return 0;
            }
            
            addHelper.push_back(Person(argv[i+1], argv[i+2]));
            i += 2;
        }
    }
    
    
    PersonList list(fileName); //TODO: check for emptyness
    
    for(auto it = addHelper.begin(); it != addHelper.end(); ++it)
    {
        list.addPerson(*it); //add new persons to the list
    }
    
    for(auto it = list.begin(); it != list.end(); ++it) //cycle through the birthdays
    {                                                   //PersonListIterator ensures that the order of dates is good
        std::cout<<(*it).getName()<<(*it).getBirthday()<<std::endl;
    }
    if(addHelper.empty() == false) //if we added something, save the list
    {
        list.save();
    }
    return 0;
}

void printHelp()
{
    std::cerr<<"help"<<std::endl;
}
