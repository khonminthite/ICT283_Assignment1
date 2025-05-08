/**
 *
 * @file Weather.h
 * @author Khon Min Thite
 * @brief Class for storing Wind log details such as date, time, wind speed, solar radiation and air temperature. Each Object correspond to a line of record from data file
 * @version 0.1
 * @date 29-2-2024
 *
 */

#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#include "Date.h"
#include "Time.h"

using namespace std;

class Weather
{
public:

    /**
     * @brief Construct a new Weather object
     */
    Weather();

    /**
     * @brief Destroy the Weather object
     */
    ~Weather();

    /**
     * @brief Get date
     *
     * @return const Date& - Date object
     */
    const Date & GetDate() const;

    /**
     * @brief Get time
     *
     * @return const Time&  -Time Object
     */
    const Time & GetTime() const;

    /**
     * @brief Get wind Speed
     *
     * @return float - Wind Speed
     */
    float GetWindSpeed() const;

    /**
     * @brief Get solar Radiation
     *
     * @return float - Solar Radiation
     */
    float GetSolarRadiation() const;

    /**
     * @brief Get air Temperature
     *
     * @return float - Ambient Air Temperature
     */
    float GetAirTemperature() const;

    /**
     * @brief Set date
     *
     * @param date - Date object
     */
    void SetDate(Date & date);

    /**
     * @brief Set time
     *
     * @param time - Time object
     */
    void SetTime(Time & time);

    /**
     * @brief Set wind Speed
     *
     * @param windSpeed - wind speed
     */
    void SetWindSpeed(float windSpeed);

    /**
     * @brief Set solar Radiation
     *
     * @param solar - Solar Radiation
     */
    void SetSolarRadiation(float solar);

    /**
     * @brief Set air Temperature
     *
     * @param temp - Ambient Air Temperature
     */
    void SetAirTemp(float temp);

private:

    //Stores the date part includes the day, month & year
    Date m_date;
    //Stores the time part include hour and minutes
    Time m_time;
    //Stores the wind speed in m/s for each record
    float m_windSpeed;
    //Stores the solar radiation in W/m^2
    float m_solarRad;
    //Stores the ambient air temperature in degree C
    float m_airTemp;
};

#endif
