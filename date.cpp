#include "date.h"
#include <sstream>

Date::Date(int day, int month, int year) : year{year}, month{month}, day{day}
{
}

Date::Date(const Date& other)
{
    day = other.day;
    month = other.month;
    year = other.year;
}

std::string Date::getFormattedDate()
{
    std::stringstream helper;
    helper << (day < 10 ? "0" : "") <<day << "." << (month < 10 ? "0" :"") << month << "." << year;
    return helper.str();
}

bool Date::operator<=(const Date& other)
{
    bool result = this->month < other.month;
    if(result)
    {
        return result; // true
    }
    if(this->month > other.month)
    {
        return result; //false
    }
    if(this->day <= other.day)
    {
        return true;
    }
    return false;
}

