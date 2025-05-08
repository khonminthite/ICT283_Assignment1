/**
 * @file Time.cpp
 * @author Khon Min Thite
 * @brief .cpp for Time.h
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "Time.h"

Time::Time(unsigned int h, unsigned int m)
{
    m_hour = h;
    m_minute = m;
}

int Time::GetHour() const
{
    return m_hour;
}

int Time::GetMinute() const
{
    return m_minute;
}

void Time::SetHour(unsigned int h)
{
    m_hour = h;
}

void Time::SetMinute(unsigned int m)
{
    m_minute = m;
}

string Time::Display24HTime() const
{
    string result;
    if(m_hour < 10)
    {
        result += "0" + to_string(m_hour);
    }
    else
    {
        result += to_string(m_hour);
    }
    result += ":";
    if(m_minute < 10)
    {
        result += "0" + to_string(m_minute);
    }
    else
    {
        result += to_string(m_minute);
    }

    return result;
}

// Overloaded extraction operator for input
istream& operator>>(istream& input, Time& time)
{
    int hour, minute;
    char delimiter;

    // Extract day, month and year
    if (input >> hour >> delimiter >> minute)
    {
        time.SetHour(hour);
        time.SetMinute(minute);
    }
    return input;
}

// Overloaded insertion operator for output
ostream& operator<<(ostream& os, const Time& time)
{
    os << " Time   : "  << time.GetHour() << ":" << time.GetMinute();
    return os;
}
