#include <iostream>
#include "date.h"
#include "person.h"

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    Person alex("alex", Date(7,2,2001));
    return 0;
}
