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
    helper << day << ". " << month << " " << year;
    return helper.str();
}
