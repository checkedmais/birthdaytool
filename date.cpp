#include "date.h"
#include <sstream>
#include <ctime>

Date::Date(int day, int month, int year) : year{year}, month{month}, day{day}
{
    
}

Date::Date(const Date& other) : year{other.year}, month{other.month}, day{other.day} 
{
    
}

Date::Date() //current date using <ctime>
{
    time_t now = time(0);
    tm* today = gmtime(&now);
    day = today->tm_mday;
    month = today->tm_mon + 1;
    year = 1900 + today->tm_year;
}


std::string Date::getFormattedDate()
{
    std::stringstream helper;
    helper << (day < 10 ? "0" : "") <<day << "." << (month < 10 ? "0" :"") << month << "." << year;
    return helper.str();
}


/*
 * this makes dates comparable, so it represents which date is earlier in the year
 * years are ignored
 */

bool Date::operator<=(const Date& other)
{
    bool result = (this->month) < other.month;
    if(result)
    {
        return result; // true
    }
    if((this->month) > other.month)
    {
        return result; //false
    }
    if((this->day) <= other.day)
    {
        return true;
    }
    return false;
}

