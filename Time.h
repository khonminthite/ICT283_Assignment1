/**
 * @file Time.h
 * @author Khon Min Thite
 * @brief used to create Time object
 * @version 0.1
 * @date 18-2-2024
 *
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
public:
    /**
     * @brief Construct a new Time object
     *
     */
    Time():m_hour(-1),m_minute(-1) {};

    /**
     * @brief Construct a new Time object
     *
     * @param h hour
     * @param m minute
     */
    Time(unsigned int h, unsigned int m);

    /**
     * @brief Destroy the Time object
     *
     */
    ~Time() {};

    /**
     * @brief Get the Hour object
     *
     * @return int hour
     */
    int GetHour() const;

    /**
     * @brief Get the Minute object
     *
     * @return int minute
     */
    int GetMinute() const;

    /**
     * @brief Set the Hour object
     *
     * @param h hour
     */
    void SetHour(unsigned int h);

    /**
     * @brief Set the Minute object
     *
     * @param m minute
     */
    void SetMinute(unsigned int m);

    /**
     * @brief Display hours and minutes
     *
     * @return string
     */
    string Display24HTime() const;

private:
    int m_hour;
    int m_minute;
};


/**
* @brief Overloaded insertion operator for output.
* @param os The output stream.
* @param time The time object to output.
* @return The output stream.
*/
ostream& operator<<(ostream& os, const Time& time);

/**
 * @brief Overloaded extraction operator for input.
 * @param is The input stream.
 * @param time The time object to input into.
 * @return The input stream.
 */
istream& operator>>(istream& is, Time& time);

#endif
