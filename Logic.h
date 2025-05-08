/**
 *
 * @file Logic.h
 * @author Khon Min Thite
 * @brief A helper class for main.cpp
 * Handles task such as displaying menu, converting of data types, addition.
 * Function for writing to file will be including in this helper class in this program as there is only 1 function in this program that will write output to file.
 * @version 0.1
 * @date 29-2-2024
 *
 */

#ifndef LOGIC_H
#define LOGIC_H

#include "Vector.h"
#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Validator.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Logic
{
public:

    /**
     * @brief Load the data of an input data file and store it in a Vector
     *
     * @param inputFile - The input file
     * @param WindLog - The Vector
     */
    void LoadDataFileCSV(ifstream& inputFile, Vector<Weather>& WindLog);

    /**
     * @brief Displays the menu
     *
     */
    void DisplayMenu();

    /**
     * @brief Removes leading 0 from a given string
     *
     * @param input - The input string
     * @return string - The string after removing leading 0
     */
    string RemoveLeadingZeros(string input);

    /**
     * @brief Search and Calculates the average wind speed of a month when given the month and year to search for
     *
     * @param array - The Vector to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The average wind speed of a month
     */
    float AverageWindSpeedMonth(const Vector<Weather>& array, const int month, const int year);

    /**
     * @brief Search and Calculates the average air temperature of a month when given the month and year to search for
     *
     * @param array - The Vector to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The average air temperature of a month
     */
    float AverageAirTemperatureMonth(const Vector<Weather>& array, const int month, const int year);

    /**
     * @brief Search and Calculates the total solar radiation of a month when given the month and year to search for
     *
     * @param array - The Vector to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The total solar radiation of a month
     */
    float SumSolarRadiationMonth(const Vector<Weather>& array, const int month, const int year);

    /**
     * @brief Converts a given integer month to string month
     *
     * @param month - A month in integer
     * @return string - A month in string
     */
    string IntMonthToString(const int& month);

    /**
     * @brief Converts wind speed m/s  to km/h
     *
     * @param windSpeed - wind speed in m/s
     * @return float - wind speed in km/h
     */
    float ConvertWindMStoKMH(const float& windSpeed);

    /**
     * @brief Converts solar radiation from W per 10 min to KiloWattHour
     *
     * @param radiation - Radiation in W per 10 min
     * @return float - Radiation in KiloWattHour
     */
    float ConvertSolarRadiationWMtoKWH(const float& radiation);

    /**
     * @brief Search and Calculates the standard deviation for wind speed of a month when given the month and year to search for
     *
     * @param array - The Vector to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The standard deviation for wind speed of a month
     */
    float StandardDeviationWindSpeedMonth(const Vector<Weather>& array, const int month, const int year);

    /**
     * @brief Search and Calculates the standard deviation for ambient air temperature of a month when given the month and year to search for
     *
     * @param array - The Vector to search in
     * @param month - The month to search for
     * @param year - The year to search for
     * @return float - The standard deviation for air temperature of a month
     */
    float StandardDeviationAirTemperatureMonth(const Vector<Weather>& array, const int month, const int year);

    /**
     * @brief Create/Appends a given string into "WindTempSolar.csv"
     *
     * @param output - The string to append
     */
    void WriteAppendFile(const string& output);

};

#endif

