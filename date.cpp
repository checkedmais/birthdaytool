#include "date.h"

Date::Date(int day, int month, int year) : year{year}, month{month}, day{day}
{
}

Date::Date(const Date& other)
{
    day = other.day;
    month = other.month;
    year = other.year;
}
