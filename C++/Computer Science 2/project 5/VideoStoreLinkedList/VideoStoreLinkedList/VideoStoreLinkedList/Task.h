//This is a header file for the Task class
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX = 101;

//Class data type for the Task object
class Task
{
	friend ostream& operator<< (ostream& out, const Task &);
    
private:
	char *course;
	char *assignment;
	char *duedate;
    
public:
	//constructors
	Task();
	Task(char initCourse[], char initAssignment[], char initDueDate[]);
	Task(const Task &aTask);
    
	//destructor
	~Task();
    
	//accessor and mutator functions
	const void getCourse(char returnCourse[]);
	const void getAssignment(char returnAssignment[]);
	const void getDueDate(char returnDueDate[]);
	void setCourse(char newCourse[]);
	void setAssignment(char newAssignment[]);
	void setDueDate(char newDueDate[]);
    
	//print function
	const void printFile(ofstream &outFile);
    
	const Task& operator= (const Task& aTask);
};
#endif