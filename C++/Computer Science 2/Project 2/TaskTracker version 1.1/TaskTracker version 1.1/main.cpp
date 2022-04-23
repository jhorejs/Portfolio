#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX = 101;
const int MIN = 10;

struct Assignment{
    char courseName[MIN];
    char assignmentDescription[MIN];
    char dueDate[MIN];
};





void menu();//
char menuSelection();//
void menuSwitch(char ch, Assignment column[], int& row);
bool alphabetize(Assignment& newAssignment, Assignment column[], int& row);
void userInput(char cstring[]);
void userInputDate(char cstring[]);
void add(Assignment& newAssignment);
void print(const Assignment column[], int& row, char ch);
bool searchAssignmentDescription(const char assignmentDescription[], Assignment& match, const Assignment column[], int row);
bool searchCourseName(const char courseName[], Assignment& match, const Assignment column[], int row);
void infile(const char file[], Assignment column[], int& row);
void outfile(char file[], const Assignment column[], int&row);



int main(){
    char    ch;
    Assignment    column[MAX]; //declares length of the task library
    int            row = 0;
    char           file[] = "tasks.txt";
    
    infile(file, column, row);
    menu();
    ch = menuSelection();
    while (ch != '6' )
    {
        menuSwitch(ch, column, row);
        menu();
        ch = menuSelection();
    }
    outfile(file, column, row);
    
    return 0;
}



void infile(const char file[], Assignment column[], int& row){
    Assignment    task;
    char    courseName[MAX];
    char    assignmentDescription[MAX];
    char    dueDate[MAX];
    
    ifstream    in;
    in.open (file);
    
    if(!in){
        in.clear();
        cerr<< '\n' << "Error: File not found.\n\n" << endl;
        //exit(1);
    }
    
    
    in.get(courseName, MAX, ';');
    while (!in.eof())
    {
        in.get();
        
        in.get(assignmentDescription, MAX, ';');
        in.get(dueDate, MAX, '\n');
        
        strcpy(task.assignmentDescription, assignmentDescription);
        strcpy(task.courseName,courseName);
        strcpy(task.dueDate, dueDate);
        
        in.get(courseName, MAX,':');
    }
    in.close();
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



void print(const Assignment column[], int& row, char ch){
    //cout << "This is: print" << endl;
    
    int index;
    
    for (index = 0; index < row; index++){
        cout << index + 1 << ": " << column[index].courseName << ' ' << column[index].assignmentDescription << ' ' << column[index].dueDate << endl;
    }
    cout << "\n" << endl;
}



void add(Assignment& newAssignment){
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
    
    strcpy(newAssignment.courseName, courseName);
    strcpy(newAssignment.assignmentDescription, assignmentDescription);
    strcpy(newAssignment.dueDate, dueDate);
    
    cout << courseName<< " " << assignmentDescription << " " << dueDate << "\n" << endl;
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
void userInputDate(char cstring[]){
    char d;
    char m;
    char y;
    cin >> d; // read the day
    if (cin.get() != '/' ){ // make sure there is a slash between DD and MM
        
        cout << "expected /\n";
        return;
    }
    cin >> m; // read the month
    if (cin.get() != '/' ){ // make sure there is a slash between MM and YYYY
        
        cout << "expected /\n";
    }
    cin >> y; // read the year
    cout << "input date: " << d << "/" << m << "/" << y << "\n";
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





void outfile(char file[], const Assignment column[], int&row)
{
    ofstream         rightout;// ouputs data
    int              i;       // incrament counter
    rightout.open    (file);  //
    
    
    for (i = 0; i < row; i++)
    {
        rightout << column[i].courseName << ';'
        << column[i].assignmentDescription << ';'
        << column[i].dueDate << '\n' << endl;
    }
    cout << "peace out"<< endl;
    rightout.close();
    
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
