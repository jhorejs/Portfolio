//This is the implementation file for TaskList class
#include "TaskList.h"
#include "functions.h"
#include <iomanip>

//TaskList implementation functions
//default constructor
TaskList::TaskList(){
    
	head = NULL;
	tail = NULL;
}

//INFILE CONSTRUCTOR
TaskList::TaskList(char file[]){
    
	ifstream in;
	Task aTask;
    char xCourse[MAX], xDueDate[MAX], xAssignment[MAX];

	head = NULL;
	tail = NULL;
    
	in.open(file);
	if (!in){
        
		cout << "\nERROR: FILE NOT IN SCOPE \n\n\n\n\n" << endl;
		exit(0);
	}

	in.get(xCourse, MAX, ';');
	while (!in.eof()){
        
		in.ignore(5, ';');
		in.get(xAssignment, MAX, ';');
		in.ignore(5, ';');
		in.get(xDueDate, MAX, '\n');
		in.ignore(5, '\n');
                   
		//populate aTask with all the information
		aTask.setCourse(xCourse);
		aTask.setAssignment(xAssignment);
		aTask.setDueDate(xDueDate);
        
		this->add(aTask);
		in.get(xCourse, MAX, ';');
	}
	in.close();
}

//destructor
TaskList::~TaskList(){
    
	Node *i = head;
	while (head){
        
		head = i->next;
		delete i;
		i = head;
	}
	head = NULL;
	i = NULL;
}

//adds a Task to the list
void TaskList::add(Task &aTask){
    
	Node *newNode, *i, *prev;
	char xCourse1[MAX], xCourse2[MAX];

	newNode = new Node;
	newNode->data = aTask;
	newNode->next = NULL;
    
	if (!head){
        
		head = newNode;
		tail = newNode;
	}
	else{
        
		i = head;
		prev = NULL;
		i->data.getCourse(xCourse1);
		newNode->data.getCourse(xCourse2);
		
		while (i && strcmp(xCourse1, xCourse2) < 0){//push prev and i right
            
			prev = i;
			i = i->next;
			if (i)
				i->data.getCourse(xCourse1);
		}
		if (!i){ //add to tail
            
			tail->next = newNode;
			tail = newNode;
		}
		else{ //insert between 2 nodes
			
			if (prev){
                
				prev->next = newNode;
				newNode->next = i;
			}
			else{
                
				newNode->next = head;
				head = newNode;
			}
		}
	}

}


//prints the list
const void TaskList::taskLibrary(){
    
	Node *i;
	for (i = head; i; i = i->next){
        
		cout << i->data;
	}
	cout << endl;
}

//finds a movie in the list
const void TaskList::findTask()
{
	Node *i;
	char searchTask[MAX], xCourse[MAX];
	cout << "\nSearch Task by Course: \n";
	cin.get(searchTask, MAX, '\n');
	allCaps(searchTask);
    
	for (i = head; i; i = i->next){
        
		i->data.getCourse(xCourse);
		allCaps(xCourse);
		if (strstr(xCourse, searchTask)){
            
			cout << i->data;
		}
	}
	cout << endl;
}

// WRITE TO FILE
void TaskList::outFile(){
    
	ofstream outFile;
	Node *i;
	outFile.open("tasks.txt");
	if (!outFile){ // TEST CASE FOR NO FILE
        
		cout << "ERROR FILE NOT IN SCOPE. " << endl;
		exit(0);
	}
	for (i = head; i; i = i->next){
        
		i->data.printFile(outFile);
	}
	outFile.close();
}
