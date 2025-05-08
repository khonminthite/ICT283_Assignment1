/**
 *
 * @file Logic.cpp
 * @author Khon Min Thite
 * @brief cpp file for Logic.h
 * @version 0.1
 * @date 29-2-2024
 *
 */

#include "Logic.h"

void Logic::LoadDataFileCSV(ifstream &inputFile, Vector<Weather> &WindLog)
{
    // Keeps track of the number of elements split from a given string
    unsigned int recordCount = 0, rowFieldCount = 0, datetimeCount = 0, dateCount = 0, timeCount = 0;
    // A temp storage for split string
    string line, rowField, datetimeField, dateField, timeField;
    // A temp storage for split string
    Vector<string> columns, splitDateTime, splitDate, splitTime;
    // Temp storage for Date object
    Date tempDate;
    // Temp storage for Time object
    Time tempTime;
    // Initializes ValidationHelper
    Validator Validate;
    // Temp storage for Weather object
    Weather tempLog;
    // input string stream for reading and splitting of elements
    istringstream row, datetime, date, time;

    // Get and ignore CSV header
    getline(inputFile, line);

    string columnNames[] = {"WAST", "S", "SR", "T"};
    int columnIndices[4] = {-1, -1, -1, -1};

    istringstream headerStream(line);
    string columnName;
    int columnIndex = 0;

    while (getline(headerStream, columnName, ','))
    {
        for (int i = 0; i < 4; i++)
        {
            if (columnName == columnNames[i])
            {
                columnIndices[i] = columnIndex;
                break;
            }
        }
        columnIndex++;
    }

    while (getline(inputFile, line))
    {
        if (line != "")
        {
            row.str(line);
            while (getline(row, rowField, ','))
            {
                columns.Insert(rowFieldCount, rowField);
                rowFieldCount++;
            }
            row.clear();

            // Skip record if "WAST" column is empty
            if (columnIndices[0] != -1 && columns[columnIndices[0]] == "")
            {
                cout << "Warning: Empty 'WAST' field detected at row " << recordCount + 1 << endl;
                continue; // Skip to the next record
            }

            // Assuming "WAST" column is always present, but its fields can be empty
            datetime.str(columns[columnIndices[0]]);
            while (getline(datetime, datetimeField, ' '))
            {
                splitDateTime.Insert(datetimeCount, datetimeField);
                datetimeCount++;
            }
            datetime.clear();

            // Handle empty date/time fields
            if (splitDateTime.Size() > 0)
            {
                date.str(splitDateTime[0]);
                while (getline(date, dateField, '/'))
                {
                    splitDate.Insert(dateCount, RemoveLeadingZeros(dateField));
                    dateCount++;
                }
                date.clear();

                if (splitDate.Size() == 3 && Validate.IsValidDate(stoi(splitDate[0]), stoi(splitDate[1]), stoi(splitDate[2])))
                {
                    tempDate.SetDay(stoi(splitDate[0]));
                    tempDate.SetMonth(stoi(splitDate[1]));
                    tempDate.SetYear(stoi(splitDate[2]));
                }
                else
                {
                    cout << "Warning: Invalid date(WAST) detected at row " << recordCount + 1 << endl;
                }

                if (splitDateTime.Size() > 1)
                {
                    time.str(splitDateTime[1]);
                    while (getline(time, timeField, ':'))
                    {
                        splitTime.Insert(timeCount, RemoveLeadingZeros(timeField));
                        timeCount++;
                    }
                    time.clear();

                    if (splitTime.Size() == 2 && Validate.IsValid24HourTime(stoi(splitTime[0]), stoi(splitTime[1])))
                    {
                        tempTime.SetHour(stoi(splitTime[0]));
                        tempTime.SetMinute(stoi(splitTime[1]));
                    }
                    else
                    {
                        cout << "Warning: Invalid time(WAST) detected at row: " << recordCount + 1 << endl;
                    }
                }
            }

            // Validate and set other fields only if they are not empty
            for (int i = 1; i < 4; i++) // Start from 1 to skip "WAST"
            {
                if (columnIndices[i] != -1 && columns[columnIndices[i]] != "" && Validate.IsNumber(columns[columnIndices[i]]))
                {
                    switch (i)
                    {
                        case 1: tempLog.SetWindSpeed(stof(columns[columnIndices[i]])); break;
                        case 2: tempLog.SetSolarRadiation(stof(columns[columnIndices[i]])); break;
                        case 3: tempLog.SetAirTemp(stof(columns[columnIndices[i]])); break;
                    }
                }
                else if (columns[columnIndices[i]] != "") // Only print warning if the field is not empty
                {
                    cout << "Warning: Invalid data detected for " << columnNames[i] << " at row: " << recordCount + 1 << endl;
                }
            }

            // Insert tempLog into Vector WindLog only if all necessary fields are valid
            if (datetimeCount > 0) // Assuming at least date is present
            {
                tempLog.SetDate(tempDate);
                tempLog.SetTime(tempTime);
                WindLog.Insert(recordCount, tempLog);
            }

            // Clear the temp storage vectors
            columns.Clear();
            splitDateTime.Clear();
            splitDate.Clear();
            splitTime.Clear();

            // Reset count
            rowFieldCount = 0;
            datetimeCount = 0;
            dateCount = 0;
            timeCount = 0;

            recordCount++;
        }
    }
}

void Logic::DisplayMenu()
{
    cout << "1. Average wind speed in km/h and standard deviation for a given specified month and year." << endl;
    cout << "2. Average ambient air temperature and sample standard deviation for each month of a specified year." << endl;
    cout << "3. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "4. Average wind speed in km/h(standard deviation), average ambient air temperature(standard deviation) and total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "5. Exit the program." << endl;
}

string Logic::RemoveLeadingZeros(string input)
{
    return input.erase(0, min(input.find_first_not_of('0'), input.size() - 1));
}

float Logic::AverageWindSpeedMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalWindSpeed = 0.0;
    int count = 0;

    //For each record in file, search for matching month and year and add to total wind speed
    //The number of matches are counted
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            totalWindSpeed += array[i].GetWindSpeed();
        }
    }
    //If no record with matching month and year is found then return -1 else return calculated average wind speed
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return totalWindSpeed / count;
    }
}

float Logic::AverageAirTemperatureMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalAirTemperature = 0.0;
    int count = 0;

    //Loops through each record in file, search for match month and year and add to totalAirTemperature
    //The number of matching records are kept track of
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            totalAirTemperature += array[i].GetAirTemperature();
        }
    }

    //If no record with matching month and year is found then return -1 else return calculated average airTemperature
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return totalAirTemperature / count;
    }
}

float Logic::SumSolarRadiationMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalSolarRadiation = 0.0;
    int count = 0;

    //Loops through each record in file, search for matching month and year and add to total solar Radiation
    //The number of matching records are kept track of
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            if (array[i].GetSolarRadiation() > 100)
            {
                totalSolarRadiation += array[i].GetSolarRadiation();
            }
        }
    }

    //If no records with matching month and year is found then return -1 else return the totalSolarRadiation
    if (count > 0)
    {
        return totalSolarRadiation;
    }
    else
    {
        return -1;
    }
}

float Logic::StandardDeviationWindSpeedMonth(const Vector<Weather>& array, const int month, const int year)
{
    Vector<float> windSpeeds;
    int count =  0;

    for (unsigned int i =  0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            windSpeeds.Insert(count -  1, array[i].GetWindSpeed());
        }
    }

    if (count ==  0)
    {
        return -1; // No data for the specified month and year
    }

    float sum =  0.0;
    for (unsigned int i =  0; i < windSpeeds.Size(); i++)
    {
        sum += windSpeeds[i];
    }
    float mean = sum / count;

    float sq_sum =  0.0;
    for (unsigned int i =  0; i < windSpeeds.Size(); i++)
    {
        float diff = windSpeeds[i] - mean;
        sq_sum += diff * diff;
    }
    float variance = sq_sum / (count -  1);

    float stdev = sqrt(variance);

    return round(stdev *  100) /  100;
}

float Logic::StandardDeviationAirTemperatureMonth(const Vector<Weather>& array, const int month, const int year)
{
    Vector<float> airTemperatures;
    int count =  0;

    // Loop through the Vector to find all entries for the specified month and year
    for (unsigned int i =  0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            airTemperatures.Insert(count -  1, array[i].GetAirTemperature()); // Assuming GetAirTemp() returns the air temperature
        }
    }

    // If no data for the specified month and year, return -1
    if (count ==  0)
    {
        return -1; // No data for the specified month and year
    }

    float sum =  0.0;
    // Calculate the sum of all air temperatures
    for (unsigned int i =  0; i < airTemperatures.Size(); i++)
    {
        sum += airTemperatures[i];
    }
    float mean = sum / count; // Calculate the mean air temperature

    float sq_sum =  0.0;
    // Calculate the sum of the squared differences from the mean
    for (unsigned int i =  0; i < airTemperatures.Size(); i++)
    {
        float diff = airTemperatures[i] - mean;
        sq_sum += diff * diff;
    }
    float variance = sq_sum / (count -  1); // Calculate the variance

    // Calculate the standard deviation from the variance
    float stdev = sqrt(variance);

    return round(stdev * 100) /100;
}

string Logic::IntMonthToString(const int &month)
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        cout << endl << "Error converting int month to string" << endl;
        return "ERROR";
    }
}

float Logic::ConvertWindMStoKMH(const float &windSpeed)
{
    return windSpeed * 3.6;
}

float Logic::ConvertSolarRadiationWMtoKWH(const float &radiation)
{
    if (radiation > 0)
    {
        return (radiation/6) /  1000;
    }
    return 0;
}

void Logic::WriteAppendFile(const string &output)
{
    ofstream OutputFile("WindTempSolar.csv", ofstream::app);
    //appends the string and proceed to next line
    OutputFile << output << endl;

    OutputFile.close();
}
