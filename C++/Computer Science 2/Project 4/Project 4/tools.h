#ifndef TOOLS_H
#define TOOLS_H

#include "videolist.h"

//function prototypes
int readInt(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, VideoList &store);
void addVideo(Video &aVideo);
void convertCase(char tempStr[]);

#endif