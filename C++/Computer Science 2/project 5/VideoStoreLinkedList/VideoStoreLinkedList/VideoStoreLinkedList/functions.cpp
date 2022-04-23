//This is the implementation file for tools.h
#include "functions.h"
#include <iomanip>

//MENU FUNCTIONS
void menuDisplay(){
    
    cout << "\n1. Add Assigment \n"
    << "2. View Task Library \n"
    << "3. Search by Course \n"
    << "4. Quit \n\n"
    << "Your selection: \n" << endl;
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
		column.add(aTask);
		break;
	case '2':
       cout << left
            << setw(15) << "\nCourse"
            << setw(15) << "Assignment"
            << setw(15) << "Due Date" << endl;
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

////////ADD TASK FUNCTION: new tasks from user.
void add(Task &aTask)
{
    char xCourse[MAX];
    char xAssignment[MAX];
    char xDueDate[MAX];
    
    cout << "\n Course: ";
    cin.get(xCourse, MAX, '\n');
    cin.ignore(100, '\n');
    
    cout << "\n Assignment: ";
    cin.get(xAssignment, MAX, '\n');
    cin.ignore(100, '\n');
    
    cout << "\n Due Date: ";
    cin.get(xDueDate, MAX, '\n');
    cin.ignore(100, '\n');
    
    aTask.setCourse(xCourse);
    aTask.setAssignment(xAssignment);
    aTask.setDueDate(xDueDate);
}

///////ALL CAPS: toupper, for none case sensitive searching.
void allCaps(char xStr[])
{

	for (int i = 0; i < strlen(xStr); i++)
	{
		xStr[i] = toupper(xStr[i]);
	}
}