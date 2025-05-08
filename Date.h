/**
 * @file Date.h
 * @author Khon Min Thite
 * @brief used to create date object
 * @version 0.1
 * @date 18-2-2024
 *
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

/**
 * @class Date
 * @brief Represents a date with day, month, and year information.
 */
class Date
{
public:

    /**
     * @brief Construct a new Date object and set all variable to 0
     *
     */
    Date():m_day(-1), m_month(-1), m_year(-1) {};

    /**
     * @brief Construct a new Date object
     *
     * @param d - day data
     * @param m - month data
     * @param y - year data
     */
    Date(unsigned int d, unsigned int m, unsigned int y);

    /**
     * @brief Destroy the Date object
     *
     */
    ~Date() {};

    /**
     * @brief Get m_day
     *
     * @return int - day data
     */
    int GetDay() const;

    /**
     * @brief Get m_month
     *
     * @return int - month data
     */
    int GetMonth() const;

    /**
     * @brief Get m_year
     *
     * @return int - year data
     */
    int GetYear() const;

    /**
     * @brief Set m_day
     *
     * @param d - day data
     */
    void SetDay(unsigned int d);

    /**
     * @brief Set m_month
     *
     * @param m - month data
     */
    void SetMonth(unsigned int m);

    /**
     * @brief Set m_year
     *
     * @param y - year data
     */
    void SetYear(unsigned int y);

    /**
     * @brief construct and return the full date in DD/MM/YYYY format
     *
     * @return string - full date
     */
    string DisplayFullDate() const;

private:
    int m_day;
    int m_month;
    int m_year;
};

/**
* @brief Overloaded insertion operator for output.
* @param os The output stream.
* @param date The Date object to output.
* @return The output stream.
*/
ostream& operator<<(ostream& os, const Date& date);

/**
 * @brief Overloaded extraction operator for input.
 * @param is The input stream.
 * @param date The Date object to input into.
 * @return The input stream.
 */
istream& operator>>(istream& is, Date& date);

#endif
