//Task.cpp
#include "Task.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

//CONSTRUCTOR
//DEFAULT CONSTRUCTOR
Task::Task(){
    
	course = new char[MAX];
	strcpy(course, "No Course");
    
	assignment = new char[MAX];
    strcpy(assignment, "No Assignment");
    
	duedate = new char[MAX];
	strcpy(duedate, "No Due Date");
}

//CONSTRUCTOR WITH PERAMETERS
Task::Task(char newCourse[], char newAssignment[], char newDueDate[]){
    
	course = new char[strlen(newCourse) + 1];
	strcpy(course, newCourse);
    
	assignment = new char [strlen(newAssignment) +1];
    strcpy(assignment, newAssignment);
    
	duedate = new char[strlen(newDueDate) + 1];
	strcpy(duedate, newDueDate);
}

//COPY CONSTRUCTOR
Task::Task(const Task &aTask){
    
	if (course){
        
		delete[] course;
		course = NULL;
	}
	course = new char[strlen(aTask.course) + 1];
    
    if (assignment){
        
        delete[] assignment;
        assignment = NULL;
    }
    assignment = new char[strlen(aTask.assignment) + 1];
    
    if (duedate){
        
		delete[] duedate;
		duedate = NULL;
	}
	duedate = new char[strlen(aTask.duedate) + 1];

	*this = aTask;
}


//DESTRUCTOR
Task::~Task(){
    
	//deallocate mem for course and Due Date
	if (course){
        
		delete[] course;
		course = NULL;
	}
    
    if (assignment){
        
        delete[] assignment;
        assignment = NULL;
    }
    
    if (duedate){
        
		delete[] duedate;
		duedate = NULL;
	}
}


//A&M FUNCTIONS
//ACCESSORS
const void Task::getCourse(char returnCourse[]){
    
	strcpy(returnCourse, course);
}

const void Task::getAssignment(char returnAssignment[]){
    
    strcpy(returnAssignment, assignment);
}

const void Task::getDueDate(char returnDueDate[]){
    
	strcpy(returnDueDate, duedate);
}


//MUTATORS
void Task::setCourse(char newCourse[]){
    
	if (course){
        
		delete[] course;
		course = NULL;
	}
	course = new char[strlen(newCourse) + 1];
	strcpy(course, newCourse);
}

void Task::setAssignment(char newAssignment[]){
    
	if (assignment){
        
        delete[] assignment;
        assignment = NULL;
    }
    assignment = new char[strlen(newAssignment) + 1];
    strcpy(assignment, newAssignment);
}

void Task::setDueDate(char newDueDate[]){
    
	if (duedate){
        
		delete[] duedate;
		duedate = NULL;
	}
	duedate = new char[strlen(newDueDate) + 1];
	strcpy(duedate, newDueDate);
}


//SAVE TO FILE
const void Task::printFile(ofstream &outFile){
    
    outFile << course << ';'
    << assignment << ';'
    << duedate << endl;
}

//OVERLOADED
const Task& Task::operator= (const Task& aTask){
    
	// CHECK FOR DUPLICATE
	if (this == &aTask)
		return *this;
	
	else{
		strcpy(this->course, aTask.course);
        strcpy(this->assignment, aTask.assignment);
		strcpy(this->duedate, aTask.duedate);

		return *this;
	}
}

ostream& operator<< (ostream& out, const Task& aTask){
    
    out << left
        << setw(15) << aTask.course
        << setw(15) << aTask.assignment
        << setw(15) << aTask.duedate << endl;
	return out;
}


