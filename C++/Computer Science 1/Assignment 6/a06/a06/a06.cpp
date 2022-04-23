//
//  main.cpp
//  a06
//  Sources: None
//  Created by Joshua Horejs on 5/11/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//


/*
 Assignment:
 CS 161 - Gayathri Iyer Assignment #6 - Functions
 
 ￼Write functions to:
 1) Write the main program to test the functions using a menu.
 
 2) case: 'a' || 'A'
 A. Read positive numbers from the user, Return the largest number and outputs it. using "int largest();"
 B. The function does not take any parameters.
 C. Return an int, which is the largest number to main.
 D. Use a loop to read the numbers until the user enters -1 to quit.
 F. Keep track of the largest number. When the user enters -1, stop reading and return the largest number to the main function. Do NOT use an array for this program.
 
 3) case 'b'|| 'B'
 A. Write a function that takes as a parameter an integer
 B. Return the number of: odd, even and zero digits.
 C. Write as void function since a function cannot return 3 values. Here is your function signature: 
    "void numberCount(int number, int &oddCount, int &evenCount, int &zeroCount);"
 D. EXAMPLE; if the user enters 34873045, the number of odd digits is 4, even digits is 3, and zeros is 1. You must use integers, do not use strings.
 
 4) Menu:
 Welcome to my program! Please choose one of the following:
 (a) Find the largest of a list of positive numbers (-1 to quit).
 (b) Given a positive number, display the number of even, odd and zero digits in the number.
 (c) quit this program.
 
 5) Use a **** SWITCH or IF *** statements and output the corresponding answer. Loop this menu so it continues to display after each turn until the user enters ‘c’ to quit.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

using namespace std;

//A
int largest()
{
    int number;
    int greator= 0;
    
    do
    {
        cout << "Enter positive numbers (-1 to quit): " << endl;
        cin >> number;
        
        if(greator < number)
            greator = number;
    }
    while (number != -1);
    
    cout << "Greatest integer: " << greator << "\n" << "\n" << endl;
    return 0;
}

//B
void numberCount (int number, int& zero, int& odd, int& even)
{
    int digit;
    cout << "Enter a number: " << endl;
    cin >> number;
    do
    {
        digit = number % 10;
        if (digit == 0)
            zero+=1;
        else if (digit % 2 == 0)
            even+=1;
        else
            odd+=1;
        
        number = number / 10;
    }
    while (number > 0);
    
    
    cout << "Your entry " << number << " contains; " << "\n" << "Evens: " << even << "\n" << "Odd's: " << odd<< "\n" << "Zeros: " << zero << "\n"<<endl;
    
}

    
int main()
{
    char ch;
    int digit=0, number=0, odd=0, even=0, zero=0;
    
    do
    {
        cout << "Welcome to my Program! Please choose one of the following: " << "\n" << endl;
        cout << "(a) Find the largest of a list of positive numbers (-1 to quit)." << endl;
        cout << "(b) Given a positive number, display the number of even, odd and zero digits in the number."<< endl;
        cout << "(c) quit this program." << "\n" <<  endl;
        cin >> ch;
        cout<< endl;
        
        switch (ch)
        {
            case 'a':
            case 'A':
                largest();
                break;
                
            case 'b':
            case 'B':
                numberCount(number, zero, odd, even);
                break;
                
            case 'c':
            case 'C':
                cout << "thank you come again: " << endl;
                exit('c');
                break;
                
            default:
                cout << "invalid input";
        }
    }
    while (ch != 'c');
    if (ch == 'c'||'C')
        exit('c');
    return 0;
}













