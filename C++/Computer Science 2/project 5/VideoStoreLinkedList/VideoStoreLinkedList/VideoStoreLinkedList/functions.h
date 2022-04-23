#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "TaskList.h"

//function prototypes
void menuDisplay();
char menuSelection();
void menuSwitch(char ch, TaskList &column);
void add(Task &aTask);
void allCaps(char xStr[]);

#endif