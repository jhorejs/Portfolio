// Joshua Horejs
// Project 3
// CS162
// 04/15/2016
// Copyright © All rights reserved



#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


const int MIN = 100;
const int MAX = 101;


struct Task{
    
    char course[MAX];
    char assignment[MAX];
    char dueDate[MAX];
    
};

class TaskList{
    
private:
    
    Task column[MAX];
    int row;
    
public:
    
    //constructor
    TaskList();
    TaskList(char file[]);
    
    //destructor
    ~TaskList();
    
    //functions
    bool add(const Task &aTask);
    const void taskLibrary();
    const void findTask();
    void delTask();
    void outFile();
    
};

void menuDisplay();
char menuSelection();
void menuSwitch(char ch, Task column[], int &row);
void add(Task &aTask);



// Default Construct: initializes to 0.
TaskList::TaskList(){
    
    row = 0;
}

// Constructor: pulls information from file at startup.
TaskList::TaskList(char file[]){
    
    ifstream in; // initializes iostrem in file operations.
    Task aTask;  // tells the class where each item will be sent
    in.open(file); // opens the file.
    row = 0; // initializes row to 0.
    
    if (!in){ // if there is no file then this will read out to the user
        
        cout << "\nERROR: FILE NOT IN SCOPE \n\n\n\n\n" << endl;
        exit(0);
    }
    
    else{
        
        in.get(aTask.course, MAX, ';'); // Starting at the first position of the infile until 100 or ; call this object course.
        while (!in.eof()){ // Until the end of the infile do the following.
            
            in.ignore(5, ';'); // Discard the ;
            in.get(aTask.assignment, MAX, ';');
            in.ignore(5, ';');
            in.get(aTask.dueDate, MAX, '\n');
            in.ignore(5, '\n');
            this->add(aTask); // Move on to a new task.
            in.get(aTask.course, MAX, ';');
        }
        in.close();
    }
}

// Destructor
TaskList::~TaskList(){
    
}


// This is the user interface that takes in a char
void menuDisplay(){
    
    cout << "\n1. Add Assigment \n"
         << "2. View Task Library \n"
         << "3. Search by Course \n"
         << "4. Quit \n"
         << "Your selection: "
         << endl;
    
}
char menuSelection(){
    
    char ch;
    cin >> ch;
    cin.ignore(100, '\n');
    return ch;
}
void menuSwitch(char ch, TaskList &column){
    
    Task aTask;
    
    switch (ch){
        case '1':
            add(aTask);
            if (column.add(aTask)){
                
                cout << "\n Accepted" << endl;
            }
            else{
                
                cout << "\n Task already exists." << endl;
            }
            break;
        case '2':
            column.taskLibrary();
            break;
            
        case '3':
            column.findTask();
            
            break;
        case '4':
            column.outFile();
            break;
        default:
            cout << "\nDigits 1-4 please \n\n\n\n Try again" << endl;
    }
}

void add(Task &aTask){
    
    cout << "\n Course: ";
    cin.get(aTask.course, MAX, '\n');
    cin.ignore(100, '\n');
    cout << "\n Assignment: ";
    cin.get(aTask.assignment, MAX, '\n');
    cin.ignore(100, '\n');
    cout << "\n Due Date: ";
    cin.get(aTask.dueDate, MAX, '\n');
    cin.ignore(100, '\n');
}
// add: takes input and passes organized data to the struct Task.
bool TaskList::add(const Task &aTask){
    
    
    int a = 0, b = 0;
    
    //compares the course and assignment. If both match up then the function returns false. 
    for (a = 0; a < row; a++)
    {
        if ((strcmp(column[a].course, aTask.course) == 0)&(strcmp(column[a].assignment, aTask.assignment) == 0))
            return false;
    }

    for (a = 0; a < row; a++)
    {
        if (strcmp(column[a].course, aTask.course) > 0)
            break;
    }

    for (b = row; b >= a; b--)
    {
        column[b + 1] = column[b];
    }
    column[a] = aTask;
    row++;
    
    return true;
}

//Outputs the current tasks.txt file data that was uploaded at the beginning of the program and intermitently added to throughout the programs use.
const void TaskList::taskLibrary(){
    
    cout << left
    << endl << "#: "
    << setw(15) << "Course"
    << setw(15) << "Assignment"
    << setw(15) << "Due Date"
    << endl;
    
    for (int counter = 0; counter < row; counter++){
        
        cout << left << counter + 1 << ": "
        << setw(15) << column[counter].course
        << setw(15) << column[counter].assignment
        << setw(15) << column[counter].dueDate
        << endl;
    }
}

//Using #cstring this function takes input(searchTask) and compares against Task(struct) until str Task.course == str searchTask.
const void TaskList::findTask(){
    
    char searchTask[MAX];
    
    cout << "\nSearch Task by Course: \n";
    cin.get(searchTask, MAX, '\n');
    	   
    for (int counter = 0; counter < row; counter++){
        
        if (strstr(column[counter].course, searchTask))
            
            cout << left
                 << setw(15) << column[counter].course
                 << setw(15) << column[counter].assignment
                 << setw(15) << column[counter].dueDate << '\n';
	
    }
    cout << endl;
    
}

void TaskList::outFile(){
    
    ofstream outFile;
    outFile.open("tasks.txt");
    
    if (!outFile) {
        
        cout << "\n File not found. " << endl;
        exit(0);
    
    }
    
    for (int counter = 0; counter < row; counter++){
        
        outFile << column[counter].course << ';'
                << column[counter].assignment << ';'
                << column[counter].dueDate << '\n';
        
    }
    outFile.close();
}

int main(){
    
    TaskList column("tasks.txt");
    
    char ch;
    
    while (ch != '4'){
        menuDisplay();
        ch = menuSelection();
        menuSwitch(ch, column);
    }
    
    return 0;
}

