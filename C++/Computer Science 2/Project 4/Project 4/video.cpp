//This is the implememtation file for video.h
#include "video.h"
#include <cstring>

//Class data type for the Video object
/*
class Video
{
private:
	char title[MAXCHAR];
	int qty;
	char genre[MAXCHAR];
public:
	//constructors
	Video();
	Video(char initTitle[], int initQty, char initGenre[]);
	//accessor and mutator functions
	const void getTitle(char returnTitle[]);
	const int getQty();
	const void getGenre(char returnGenre[]);
	void setTitle(char newTitle[]);
	void setQty(int newQty);
	void setGenre(char newGenre[]);
	//print function
	const void printVideo();
};
*/
//constructors
//default constructor
Video::Video()
{
	//allocate memory
	title = new char[MAXCHAR];
	strcpy(title, "No Title");
	qty = 0;
	genre = new char[MAXCHAR];
	strcpy(genre, "No Genre");
}

//constructor with parameters
Video::Video(char newTitle[], int newQty, char newGenre[])
{
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
	qty = newQty;
	genre = new char[strlen(newGenre) + 1];
	strcpy(genre, newGenre);
}
//Copy Constructor
Video::Video(const Video &aVideo)
{
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	title = new char[strlen(aVideo.title) + 1];
	strcpy(title, aVideo.title);
	this->setQty(aVideo.qty);
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
	genre = new char[strlen(aVideo.genre) + 1];
	this->setGenre(aVideo.genre);
}
//destructor
Video::~Video()
{
	//deallocate mem for title and genre
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
}

//accessor and mutator functions
//accessor functions
const void Video::getTitle(char returnTitle[])
{
	strcpy(returnTitle, title);
}
const int Video::getQty()
{
	return qty;
}
const void Video::getGenre(char returnGenre[])
{
	strcpy(returnGenre, genre);
}
//mutator functions
void Video::setTitle(char newTitle[])
{
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
}
void Video::setQty(int newQty)
{
	qty = newQty;
}
void Video::setGenre(char newGenre[])
{
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
	genre = new char[strlen(newGenre) + 1];
	strcpy(genre, newGenre);
}

//print function to screen
const void Video::printVideo()
{
	cout << title << ';' << qty << ';' << genre << endl;
}

//print function to file
const void Video::printFile(ofstream &outFile)
{
	outFile << title << ';' << qty << ';' << genre << endl;
}