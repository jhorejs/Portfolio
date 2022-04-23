//
//  main.cpp
//  lab06-3
//  sources: none
//  Created by Joshua Horejs on 5/3/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//

/*
 *********** ASSIGNMENT **********
 Write a program that mimics a calculator in a shopping cart. Your program must display a simple menu to the user with the following choices:
 (a) Add an item to the cart.
 (t) Total.
 (q) Quit.
 If the choice is:
 (a), you must let the user add an item by name (any text with spaces). Then you must ask for the price of the item (read in double), and then display the total so far immediately. That would be the running total. Then display the menu again.
 
 (t), give them the total so far, and then display the menu again.
 
 (q), then give them the total and quit the program.
 
 
 ***********   DESIGN CONSIDERATIONS *************
 
 1. You must use loops, since this is an exercise in loops.
 2. No global variables. All variables must be inside main().
 3. You must be able to read text with spaces, so use getline() for the string data type.
 4. The menu must display continuously after every turn, until the user enters ‘q’ to quit.
 5. There is no need to store the past items. All you need to do is to output and maintain a running total, to output to the user.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


void showChoices ();


int main()
{
    // variables
    string item;
    int price;
    int total;
    double grandtotal;
    char  menu;
    cout << setprecision(2) << endl;
    
    do
    {
        showChoices();
        cin >> menu;
        cout<< endl;
        
        
        
        switch (menu)
        {
            case 'a':
                cout << setprecision(2)<< endl;
                cout << "Enter item: " << endl;
                cin >> item;
                
                cout << endl;
                
                cout << "Enter price of " << item << ": " << endl;
                cin >> price;
                total +=price;
                cout << endl;
                
                
                cout <<"The total for "<< item << " is " << price << endl;
                cout << endl;
                
                
            case 't':
                cout << "Subtotal: " << endl;
                cout << total;
                cout << endl;
                
                break;
                
                
            case 'q':
                cout << "Grand Total: " << total++ << endl;
                cout << "enter 'q' to quit: " << endl;
                cout << endl;
                break;
                
            default:
                cout << "Invalid input." << endl;
                
        }
    }
    while (menu != 'q');
    return 0;
}

void showChoices()
{
    cout << "Select an option" << endl;
    cout << endl;
    cout << "a. Add an item to the cart:" << endl;
    cout << "t. Total: " << endl;
    cout << "q. Quit" << endl;
    cout << endl;
}


