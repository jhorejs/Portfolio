//
//  main.cpp
//  tasktracker 1.2
//
//  Created by Joshua Horejs on 4/15/16.
//  Copyright © 2016 Joshua Horejs. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 30;
const int MIN = 10;

//assigns a struct of Assignment
struct Assignment{
    char courseName[MIN];
    char assignmentDescription[MIN];
    char dueDate[MIN];
};


void menu();//
char menuSelection();//
void menuSwitch(char ch, Assignment column[], int& row);
bool searchAssignmentDescription(const char assignmentDescription[], Assignment& match, const Assignment column[], int row);
void print(const Assignment column[], int& row, char ch);
void userInput(char cstring[]);

int main() {
    char    ch;
    Assignment    column[MAX]; //declares length of the task library
    int            row = 0;
    
    
    infile(column, row);
    
    menu();
    ch = menuSelection();
    while (ch != '6' )
    {
        menuSwitch(ch, column, row);
        menu();
        ch = menuSelection();
    }
    outfile(column, row);
    
    return 0;
    
}












void add(Assignment& task){
    char    courseName[MIN];
    char    assignmentDescription[MIN];
    char    dueDate[MIN];
    
    cout << "Please enter the following: " << endl;
    cout << "Course name: " << endl;
    userInput(courseName);
    cout << "Assignment description: " << endl;
    userInput(assignmentDescription);
    cout << "Due date: " << endl;
    userInput(dueDate);
    
    strcpy(task.courseName, courseName);
    strcpy(task.assignmentDescription, assignmentDescription);
    strcpy(task.dueDate, dueDate);
    
    cout << courseName<< " " << assignmentDescription << " " << dueDate << "\n" << endl;
}


bool alphabetize(Assignment& newAssignment, Assignment column[], int& row){
    int index;
    int puthere;
    
    if (row == MAX)
        return false;
    
    //step 1
    for (index = 0; index < row; index++)
    {
        if (strcmp(column[index].courseName, newAssignment.courseName) > 0)
        {
            break;
        }
    }
    
    puthere = index;//puthere gets the index/row value
    
    for (index = row -1; index >= puthere; index--)
    {
        column[index + 1] = column[index];
    }
    
    //step 3: "puther" is inserted into the open library index/row
    
    column[puthere] = newAssignment;
    row++;
    return true;
}

void userInput(char cstring[]){
    
    cin.get(cstring, MAX, '\n');
    while (!cin)
    {
        cin.clear();
        cin.ignore(MAX, ';');
        cin.get(cstring, MAX, '\n');
    }
    cin.ignore(MAX, '\n');
    
}

void print(const Assignment column[], int& row, char ch){
    //cout << "This is: print" << endl;
    
    int index;
    
    for (index = 0; index < row; index++){
        cout << index + 1 << ": " << column[index].courseName << ' ' << column[index].assignmentDescription << ' ' << column[index].dueDate << endl;
    }
    cout << "\n" << endl;
}


bool searchCourseName(const char courseName[], Assignment& match, const Assignment column[], int row){
    int index;
    
    for (index = 0 ; index < row; index++)
    {
        if (strstr(column[index].courseName, courseName) == 0)
        {
            match = column[index];
            break;
        }
    }
    if(index == row)
        return false;
    return true;
    
}


void menu(){
    //cout << "This is: menu()" << endl;
    
    cout
    << "1 Add: \n"
    << "2 View: \n"
    << "3 Search Course: \n"
    << "4 Exit: \n"
    << endl;
}
char menuSelection(){
    //cout << "This is: menuSelection o1b" << endl;
    
    char ch;
    cout << "\nSelection: ";
    cin >> ch;
    cin.ignore(MAX, '\n');
    return tolower(ch);
}
void menuSwitch(char ch, Assignment column[], int& row){
    //cout << "This is: menuSwitch" << endl;
    
    Assignment    task;
    char    courseName[MAX];
    char    assignmentDescription[MAX];
    char    dueDate[MAX];
    
    switch (ch)
    {
        case '1':
            add(task);
            alphabetize(task, column, row);
            break;
            
        case '2':
            print(column, row, ch);
            break;
            
        case '3':
            cout << "Search for Course: ";
            userInput(courseName);
            if (searchCourseName(courseName, task, column, row)){
                cout << "Is this information correct: "
                << task.courseName << " \n"
                << task.assignmentDescription << " \n"
                << task.dueDate << endl;
            }
            else{
                cout << "\n\nERROR\nTry again" << endl;
            }
            break;
        default:
            cout << "only.... \n\n 1,2,3,4\n try again: " << endl;
    }

}
