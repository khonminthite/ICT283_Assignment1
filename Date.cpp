/**
 * @file Date.cpp
 * @author Khon Min Thite
 * @brief .cpp file for Date.h
 * @version 0.1
 * @date 2024-02-18
 *
 */

#include "DATE.H"

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
    m_day = d;
    m_month = m;
    m_year = y;
}

    //Getters
int Date::GetDay() const
{
    return m_day;
}
int Date::GetMonth() const
{
    return m_month;
}
int Date::GetYear() const
{
    return m_year;
}

    //Setters
void Date::SetDay(unsigned int d)
{
    m_day = d;
}
void Date::SetMonth(unsigned int m)
{
    m_month = m;
}
void Date::SetYear(unsigned int y)
{
    m_year = y;
}


string Date::DisplayFullDate() const
{
    return to_string(m_day) + "/" + to_string(m_month) + "/" + to_string(m_year);
}

istream& operator>>(istream& input, Date& date)
{
    int day, month, year;
    char delimiter;

    if (input >> day >> delimiter >> month >> delimiter >> year)
    {
        date.SetDay(day);
        date.SetMonth(month);
        date.SetYear(year);
    }

    return input;

}

ostream& operator<<(ostream& os, const Date& date)
{
    os << " Date   : "  << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear();

    return os;
}
