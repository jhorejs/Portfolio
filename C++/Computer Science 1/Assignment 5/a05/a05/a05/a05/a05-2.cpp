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
#include <cstring>

using namespace std;


void showChoices ();
const int MAX = 100;
void item_name(char str[]);
void error();

int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    char item[MAX];
    float price;
    float total=0;
    char  menu;
    
    do
    {
        showChoices();
        cin >> menu;
        cout<< endl;
        
        
        switch (menu)
        {
            case 'a':
                do
                {
                    cout << "Enter item: ";
                    item_name(item);
                    cout << item << ": $";
                    cin >> price;
                    total += price;
                    cout << item << " is: $" << price << endl;
                    cout << "\nAdd or quit? (a/q): " << endl;
                    cin>> menu;
                } while (menu !='q');
                
            case 't':
                cout << "Total: " << total;
                cout << endl;
                
                break;
                
                
            case 'q':
                cout << "Grand Total: " << total++ << endl;
                cout << "enter 'q' to quit: " << endl;
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
    cout << "Add or quite?(a/q):"<< endl;
}

void item_name(char str[]) //
{
    cin.get(str, MAX, '\n');
    while (!cin)
    {
        cin.clear();
        cin.ignore(MAX, '\n');
        cin.get(str, MAX, '\n');
    }
    cin.ignore(MAX, '\n');
}
