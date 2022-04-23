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
#include <string>
#include <iomanip>

using namespace std;

const int N = 10;// use array of 20 components of type StudentType

struct StudentType //Student data should be stored in a struct variable of type StudentType
{
    // Which has four components:
    string studentFName;
    string studentLName;
    int testScores[5];// must be an array
    char Grade;// must be an array
};


void initialize(StudentType studentList[]);// "function to read the students grade into an array"

void getData(ifstream& infile, StudentType studentList[]);

void calculateGrade(StudentType steudentList[], int student); // "function to assign the relevant grade"

void printGrades(ofstream& outfile, StudentType studentList[]); // "FName, LNam, testSores, relevent grade"


int main()
{
    
    //"main should only be function calls"
    ifstream infile;
    ofstream outfile;
    
    StudentType studentList[N];
    
    
    infile.open("/Users/joshuahorejs/Desktop/students.txt");
    outfile.open("/Users/joshuahorejs/Desktop/output.txt");
    
    cout << "works" << endl;
    
    if (!infile)
    {
        cout << "Cannot open the input file." << endl;
        
        return 1;
    }
    
    initialize(studentList);// 6 initialize array
    getData(infile, studentList);
    infile.close();// 7 clear input data and close
    infile.clear();
    
    printGrades(outfile, studentList);
    //system("PAUSE");
    
    return 0;
}



void calculateGrade(StudentType studentList[], int student)
{
    int average = 0;
    int sum=0;
    int sindex;
    
    for (sindex = 0; sindex < 5; sindex++)
    {
        sum += studentList[student].testScores[sindex];
    }
    
    average = sum / 5;
    
    
    
    if (average >= 90)
        studentList[student].Grade = 'A';
    else if (average >= 80)
        studentList[student].Grade  = 'B';
    else if (average >= 70)
        studentList[student].Grade  = 'C';
    else if (average >= 60)
        studentList[student].Grade  = 'D';
    else
        studentList[student].Grade  = 'F';
    return;
    
}

void getData(ifstream& infile, StudentType studentList[])
{
    int index;
    int sindex;
    
    cout << "getData works" << endl;
    
    for (index =0; index < N; index++)
    {
        infile >> studentList[index].studentLName;
        infile >> studentList[index].studentFName;
        
        
        for (sindex =0; sindex < 5; sindex++)
            infile >> studentList[index].testScores[sindex];
        
        calculateGrade(studentList, index);
        
    }
    cout << "getdata ends" << endl;
}

void initialize(StudentType studentList[])// "function to read the students grade into an array"
{
    int index;
    int sindex;
    
    cout << "init works" << endl;
    
    for (index =0; index < N; index++)
    {
        studentList[index].studentFName = '\0';
        studentList[index].studentLName ='\0';
        
        for (sindex =0; sindex < 5; sindex++)
            studentList[index].testScores[sindex] =0;
        
        studentList[index].Grade=0;
    }
    
}

void printGrades(ofstream& outfile, StudentType studentList[])
{
    int index;
    int sindex;
    
    cout << "printgrades works" << endl;
    
    for (index =0; index < N; index++)
    {
        outfile << studentList[index].studentLName << ' ';
        cout << studentList[index].studentLName << ' ';
        outfile << studentList[index].studentFName << ' ';
        cout << studentList[index].studentFName << ' ';
        
        
        for (sindex =0; sindex < 5; sindex++)
            outfile << studentList[index].testScores[sindex] << ' ';
            cout << studentList[index].testScores[sindex] << ' ';
        
        outfile << studentList[index].Grade << endl;
        cout << studentList[index].Grade << endl;
        
    }
    
}














