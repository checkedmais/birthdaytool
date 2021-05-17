#include <iostream>
#include "date.h"
#include "person.h"
#include "personlist.h"
#include "personlistiterator.h"

int main(int argc, char **argv) {
   // std::cout << "Hello, world!" << std::endl;
  // Person alex("alex", Date(7,2,2001), true);
   // std::cout<<alex.getName()<<alex.getBirthday();
    PersonList list("dates");
    list.addPerson(Person("peter", Date(20,2,2001), false));
    list.pr();
    list.save();
    return 0;
}


//todo: create PersonList class, which handels sorting, printing, etc
