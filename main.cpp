/**
 *
 * @file Main.cpp
 * @author Khon Min Thite
 * @brief Controls the cin and cout of the program, the logic of the program
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "Logic.h"
#include "Validator.h"
#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Vector.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main ()
{
    //Vector that store all the data of the data file
    Vector<Weather> WindLog;

    Logic LogicHelp;
    Validator Validate;

    string dataSourceFileName = "data/data_source.txt";
    ifstream dataSourceFile(dataSourceFileName);

    if (!dataSourceFile.is_open())
    {
        cout << "Failed to open " << dataSourceFileName << endl;
        return 1;
    }

    string inputFileName;
    getline(dataSourceFile, inputFileName); // read the first line of the file which is the data file name
    dataSourceFile.close();

    ifstream inputFile("data/" + inputFileName);
    if (!inputFile.is_open())
    {
        cout << "Failed to open data file: " << inputFileName << endl;
        return 1;
    }
    LogicHelp.LoadDataFileCSV(inputFile, WindLog);

    inputFile.close();

    bool flag = true;
    string input;
    while(flag)
    {
        LogicHelp.DisplayMenu();
        cin >> input;
        //Check which function user wants to use
        if(input == "1")
        {
            //Ask user which month and year they want to search for and validate those input
            string monthInput, yearInput;
            cout << "Input month to search(1-12)" << endl;
            cin >> monthInput;
            while(Validate.IsInteger(monthInput) == false)
            {
                cout << "Error: invalid month. Expects integer." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
            }
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }
            if(Validate.IsValidDate(stoi(monthInput), stoi(yearInput)) == false)
            {
                cout << "Error: invalid date." << endl;
                break;
            }

            float averageWind = LogicHelp.AverageWindSpeedMonth(WindLog, stoi(monthInput), stoi(yearInput));
            float stdevWind = LogicHelp.StandardDeviationWindSpeedMonth(WindLog, stoi(monthInput), stoi(yearInput));

            //If record for that month and year don't exist then print no data else print the data
            if(averageWind == -1)
            {
                cout << LogicHelp.IntMonthToString(stoi(monthInput)) << " " << yearInput << ": " << "No Data" << endl;
            }
            else
            {
                float convertedWind = LogicHelp.ConvertWindMStoKMH(averageWind);
                cout << LogicHelp.IntMonthToString(stoi(monthInput)) << " " << yearInput << ": " << endl;
                cout << "Average speed: " << convertedWind << " km/h " << endl;
                cout << "stdev: " <<  stdevWind << endl;
            }
        }
        else if (input == "2")
        {
            //Ask user for year to search for and validate the input
            string yearInput;
            cout << "Input year to search(YYYY)" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false ||yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;
            float averageTemp,stdevTemp;

            //For each month of the year get average wind speed and air temperature
            for(int month = 1; month <= 12; month++)
            {
                averageTemp = LogicHelp.AverageAirTemperatureMonth(WindLog, month, stoi(yearInput));
                stdevTemp   = LogicHelp.StandardDeviationAirTemperatureMonth(WindLog, month, stoi(yearInput));

                if(averageTemp == -1)
                {
                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << "No Data" << endl;
                }
                else
                {
                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": average:" << averageTemp << " degrees C, stdev: " << stdevTemp << endl;
                }
            }
        }
        else if (input == "3")
        {
            //Ask user for which year to search and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false || yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }
            cout << yearInput << endl;
            float totalRadiation, convertedRadiation;

            //For each month in a year, search for the total solar radiation
            for(int month = 1; month <= 12; month++)
            {
                totalRadiation = LogicHelp.SumSolarRadiationMonth(WindLog, month, stoi(yearInput));

                if(totalRadiation == -1)
                {
                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << "No Data" << endl;
                }
                else
                {
                    convertedRadiation = LogicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);

                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << convertedRadiation << " kWh/m2" << endl;
                }
            }
        }
        else if(input == "4")
        {
            // Delete the output file if it exists
            remove("WindTempSolar.csv");

            // Ask user for which year to search for and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false || yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            // Write the year onto the output file
            LogicHelp.WriteAppendFile(yearInput);

            bool yearHasData = false; // Flag to check if any data is available for the year

            for(int month = 1; month <= 12; month++)
            {
                float averageWind = LogicHelp.AverageWindSpeedMonth(WindLog, month, stoi(yearInput));
                float stdevWind = LogicHelp.StandardDeviationWindSpeedMonth(WindLog, month, stoi(yearInput));
                float totalRadiation = LogicHelp.SumSolarRadiationMonth(WindLog, month, stoi(yearInput));
                float averageTemp = LogicHelp.AverageAirTemperatureMonth(WindLog, month, stoi(yearInput));
                float stdevTemp = LogicHelp.StandardDeviationAirTemperatureMonth(WindLog, month, stoi(yearInput));

                // Check if any data is available for the month
                if(averageWind != -1 || averageTemp != -1 || totalRadiation != -1)
                {
                    yearHasData = true; // Set the flag indicating that there is data for the year

                    // Convert units if data is available
                    float convertedWind = averageWind != -1 ? LogicHelp.ConvertWindMStoKMH(averageWind) : -1;
                    float convertedRadiation = totalRadiation != -1 ? LogicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation) : -1;

                    // Prepare the output string for the month
                    string outputLine = LogicHelp.IntMonthToString(month);
                    if(convertedWind != -1)
                        outputLine += "," + to_string(convertedWind) + "(" + to_string(stdevWind) + ")";
                    else
                        outputLine += ",";

                    if(averageTemp != -1)
                        outputLine += "," + to_string(averageTemp) + "(" + to_string(stdevTemp) + ")";
                    else
                        outputLine += ",";

                    if(convertedRadiation != -1)
                        outputLine += "," + to_string(convertedRadiation);
                    else
                        outputLine += ",";

                    // Write data to file
                    LogicHelp.WriteAppendFile(outputLine);
                }
            }

            // If no data was found for the entire year, output "No Data"
            if(!yearHasData)
            {
                LogicHelp.WriteAppendFile("No Data");
            }
        }
        else if (input == "5")
        {
            flag = false;
        }
        else
        {
            cout << "Error: Unknown command. Only numbers 1-5 accepted." << endl;
        }

    }
    return 0;
}
