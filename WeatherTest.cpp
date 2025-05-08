/**
 *
 * @file WeatherTest.cpp
 * @author Khon Min Thite
 * @brief Unit Test for Weather
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "WEATHER.H"
#include <iostream>

using namespace std;

int main()
{
    //Check that constructor correctly initialize the data and all getters can retrieve the data
    cout << " Check constructor " << endl;
    Weather testWeather;
    cout << " Date:            " << testWeather.GetDate().DisplayFullDate() << endl;
    cout << " Time:            " << testWeather.GetTime().Display24HTime() << endl;
    cout << " Wind Speed:      " << testWeather.GetWindSpeed() << endl;
    cout << " Solar Radiation: " << testWeather.GetSolarRadiation() << endl;
    cout << " Air Temperature: " << testWeather.GetAirTemperature() << endl;
    cout << endl;

    //Check that setters are working correctly
    cout << " Test Setters " << endl;
    Date anotherDate(16,3,2016);
    Time anotherTime(9,15);

    testWeather.SetDate(anotherDate);
    testWeather.SetTime(anotherTime);
    testWeather.SetWindSpeed(11.1);
    testWeather.SetSolarRadiation(23.15);
    testWeather.SetAirTemp(78.25);

    cout << " Date:            " << testWeather.GetDate().DisplayFullDate() << endl;
    cout << " Time:            " << testWeather.GetTime().Display24HTime() << endl;
    cout << " Wind Speed:      " << testWeather.GetWindSpeed() << endl;
    cout << " Solar Radiation: " << testWeather.GetSolarRadiation() << endl;
    cout << " Air Temperature: " << testWeather.GetAirTemperature() << endl;

    return 0;
}
