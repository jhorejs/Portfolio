//
//  main.cpp
//  aha
//
//  Created by Joshua Horejs on 5/2/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Declare variables to manipulate data
    string name;
    string fileSource; d = destination
    int maleScore = 0; m
    int femScore = 0; f
    int unScore = 0; ug
    int ccScore = 0; cg
    int femCount = 0; fg
    int maleCount = 0;mg
    int ccCount = 0; cc
    int unCount = 0; uc
    //Declare stream variables
    ifstream inData; intxt
    ofstream outData; outtxt
    
    // Prompt user for file location
    cout << "Please input file location: ";
    cin >> fileSource;
    
    // open output file and run program exit failsafe command
    inData.open(fileSource);
    
    if(!inData)
    {
        cout << "Cannot open input file. "
        << "Program will now terminate." << endl;
        return 1;
    }
    
    cout << "Reading data from '" << fileSource << "'" << endl;
    
    while(inData >> name)
    { // If we read a name, we can continue. Otherwise, we're done.
        char sex;
        int score;
        string school;
        
        inData >> sex >> school >> score;
        
        // Echo
        cout << name << sex << school << score << endl;
        
        // Male and female calculations
        if(sex=='M')
        {
            maleScore +=score;
            maleCount++;
        }
        else if(sex =='F')
        {
            femScore +=score;
            femCount++;
        }
        
        // Community college and University calculations
        if(school == "CC")
        {
            ccScore +=score;
            ccCount++;
        }
        else if(school == "UN")
        {
            unScore +=score;
            unCount++;
        }
    }
    
    // Average Calculations
    cout << fixed << showpoint << setprecision(2) << endl;
    if(maleCount != 0)
    {
        cout << "The average scores for males is: "
        << static_cast<double>(maleScore) / maleCount << endl;
    }
    
    if(femCount != 0)
    {
        cout << "The average score for females is: "
        << static_cast<double>(femScore) / femCount << endl;
    }
    
    if(ccCount != 0)
    {
        cout << "The average score for Community Colleges is: "
        << static_cast<double>(ccScore) / ccCount << endl;
    }
    
    if(unCount != 0)
    {
        cout << "The average score for Universities is: "
        << static_cast<double>(unScore) / unCount << endl;
    }
    
    cout << "The average test score for all students combined is: "
    << (1.0 * (maleScore + femScore + ccScore + unScore)) / 12 << endl;
    
    return 0;
}

