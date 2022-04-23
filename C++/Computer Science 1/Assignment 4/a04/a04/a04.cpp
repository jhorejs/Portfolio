//
//  main.cpp
//  a04
//  sources
//  Created by Joshua Horejs on 5/2/15.
//  Copyright (c) 2015 Joshua Horejs. All rights reserved.
//

/*
 The Oregon Department of Education has commissioned a study to determine if Males or Females score better on a particular test. They also want to study if Community College or University students score better. Researchers have created a data file (scores.txt), which contains the scores attained by the student sample. The first column is the student’s name, the second column is the student’s gender (M for male, and F for emale), the thi rd column indicates Community College (CC) or 4 year (UN), and the last column specifies the score. A specimen of the file scores.txt is attached as part of this assignment. You should download this file to a convenient place on your hard drive.
 1. Your assignment is to prompt the user to enter the filename with the path on disk. If the file does not exist in the specified location, your program should exit with a suitable error message.
 2. No global variables. All variables must be inside main().
 3. The first thing your program should do is output to the screen a copy of the data read in from the disk file. This is known as “echoing” the input data.
 4. Your program should then calculate and display the average score for:
    males, females, community college students, and university students. 
    Display your results to two places of decimals, and write your program to automatically list your
    four calculated averages one to a line, along with a suitable label for each result.
 5. Finally, your program should calculate and display to two places of decimals the overall average score for all of the students surveyed. (Note: Mathematically, this is NOT the average of the four averages you calculated previously).
 */







#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
//Variables:
    ifstream intxt;
    ofstream outtxt;
    double m = 0, f=0, u=0, c=0;
    double fg = 0, mg = 0, cg = 0, ug = 0;
    char q, gender;
    string name, d, inst;
    double grade=0, average=0, sum=0;
    double percentage, maximum;

    do
    {
        // "prompt the user to enter the filename with the path on disk"
    cout << "File destination('scores'): ";
    cin >> d;
    cout << endl;
    
// File does not exist in the specified location, your program should exit with a suitable error message.
    intxt.open(d);
    
    
        if(!intxt)
    {
        cout << "INPUT FAILURE. "<< endl;
        cout << "q to quit: ";
        cin >> q;
        exit(1);
    }
    
// Output to the screen a copy of the data read in from the disk file
    cout <<setw(20)<< "INPUT " << endl;
    cout<< endl;
    cout <<setw(11)<< "Name: " << setw(10) << "Sex: " << setw(9)<< "Inst: " << setw(9) << "Grade: " << endl;
    while(intxt>> name)
    {
        
        
        intxt >> gender >> inst >> grade;
        cout << setw(10)<< name << setw(9) << gender << setw(9)<< inst << setw(9) << grade << setw(9)<< endl;
    
        if (gender =='F')
        {
            f += grade;
            fg++;
        }
        else if (gender=='M')
        {
            m += grade;
            mg++;
        }

        if(inst == "UN" )
        {
            u +=grade;
            ug++;
        }

        else if(inst == "CC" )
        {
            c += grade;
            cg ++;
        }
        
        if (inst == "CC" && "UN")
        {
            sum += grade;
            average++;
        }
    }
    
//'Overall average score for all of the students surveyed.'
        cout << fixed << showpoint << setprecision(2) << endl;
        cout << endl;
        cout <<setw(20)<< "TOTAL AVERAGES "<< endl;
        cout << endl;
        cout <<setw(12)<< "Demographic " <<setw(9)<< "GPA:" <<setw(9)<< "Grade:"<< endl;
        
        percentage = m /mg;
        cout <<setw(12)<< "Male: " <<setw(9)<< percentage << "%" <<setw(5) ;
        if (percentage >= 90)
        {
            cout << "A" << endl;
        }
        else if (percentage >= 80)
        {
            cout << "B" << endl;
        }
        else if (percentage >= 70)
        {
            cout << "C" << endl;
        }
        else if (percentage >= 60)
        {
            cout << "D" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
        
        percentage = f / fg;
        cout <<setw(12)<< "Female: " <<setw(9)<< percentage << "%" <<setw(5) ;
        if (percentage >= 90)
        {
            cout << "A" << endl;
        }
        else if (percentage >= 80)
        {
            cout << "B" << endl;
        }
        else if (percentage >= 70)
        {
            cout << "C" << endl;
        }
        else if (percentage >= 60)
        {
            cout << "D" << endl;
        }

        else
        {
            cout << "F" << endl;
        }
        
        percentage = c / cg;
        cout <<setw(12)<< "CC: " <<setw(9)<< percentage << "%" <<setw(5) ;
        if (percentage >= 90)
            {
                cout << "A" << endl;
            }
        else if (percentage >= 80)
            {
                    cout << "B" << endl;
            }
        else if (percentage >= 70)
            {
                cout << "C" << endl;
            }
        else if (percentage >= 60)
            {
                cout << "D" << endl;
            }
        else
            {
                cout << "F" << endl;
            }
        
        percentage = u / ug;
        cout <<setw(12)<< "UN: " <<setw(9)<< percentage << "%" <<setw(5) ;
        if (percentage >= 90)
            {
                cout << "A" << endl;
            }
        else if (percentage >= 80)
            {
                cout << "B" << endl;
            }
        else if (percentage >= 70)
            {
                cout << "C" << endl;
            }
        else if (percentage >= 60)
            {
                cout << "D" << endl;
            }

        else
            {
                cout << "F" << endl;
            }
        
        percentage = sum/average;
        cout <<setw(12)<< "Mean: " <<setw(9)<< percentage << "%" <<setw(5) ;
        if (percentage >= 90)
            {
                cout << "A" << endl;
            }
        else if (percentage >= 80)
            {
                cout << "B" << endl;
            }
        else if (percentage >= 70)
            {
                cout << "C" << endl;
            }
        else if (percentage >= 60)
            {
                cout << "D" << endl;
            }

        else
            {
                cout << "F" << endl;
            }
        

        cout << endl;
        cout << "Repeat program? (y/n)";
        cin >> q;
    }while (q == 'y');
    
// Exit statement
    cout << endl;
    cout << "Enter q to quit: ";
    cin >> q;
    exit(1);
    return 0;
}



