//This is the driver file for sample project 3

#include "tools.h"
#include <stdlib.h>
#define CRTDBG_MAP_ALLOC

//main
int main()
{
	//memory leak detection tool
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//create the list object
	VideoList store("movies.txt");
	char option;
	//display the menu
	do
	{
		displayMenu();
		option = readOption();
		exeCmd(option, store);
	} while (tolower(option) != 'q');

	return 0;
}