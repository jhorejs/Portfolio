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
    char input;
    double passenger, senior, youth, bike, hover7;
    double length, h;
    double a = 12.95, b = 6.45, c = 2;
    
    
    // Intro
    cout << fixed << setprecision (2);
    
    cout << "Welcome to the Josh Horejs Fare Calculator" << endl;
    cout << endl;
    
    cout << "Are you driving a vehicle onto the ferry? (Y/N): " << endl;
    cin >> input;
    cout << endl;
        
    cout << "Is the driver a senior citizen (65 or over) or disabled? (y/n): " <<endl;
    cin >> senior;
    cout << endl;
        
    cout << "How many passengers in your vehicle? (excluding the driver) Adults (age 19 – 64): " << endl;
    cin >> senior;
    cout << endl;
        
    cout << "Youth (5 -18 years old): " << endl;
    cin >> youth;
    cout << endl;
        
    cout << "Is your vehicle over 7 feet, 6 inches in height? (y/n): " << endl;
    cin >> hover7;
    cout << endl;
    
    cout << "How long is your vehicle in feet?: " << endl;
    cin >> length;
    cout << endl;
    
    cout << "How many people in your group are traveling with a bicycle?: " << endl;
    cin >> bike;
    cout << endl;

    // if else string
    
    
        // 50 under
    if (length >= 40)
    {
        if (senior >= 1) // w/ senior
            
        {
            cout << "Total: " << (232.95 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c)) << endl;
        }
        
        else if (senior == 0)
            
        {
            cout << "Total: " << 232.95 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
        }
    }
        
        // 40 under
   else if (length >= 30)
   {
       if (senior >= 1) // w/ senior
           
       {
           cout << "Total: " << 185.95 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
       }
       
       else if (senior == 0)
           
       {
           cout << "Total: " << 185.95 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
       }
   }
        // 30 under
   else if (length >= 22)
   {
       if ( h >= 7.5) // over 7.5
       {
           if (senior >= 1) // w/ senior
               
           {
               cout << "Total: $" << 138.95 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
           }
           
           else if (senior == 0)
               
           {
               cout << "Total: $" << 138.95 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
           }
       }
       
       else if ( h <= 7.5)
           
       {
           if (senior >= 1) // w/ senior
               
           {
               cout << "Total: $" << 69.6 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
           }
           
           else if (senior == 0)
               
           {
               cout << "Total: $" << 69.6 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
           }
       }
   }
   
        // 22 & under
   else if (length >= 14)
   {
       if ( h >= 7.5) // over 7.5'
           
       {
           if (senior >= 1) // w/ senior
               
           {
               cout << "Total: $" << 44.75 + 38.5 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
           }
           
           else if (senior == 0)
               
           {
               cout << "Total: $" << 44.75 + 45 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
           }
       }
       
       else if ( h <= 7.5)
           
       {
           if (senior >= 1) // w/ senior
               
           {
               cout << "Total: $" << 38.5 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
           }
           
           else if (senior == 0)
               
           {
               cout << "Total: $" << 45 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
           }
       }
   }
        
        
    // 14 & under
   else if (length >= 1)
    {
        if ( h  >= 7.5 )
        {
            if (senior >= 1) // w/ senior
        
            {
                cout << "Total: $" << 35.80 + 29.55 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
            }
            
            else if (senior == 0)
            
            {
                cout << "Total: $" << 35.80 + 36.05  + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
            }
        }
        
        else if ( h <= 7.5)
        
        {
            if (senior >= 1) // w/ senior
            
            {
                cout << "Total: $" << 29.55 + (passenger * a ) + ((youth + senior - 1) * b) + (bike *c) << endl;
            }
            
            else if (senior == 0)
            
            {
                cout << "Total: $" << 36.05 + ((passenger - 1) * a) + ((youth + senior ) * b) + (bike *c) << endl;
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