#include <iostream>
#include "date.h"
#include "person.h"
#include "personlist.h"
#include "personlistiterator.h"

int main(int argc, char **argv) {
   // std::cout << "Hello, world!" << std::endl;
  // Person alex("alex", Date(7,2,2001), true);
  // // std::cout<<alex.getName()<<alex.getBirthday();
    PersonList list("dates");
    auto it = list.begin();
    for(int i = 0; i < 10; i++)
    {
        std::cout<<(*it).getName()<<(*it).getBirthday()<<std::endl;
        ++it;
    }
    list.save();
    return 0;
}


//todo: create PersonList class, which handels sorting, printing, etc
