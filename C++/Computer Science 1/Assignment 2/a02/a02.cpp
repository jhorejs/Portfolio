//
//  a02.cpp
//
//  Sources: None.
//
//
//  Created by Josh Horejs on 4/18/15.
//  Copyright (c) 2015 Josh Horejs. All rights reserved.
//

/*
 CS 161 - Gayathri Iyer     Assignment #2 - Fuel Consumption Assignment:
 
 Write a program to:
 evaluate the fuel consumption of a car.
 mileage at the start and end of the journey,
 indicate fuel level in the tank at the start and end of the trip.
 
 output:
 fuel used,
 miles travelled,
 Overall fuel consumption in m.p.g.
 
 In many countries using the metric system, car fuel consumptions are measured in liters of fuel required to
 travel 100 kilometers.
 
 Modify your solution so that the output now specifies:
 distance travelled in kilometers as well as in miles,
 fuel consumed in liters as well as in gallons,
 consumption in liters per 100 kilometers as well as in miles per gallon.
 
 Use const for the conversion factors between:
 miles and kilometers,
 gallons and liters.
 
 Design Considerations:
 
 1. Your file should be named a02.cpp.
 2. No global variables. All variables must be inside main().
 3. Your output should be formatted to 2 decimal places.
 4. 1mile = 1.609kms
 5. 1gallon = 3.785liters
 6. Must use constants for the above conversion factors.
 7. Please download the picture file and see what the output should look like.
 8. Your program should ask the questions in the same order.
 
 input:
 Starting mileage,
 ending mileage,
 fuel at start,
 fuel at end.
 
 You need to calculate the rest of the information.
 
 9. You should use the lessons you have learned until this point.
 10.Points will be awarded for the following attributes of your solution:
 */

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

// Constants
const double mTOk = 1.609;
const double gTOl = 3.785;


int main()
{
    // Variables
    double sOdom;
    double eOdom;
    double sFuel;
    double eFuel;
    
    
    
    // Input from user
    cout << "Please enter the following travel information." << endl;
    cout << endl;
    
    cout << "Pre-travel Odometer miles: ";
    cin >> sOdom;
    cin.clear();
    cin.ignore(100, '\n');
    
    cout << "Post-travel Odometer miles: ";
    cin >> eOdom;
    cin.clear();
    cin.ignore(100, '\n');
    
    cout << "Pre-travel gas level: ";
    cin >> sFuel;
    cin.clear();
    cin.ignore(100, '\n');
    
    cout << "Post-travel gas level: ";
    cin >> eFuel;
    cin.clear();
    cin.ignore(100, '\n');
    cout << endl;
    
    // Output calculation from user input
    cout << fixed << showpoint << setprecision(2);
    cout << setw(20) << right << "Started with:" << right<< setw(10) << sOdom << " mi" << endl;
    
    cout << setw(20) << right << "Ended with:" << right << setw(10) << eOdom << " mi" << endl;
    
    cout << setw(20) << right << "Start fuel:" << right << setw(10) << sFuel << " g" << endl;
    
    cout << setw(20) << right << "End fuel:" << right << setw(10) << eFuel << " g" << endl;
    
    cout << setw(20) << right << "Miles traveled:" << right << setw(10) << eOdom - sOdom  << " mi" << endl;
    
    cout << setw(20) << right << "Fuel used:" << right << setw(10) << sFuel - eFuel<< " g" << endl;
    
    cout << setw(20) << right << "Miles per gallon:" << right << setw(10) << (eOdom - sOdom) / (sFuel - eFuel)  << " mpg" << endl;
    cout << endl;
    
    // Metric Convertions
    cout << setw(20) << right << "Kilometers traveled:" << right << setw(10) << eOdom - sOdom * mTOk << " kms" << endl;
    
    cout << setw(20) << right << "liters of fuel used:" << setw(10) << right << sFuel - eFuel * gTOl << " l" << endl;
    
    cout << setw(20) << right << "liters per 100kms:" << right << setw(10) << right << 100 / (gTOl * ((eOdom - sOdom) / (sFuel - eFuel))) << " lpk" << endl;
    cout << endl;
    
    
    return 0;
}