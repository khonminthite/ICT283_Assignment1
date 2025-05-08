/**
 *
 * @file Validator.cpp
 * @author Khon Min Thite
 * @brief .CPP file for validator class
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "Validator.h"

bool Validator::IsValidDate(const int& day,const int& month,const int& year)
{
    if(year > 9999 || year < 1000)
    {
        return false;
    }
    if(month < 1 || month > 12)
    {
        return false;
    }
    if(day < 1 || day > 31)
    {
        return false;
    }

    //Checks if it is february before checking if it is leap year. If not leap year than day cannot be more than 28
    if(month == 2)
    {
        if(IsLeapYear(year))
        {
            return (day <= 29);
        }
        else
        {
            return (day <= 28);
        }
    }
    //Months that has only 30 days
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day <= 30);
    }

    return true;
}

bool Validator::IsValidDate(const int& month,const int& year)
{
    if(year > 9999 || year < 1000)
    {
        return false;
    }
    if(month < 1 || month > 12)
    {
        return false;
    }

    return true;
}

bool Validator::IsValidMonth(const int& month)
{
    if(month < 1 || month > 12)
    {
        return false;
    }

    return true;
}

bool Validator::IsLeapYear(const int& year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
bool Validator::IsValid24HourTime(const int& hour, const int& minute)
{
    return (hour >= 0 && hour <= 24) && (minute >= 0 && minute <= 59);
}


bool Validator::IsNumber(const string& input )
{
    //Checks that it can only be positive numbers that may have a decimal point after at least a digit and has no leading zeros
    return regex_match( input, regex( "^(?=.+)(?:[1-9]\\d*|0)?(?:\\.\\d+)?$" ) );
}

bool Validator::IsInteger(const string& input)
{
    //Checks that it can only be positive number that does not have decimal point and has no leading zeros
    return regex_match( input, regex( ( "^(?=.+)(?:[1-9]\\d*|0)$" ) ) );
}
