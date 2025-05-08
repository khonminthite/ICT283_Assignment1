/**
 * @file DateTest.cpp
 * @author Khon Min Thite
 * @brief Unit test for Date
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Date testDate1;
    cout << "Default Constructor" << endl;
    cout << "Day: " << testDate1.GetDay() << endl;
    cout << "Month: " << testDate1.GetMonth() << endl;
    cout << "Year: " << testDate1.GetYear() << endl << endl;

    Date testDate2(2,2,2000);
    cout << "Constructor" << endl;
    cout << "Day: " << testDate2.GetDay() << endl;
    cout << "Month: " << testDate2.GetMonth() << endl;
    cout << "Year: " << testDate2.GetYear() << endl << endl;

    //Check that setters are working correctly
    testDate2.SetDay(24);
    testDate2.SetMonth(10);
    testDate2.SetYear(1995);
    cout << "Test Setters" << endl;
    cout << "Day: " << testDate2.GetDay() << endl;
    cout << "Month: " << testDate2.GetMonth() << endl;
    cout << "Year: " << testDate2.GetYear() << endl;
    return 0;
}
