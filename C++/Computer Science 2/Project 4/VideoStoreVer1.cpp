//This program keeps track of Videos in a VideoStore.  It is very similar to Project 3.
//We will use struct to model the Video object and class to model the VideoList object
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#define CRTDBG_MAP_ALLOC

using namespace std;

//constants
const int CAP = 5;
const int MAXCHAR = 101;
const int GROWTH = 3;
//struct data type for the Video object
struct Video
{
	char *title;
	int qty;
	char *genre;
};

//class data type for the VideoList object
class VideoList
{
private:
	Video *list;
	int size;
	int capacity;
	//function to expand array
	void expandArray();
public:
	//constructor
	VideoList();
	VideoList(char fileName[]);
	//destructor
	~VideoList();
	//other list functions
	void addVideo(Video &aVideo);
	const void displayList();
	const void findVideo();
	void writeFile();

};

//function prototypes
int readInt(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, VideoList &store);
void addVideo(Video &aVideo);
void convertCase(char tempStr[]);

//Function implementations


//displays the menu
void displayMenu()
{
	cout << "Welcome to the VideoStore:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "[A-a]: Add a movie" << endl;
	cout << "[D-d]: Display the List" << endl;
	cout << "[F-f]: Find a movie" << endl;
	cout << "[Q-q]: Quit" << endl;
}

//read the option from the user
char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, VideoList &store)
{
	Video aVideo;
	switch (tolower(option))
	{
	case 'a':
		addVideo(aVideo);
		store.addVideo(aVideo);
		break;
	case 'd':
		store.displayList();
		break;
	case 'f':
		store.findVideo();
		break;
	case 'q':
		store.writeFile();
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt(char prompt[])
{
	int temp = 0;
	cout << prompt;
	cin >> temp;
	//data validation
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}

//standalone overloaded addVideo function
//populate aVideo from the user
void addVideo(Video &aVideo)
{
	aVideo.title = new char[MAXCHAR];
	aVideo.genre = new char[MAXCHAR];
	cout << "Enter a movie name:";
	cin.get(aVideo.title, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	aVideo.qty = readInt("Enter quantity:");
	cout << "Enter movie genre:";
	cin.get(aVideo.genre, MAXCHAR, '\n');
	cin.ignore(100, '\n');
}

//converts all text to upper case
void convertCase(char tempStr[])
{
	//for(int i = 0; tempStr[i] != '\0'; i++)

	for (int i = 0; i < strlen(tempStr); i++)
	{
		tempStr[i] = toupper(tempStr[i]);
	}
}

//VideoList implementation functions
//default constructor
VideoList::VideoList()
{
	capacity = CAP;
	list = new Video[capacity];
	size = 0;
}
//constructor from file
VideoList::VideoList(char fileName[])
{
	ifstream inFile;
	Video aVideo;
	inFile.open(fileName);
	if (!inFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	capacity = CAP;
	list = new Video[capacity];
	size = 0;
	aVideo.title = new char[MAXCHAR];
	inFile.get(aVideo.title, MAXCHAR, ';');
	while (!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> aVideo.qty;
		inFile.ignore(5, ';');
		aVideo.genre = new char[MAXCHAR];
		inFile.get(aVideo.genre, MAXCHAR, '\n');
		inFile.ignore(5, '\n');
		addVideo(aVideo);
		if (aVideo.title) {
		
			delete[] aVideo.title;
			aVideo.title = NULL;
		}
		if (aVideo.genre) {

			delete[] aVideo.genre;
			aVideo.genre = NULL;
		}
		aVideo.title = new char[MAXCHAR];
		inFile.get(aVideo.title, MAXCHAR, ';');
	}
	if (aVideo.title) {

		delete[] aVideo.title;
		aVideo.title = NULL;
	}
	if (aVideo.genre) {

		delete[] aVideo.genre;
		aVideo.genre = NULL;
	}
	inFile.close();
}

//destructor
VideoList::~VideoList()
{
	if (list)
	{
		for (int i = 0; i < size; i++)
		{
			if (list[i].title)
			{
				delete [] list[i].title;
				list[i].title = NULL;
			}
			if (list[i].genre)
			{
				delete[] list[i].genre;
				list[i].genre = NULL;
			}
		}
		delete[]list;
		list = NULL;
	}
}
//adds a video to the list
void VideoList::addVideo(Video &aVideo)
{
	if (size == capacity)
	{
		expandArray();
	}
	list[size].title = new char[strlen(aVideo.title) + 1];
	strcpy_s(list[size].title, strlen(aVideo.title) + 1, aVideo.title);
	list[size].qty = aVideo.qty;
	list[size].genre = new char[strlen(aVideo.genre) + 1];
	strcpy_s(list[size].genre, strlen(aVideo.genre) + 1, aVideo.genre);
	size++;
	if (aVideo.title) {

		delete[] aVideo.title;
		aVideo.title = NULL;
	}
	if (aVideo.genre) {

		delete[] aVideo.genre;
		aVideo.genre = NULL;
	}
}

//prints the list
const void VideoList::displayList()
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ": " << list[i].title << ';' << list[i].qty << ';' << list[i].genre << '\n';
	}
	cout << endl;
}

//finds a movie in the list
const void VideoList::findVideo()
{
	char srchTitle[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (int i = 0; i < size; i++)
	{
		convertCase(list[i].title);
		if (strstr(list[i].title, srchTitle))
		{
			cout << list[i].title << ';' << list[i].qty << ';' << list[i].genre << '\n';
		}
	}
	cout << endl;
}

//writes the data back to the file
void VideoList::writeFile()
{
	ofstream outFile;
	outFile.open("movies.txt");
	if (!outFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	for (int i = 0; i < size; i++)
	{
		outFile << list[i].title << ';' << list[i].qty << ';' << list[i].genre << '\n';
	}
	outFile.close();
}

//function to expand array
void VideoList::expandArray()
{
	capacity += GROWTH;
	Video *tempList = new Video[capacity];
	for (int i = 0; i < size; i++)
	{
		tempList[i].title = new char[MAXCHAR];
		strcpy_s(tempList[i].title, MAXCHAR, list[i].title);
		tempList[i].qty = list[i].qty;
		tempList[i].genre = new char[MAXCHAR];
		strcpy_s(tempList[i].genre, MAXCHAR, list[i].genre);
	}
	if (list)
	{
		for (int i = 0; i < size; i++)
		{
			if (list[i].title)
			{
				delete[] list[i].title;
				list[i].title = NULL;
			}
			if (list[i].genre)
			{
				delete[] list[i].genre;
				list[i].genre = NULL;
			}
		}
	}
	delete[] list;
	list = tempList;
	tempList = NULL;
}

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
