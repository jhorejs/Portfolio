//
//  main.cpp
//  count: even, odd, zero
//
//  Created by Joshua Horejs on 5/17/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;


void initialize (int& zeroCount, int& oddCount, int& evenCount);
void getNumber (int& number);
void classifyNumber ( int number, int& zeroCount, int& oddCount, int&evenCount);
void printReslults (int zeroCount, int oddCount, int evenCount);


int main()
{
    int counter;
    int number;
    int zeros;
    int odds;
    int evens;
    
    initialize(zeros, odds, evens);
    
    cout << "please enter number: " << number << "\n" << "You entered" << "\n" << endl;
    
    for (counter = 1; counter <= number; counter++)
    {
        getNumber(number);
        cout << number << " ";
        classifyNumber(number, zeros, odds, evens);
    }
    
    cout << endl;
    printReslults(zeros, odds, evens);
    return 0;
}

void initialize(int& zeroCounter, int& oddCounter, int& evenCounter)
{
    zeroCounter=0;
    oddCounter=0;
    evenCounter=0;
}

void getNumber(int& num)
{
    cin >> num;
}

void classifyNumber(int number, int& zeroCount, int& oddCount, int& evenCount)
{
    switch (number % 2)
    {
        case 0:
            evenCount++;
            if (number == 0)
                zeroCount++;
            break;
        case 1:
        case -1:
            oddCount++;
    }
}

void printResults (int zeroCount, int oddCount, int evenCount)
{
    cout << "There are " << evenCount<< " evens, " << "which includes " << zeroCount << " zeros" << "\n" << "Then number of odd numbers is: " << oddCount << endl;
}

    


