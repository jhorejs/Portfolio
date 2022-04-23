#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

class TaskList
{
private:
	struct Node
	{
		Task data;
		Node *next;
	};
	Node *head, *tail;
    
public:
	//CONSTRUCTOR
	TaskList();
	TaskList(char file[]);
    
	//DESTRUCTOR
	~TaskList();
    
	//FUNCTIONS
	void add(Task &aTask);
	const void taskLibrary();
	const void findTask();
	void outFile();
};

#endif