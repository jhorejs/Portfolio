#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int ReadArrays(string names[], int totals[]);
//The ReadArrays function receives the names and totals from the file student.txt. It does not return anything to main.

int PrintArrays(string names[], int totals[], int count);
//The PrintArrays function receives the names, totals and student count from the file students.txt. It returns the student count.


int main()
{
    string names[50];
    int totals[50], count;
    count = ReadArrays(names,totals);
    //SortArrays(names,totals,count);
    PrintArrays(names,totals,count);

    return 0;
}

int ReadArrays(string names[], int totals[])
{
    ifstream StudentFile;
    StudentFile.open("Desktop://students.txt");
    
    int test1, test2, test3, max=100, i=0;
    
    for (int i = 0; i < max; i++)
    {
        StudentFile >> test1;
        StudentFile >> test2;
        StudentFile >> test3;
        
        totals[i] = test1 + test2 + test3;
        
        StudentFile.ignore(10,'\n');
    }
    
    return i;
}

int PrintArrays(string names[], int totals[], int count)
//The PrintArrays function receives the names, totals and student count from the file students.txt. It returns the student count.
{
    cout << "Count " << count << endl;
    
    for(int i = 0; (i < count); i++)
    {
        cout << "Student " << names[i] << " Total " << totals[i] << endl;
    }
    
    return count;
}
