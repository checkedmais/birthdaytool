#ifndef DATE_H
#define DATE_H

#include <string>

/**
 * @todo write docs
 */
class Date
{

public:
    Date(int day, int month, int year);
    Date(const Date &other);
    std::string getFormattedDate();
    
private:
    int year=0;
    int month;
    int day;
};

#endif // DATE_H
