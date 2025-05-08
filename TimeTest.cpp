/**
 * @file TimeTest.cpp
 * @author Khon Min Thite
 * @brief Unit test for Time.h
 * @version 0.1
 * @date 29-2-2024
 *
 *
 */
#include "TIME.H"

#include <iostream>

using namespace std;

int main()
{
    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Time testTime1;
    cout << " Default Constructor" << endl;
    cout << " Hour:   " << testTime1.GetHour() << endl;
    cout << " Minute: " << testTime1.GetMinute() << endl;
    cout << endl;

    Time testTime2(10,30);
    cout << " Constructor" << endl;
    cout << " Hour:   " << testTime2.GetHour() << endl;
    cout << " Minute: " << testTime2.GetMinute() << endl;
    cout << endl;

    //Check that setters are working correctly
    testTime2.SetHour(9);
    testTime2.SetMinute(56);

    cout << " Test Setters" << endl;
    cout << " Hour:   " << testTime2.GetHour() << endl;
    cout << " Minute: " << testTime2.GetMinute() << endl;

    return 0;
}
