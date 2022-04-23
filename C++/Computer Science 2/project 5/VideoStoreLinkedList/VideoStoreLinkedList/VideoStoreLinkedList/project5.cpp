//Project 4 Main function

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

//main
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