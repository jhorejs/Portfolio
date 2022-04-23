//
//  main.cpp
//  a07
//
//  Created by Joshua Horejs on 5/22/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//
/*
 Write a program to calculate students’ average test scores and their grades. You may assume the following input data: Create a text file called arrays.txt with this data.
 
    File: arrays.txt
 Johnson 85 83 77 91 76
 Aniston 80 90 95 93 48
 Cooper  78 82 22 90 73
 Gupta   92 83 30 69 87
 Blair   23 45 96 38 59
 Clark   60 85 45 39 67
 Kennedy 77 31 52 74 83 
 Bronson 93 94 89 77 97 
 Sunny   79 85 28 93 82
 Smith   85 72 49 75 63
 
 
 example output
 johnson 82.4 B
 Aniston 81.2 B
 Cooper  69   D
 Gupta   72.2 C
 Blair   etc...
 Clark
 Kennedy
 Bronson
 Sunny
 Smith
 */
#include <iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include <cctype>
using namespace std;

//Number of students
const int numStudents = 10;
const int numScores = 5;

//Activate voids
void inData(ifstream& infile, string names[], int scores[][numScores]);
void Average(int scores[][numScores], double numericGrades[], char letterGrades[]);
void printResults(string name[], double numericGrades[], char letterGrade[]);

int main()
{   // step 1

    string names[numStudents];
    int scores[numStudents][numScores];
    double numericGrades[numStudents];
    char letterGrades[numStudents];

    ifstream infile;
    
    cout << "Welcom to program a07: " << endl;
    
    // step 2 open file
    infile.open("array.txt");
    if (!infile)
    {
        cout << "Cannot open the input file. " << endl;
        return 1;
    }
    
    inData(infile, names, scores);
    Average(scores, numericGrades, letterGrades);
    printResults(names, numericGrades, letterGrades);
    
    infile.close();
    
    return 0;
    
}

void inData(ifstream& infile, string names[], int scores[][numScores])
{
    int studentRow;
    for (studentRow = 0; studentRow < 10; studentRow++)
    {
        infile >> names[studentRow];
        
        for (int j = 0; j< numScores; j++)
            infile >> scores[studentRow][j];
    }
}

void Average(int scores[][numScores], double numericGrades[], char letterGrades[])
{
    double average = 0;
    double sum = 0;
    int sindex;
    int i;
    
    for (i = 0; i < numStudents; i++)
    {
        sum = 0;
        average = 0;
        
        for (sindex = 0; sindex < numScores; sindex++)
        {
            sum += scores[i][sindex];
        }
    
        average = sum / numScores;
        numericGrades[i] = average;
        
        if (average >= 90.0)
            letterGrades[i] = 'A';
        else if (average >= 80.0)
            letterGrades[i]  = 'B';
        else if (average >= 70.0)
            letterGrades[i]  = 'C';
        else if (average >= 60.0)
            letterGrades[i]  = 'D';
        else
            letterGrades[i]  = 'F';
    }
    return;
}

void printResults(string name[], double numericGrades[], char letterGrade[])
{
    for (int i = 0; i< numStudents; i++)
    {
        cout << fixed << showpoint;
        
        cout <<setprecision(1) << name[i] << " " << numericGrades[i] << " " << letterGrade[i] << endl;
    }
}

