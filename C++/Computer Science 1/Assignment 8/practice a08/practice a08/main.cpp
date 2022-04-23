//
//  a08.cpp
//  a08
//  Sources: none
//  Created by Joshua Horejs on 6/4/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
/*
 Write a program that:
 1. All data should be separated by a single space. (using )
 2. read students’ names followed by their test scores
 3. read (5 scores) from the given input file, students.txt.
 4. The program should output to a file, output.txt,
 5. each student’s first name, last name, followed by the test scores and the relevant grade.
 
 
 Student data should be stored in a struct variable of type StudentType, which has four components:
 √* studentFName and studentLName of type string,
 √* an array of testScores of type int and grade of type char.
 Suppose that the class has 20 students.
 √* Use an array of 20 components of type StudentType.
 
 Your program must contain at least the following functions:
 1. A function to read the students’ data into an array.
 2. A function to assign the relevant grade to each student.
 
 Moreover, other than declaring the variables and opening the input and output files, the function main should only be a collection of function calls. Use constants where needed.
 You MUST use:
 * structs,
 * an array of the struct,
 * and an array inside the struct for the scores.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int N = 20

struct studentType
{
    string studentFName;
    string studentLName;
    int testscore;
    char grade;
};

studentType students[N];

void getData(studentType sList[], int listSize);
void calculateGrade(studentType sList[], int listSize);
int highestScore(const studentType sList[], int listSize);
void printResult(const studentType sList[],int listSize);

int main ()
{
    ifstream inFile;
    inFile.open("students.txt");
    
    ofstream outFile;
    outFile.open("output.txt");
    
    
    StuRead(inFile, students);
    
    system("PAUSE");
    return 0;
}

void StuRead(ifstream& indata, studentType students[])
{
    int x = 0;
    
    for (x = 1; x < N; x++)
    {
        ifstream inFile;
        inFile >> students[x].studentLName
        >> students[x].studentFName
        >> students[x].testscore;
    }
    
}




char AssignGrade(char LetterGrade, studentType students[])
{
    char grade = 0;
    
    if(LetterGrade > 90)
        students.grade = 'A';
    else if (LetterGrade > 80)
        grade = 'B';
    else if (LetterGrade > 70)
        grade = 'C';
    else if (LetterGrade > 60)
        grade = 'D';
    else
        grade = 'F';
    
    return grade;
}



void Highest(studentType students[N])
{
    int highTest = 0;
    int x = 0;
    
    for(x = 0; x < N; x++)
    {
        if(x > highTest)
            highTest = x;
        
    }
    
}

