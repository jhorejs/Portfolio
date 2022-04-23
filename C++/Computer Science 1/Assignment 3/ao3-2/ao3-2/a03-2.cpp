//
//  a03.cpp
//
//  Sources: none
//  Created by Joshua Horejs on 4/19/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

int main()
{
    // Variables
    char input, driver, height;
    double passenger, youth, bike;
    double length, senior;
    double a = 12.95, b = 6.45, c = 2;
    
    
    // Intro
    cout << fixed << setprecision (2);
    
    cout << "Welcome to the Josh Horejs Fare Calculator" << endl;
    cout << endl;
    
    cout << "Are you driving a vehicle onto the ferry? (Y/N): " << endl;
    cin >> input;
    cout << endl;
    
    if (input == 'n')
    {
        
        cout << "How many passengers in your group adults(age 19 – 64)?: " << endl;
        cin >> passenger;
        cout << endl;
        
        cout << "Senior Citizens (65 or older), or Disabled Persons: " << endl;
        cin >> senior;
        cout << endl;
        
        cout << "Youth (5 -18 years old): " << endl;
        cin >> youth;
        cout << endl;
        
        cout << "How many people in your group are traveling with a bicycle?: " << endl;
        cin >> bike;
        cout << endl;
        
        cout << "Your total fare is $" << ( passenger * a ) + (( youth + senior ) * b ) + ( bike *c ) << endl;
        cout << "thank you for using Joshua Horejs calculator" << endl;
        cout << "Enter q to quit: ";
        cin >> input;
        exit(1);
        
    }

    else if (input == 'y')
    {
        cout << "Is the driver a senior citizen (65 or over) or disabled? (y/n): " <<endl;
        cin >> driver;
        cout << endl;
    
        cout << "How many passengers in your vehicle? (excluding the driver) Adults (age 19 – 64): " << endl;
        cin >> passenger;
        cout << endl;
    
        cout << "Senior Citizens (65 or older), or Disabled Persons: " << endl;
        cin >> senior;
        cout << endl;
        
        cout << "Youth (5 -18 years old): " << endl;
        cin >> youth;
        cout << endl;
    
        cout << "Is your vehicle over 7 feet, 6 inches in height? (y/n): " << endl;
        cin >> height;
        cout << endl;
    
        cout << "How long is your vehicle in feet?: " << endl;
        cin >> length;
        cout << endl;
    
        cout << "How many people in your group are traveling with a bicycle?: " << endl;
        cin >> bike;
        cout << endl;
    
        if (length >= 40)
        {
            if (driver == 'y') // w/ senior
            
            {
                cout << "Your total fare is $" << (232.95 + (passenger * a ) + ((youth + senior ) * b) + (bike *c)) << endl;
                cout << "thank you for using Joshua Horejs calculator" << endl;
            }
        
            else if (driver == 'n')
            
            {
                cout << "Your total fare is $" << 232.95 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                cout << "thank you for using Joshua Horejs calculator" << endl;
            }
        }
    
        // 40 under
        else if (length >= 30)
        {
            if (driver =='y') // w/ senior
            
            {
                cout << "Your total fare is $" << 185.95 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                cout << "thank you for using Joshua Horejs calculator" << endl;
            }
        
        else if (driver == 'n')
            
        {
            cout << "Your total fare is $" << 185.95 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
            cout << "thank you for using Joshua Horejs calculator" << endl;
        }
        }
        
        // 30 under
        else if (length >= 22)
        {
            if ( height >= 7.5) // over 7.5
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 138.95 + (passenger * a ) + ((youth + senior) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 138.95 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        
            else if ( height <= 7.5)
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 69.6 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 69.6 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        }
    
        // 22 & under
        else if (length >= 14)
        {
            if ( height >= 7.5) // over 7.5'
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 44.75 + 38.5 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 44.75 + 45 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        
            else if ( height <= 7.5)
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 38.5 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 45 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        }
    
        // 14 & under
        else if (length >= 1)
        {
            if ( height  >= 7.5 )
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 35.80 + 29.55 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 35.80 + 36.05  + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        
            else if ( height <= 7.5)
            {
                if (driver =='y') // w/ senior
                {
                    cout << "Your total fare is $" << 29.55 + (passenger * a ) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            
                else if (driver == 'n')
                {
                    cout << "Your total fare is $" << 36.05 + ((passenger ) * a) + ((youth + senior ) * b) + (bike *c) << endl;
                    cout << "thank you for using Joshua Horejs calculator" << endl;
                }
            }
        }
    
    // Exit statement
    cout << endl;
    cout << "Enter q to quit: ";
    cin >> input;
    exit(1);
    
    
    return 0;
    
}
}