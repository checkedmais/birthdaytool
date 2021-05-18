#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "date.h"
#include "person.h"
#include "personlist.h"
#include "personlistiterator.h"
#include "personlistloopiterator.h"

void printHelp(std::string name);
void printFormatted(std::ostream &out, int width, std::string text);

int main(int argc, char **argv) {
    std::string fileName = "dates";
    bool fileSet = false;
    std::vector<Person> addHelper;
    int entries = -1;
    
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if( (arg == "-h") || (arg =="--help") )
        {
            printHelp(argv[0]);
            return 0;
        }
        if( (arg == "-f") || (arg == "--file") )
        {
            if ((i + 1 >= argc) || fileSet)
            {
                printHelp(argv[0]);
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
                printHelp(argv[0]);
                return 0;
            }
            
            addHelper.push_back(Person(argv[i+1], argv[i+2])); //TODO: check for wrong arguments
            i += 2;
            
            continue;
        }
        
        if( (arg == "-e") || (arg == "--entries"))
        {
            if(i + 1 >= argc) //standard procedure
            {
                entries = -1;
                break;
            }
            arg = argv[i+1];
            std::istringstream h(arg); //TODO: check for bad numbers
            h >> entries;
            i++;
            
            continue;
        }
        //it is not something we recognize
        printHelp(argv[0]);
        return 0;
    }
    
    
    PersonList list(fileName); //TODO: check for emptyness
    
    for(auto it = addHelper.begin(); it != addHelper.end(); ++it)
    {
        list.addPerson(*it); //add new persons to the list
    }
    
    if(entries == -1)
    {
    
        for(auto it = list.begin(); it != list.end(); ++it) //cycle through the birthdays
        {                                                   //PersonListIterator ensures that the order of dates is good
            if((*it).isFamily())
            {
                std::cout<<"\033[34m"; //color
            }
            
            printFormatted(std::cout, 25, (*it).getName());
            printFormatted(std::cout, 25, (*it).getBirthday());
            std::cout << "\033[0m" << std::endl;
        }
    }
    else
    {
        auto itl = list.beginl();
        for(int q = 0; q < entries; q++)
        {
            if((*itl).isFamily())
            {
                std::cout<<"\033[34m"; //color
            }
         
            printFormatted(std::cout, 25, (*itl).getName());
            printFormatted(std::cout, 25, (*itl).getBirthday());
            std::cout << "\033[0m" << std::endl;
            
            ++itl;
        }
    }
    
    if(addHelper.empty() == false) //if we added something, save the list
    {
        list.save();
    }
    
    return 0;
}

void printHelp(std::string name)
{
    std::cerr << "Usage: " << name << " {parameter} [...]" << std::endl;
    std::cerr << "Options:" << std::endl;
    
    printFormatted(std::cerr, 5, "-h");
    printFormatted(std::cerr, 15, "--help");
    printFormatted(std::cerr, 10, "show this help message");
    std::cerr << std::endl;
    
    printFormatted(std::cerr, 5, "-f");
    printFormatted(std::cerr, 15, "--file");
    printFormatted(std::cerr, 10, "specifies the file that contains the birthday dates, use only once");
    std::cerr << std::endl;
    
    printFormatted(std::cerr, 5, "-a");
    printFormatted(std::cerr, 15, "--add");
    printFormatted(std::cerr, 10, "add a birthday, takes the name as first argument and date as second argument");
    std::cerr << std::endl;
    
    printFormatted(std::cerr, 5, "-e");
    printFormatted(std::cerr, 15, "--entries");
    printFormatted(std::cerr, 10, "specifies how many upcomming birthdays are printed");
    std::cerr << std::endl;
}

void printFormatted(std::ostream& out, int width, std::string text)
{
    out << std::left << std::setw(width) << std::setfill(' ')
        << text;
}
