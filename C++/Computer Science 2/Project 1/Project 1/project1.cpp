#include <iostream>
#include <cstring>

using namespace std;


void showChoices ();
const int MAX = 100;
void item_name(char str[]);
void error();

int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    char item[MAX];
    float price;
    float total=0;
    char  menu;
    
    do
    {
        showChoices();
        cin >> menu;
        cout<< endl;
        
        
        switch (menu)
        {
            case 'a':
                do
                {
                    cout << "Enter item: ";
                    item_name(item);
                    cout << item << ": $";
                    cin >> price;
                    total += price;
                    cout << item << " is: $" << price << endl;
                    cout << "\nAdd or quit? (a/q): " << endl;
                    cin>> menu;
                } while (menu !='q');
                
            case 't':
                cout << "Total: " << total;
                cout << endl;
                
                break;
                
                
            case 'q':
                cout << "Grand Total: " << total++ << endl;
                cout << "enter 'q' to quit: " << endl;
                break;
                
            default:
                cout << "Invalid input." << endl;
                
        }
    }
    while (menu != 'q');
    return 0;
}

void showChoices()
{
    cout << "Add or quite?(a/q):"<< endl;
}

void item_name(char str[]) //
{
    cin.get(str, MAX, '\n');
    while (!cin)
    {
        cin.clear();
        cin.ignore(MAX, '\n');
        cin.get(str, MAX, '\n');
    }
    cin.ignore(MAX, '\n');
}
